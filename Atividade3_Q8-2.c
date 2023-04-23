/*
8.2. Implemente a fila de prioridade utilizando lista não-ordenada:
a) Adicionar um elemento na fila;
b) Remover um elemento da fila;
c) Imprimir os elementos da fila;
*/

#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura dos nós da lista
struct no {
    int valor;
    struct no* prox;
    struct no* ant;
};

// Definindo a estrutura da fila de prioridades
struct fila_prioridades {
    struct no* inicio;
    struct no* fim;
};

// Inicializando a fila de prioridades
void inicializar_fila(struct fila_prioridades* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

// Adicionando um elemento na fila de prioridades
void adicionar_elemento(struct fila_prioridades* fila, int valor) {
    struct no* novo_no = (struct no*) malloc(sizeof(struct no));
    novo_no->valor = valor;
    novo_no->prox = NULL;
    novo_no->ant = fila->fim;
    if (fila->inicio == NULL) {
        fila->inicio = novo_no;
    } else {
        fila->fim->prox = novo_no;
    }
    fila->fim = novo_no;
    // Ordenando a lista em ordem decrescente de valor
    struct no* atual = novo_no;
    while (atual->ant != NULL && atual->valor > atual->ant->valor) {
        // Trocando o valor do novo nó com o valor do nó anterior
        int temp = atual->valor;
        atual->valor = atual->ant->valor;
        atual->ant->valor = temp;
        atual = atual->ant;
    }
}

// Removendo o elemento de maior prioridade da fila de prioridades
void remover_elemento(struct fila_prioridades* fila) {
    if (fila->inicio == NULL) {
        printf("Fila vazia\n");
        return;
    }
    struct no* no_removido = fila->inicio;
    fila->inicio = no_removido->prox;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    } else {
        fila->inicio->ant = NULL;
    }
    free(no_removido);
}

// Imprimindo os elementos da fila de prioridades em ordem de prioridade
void imprimir_fila(struct fila_prioridades* fila) {
    struct no* atual = fila->inicio;
    printf("Fila: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    struct fila_prioridades fila;
    inicializar_fila(&fila);
    adicionar_elemento(&fila, 5);
    adicionar_elemento(&fila, 15);
    adicionar_elemento(&fila, 7);
    adicionar_elemento(&fila, 2);
    adicionar_elemento(&fila, 10);
    imprimir_fila(&fila);
    remover_elemento(&fila);
    remover_elemento(&fila);
    imprimir_fila(&fila);
    return 0;
}


