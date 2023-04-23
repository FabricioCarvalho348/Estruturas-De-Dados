/*8 Considere uma Fila de prioridades de elementos inteiros positivos onde o token de prioridade é o
próprio valor inteiro positivo e a regra de prioridade é quanto maior o token, maior a prioridade. Crie
os seguintes métodos:

8.1 Implemente a fila de prioridade utilizando lista ordenada:
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
};

// Definindo a estrutura da fila de prioridades
struct fila_prioridades {
    struct no* inicio;
};

// Inicializando a fila de prioridades
void inicializar_fila(struct fila_prioridades* fila) {
    fila->inicio = NULL;
}

// Adicionando um elemento na fila de prioridades
void adicionar_elemento(struct fila_prioridades* fila, int valor) {
    struct no* novo_no = (struct no*) malloc(sizeof(struct no));
    novo_no->valor = valor;

    // Se a fila estiver vazia, insere o novo nó no início
    if (fila->inicio == NULL) {
        novo_no->prox = NULL;
        fila->inicio = novo_no;
        return;
    }

    // Se o valor for maior que o primeiro elemento da fila, insere o novo nó no início
    if (valor > fila->inicio->valor) {
        novo_no->prox = fila->inicio;
        fila->inicio = novo_no;
        return;
    }

    // Percorre a fila até encontrar a posição correta para inserir o novo nó
    struct no* atual = fila->inicio;
    while (atual->prox != NULL && valor <= atual->prox->valor) {
        atual = atual->prox;
    }
    novo_no->prox = atual->prox;
    atual->prox = novo_no;
}

// Removendo um elemento da fila de prioridades
void remover_elemento(struct fila_prioridades* fila) {
    if (fila->inicio == NULL) {
        printf("Fila vazia\n");
        return;
    }
    struct no* no_removido = fila->inicio;
    fila->inicio = no_removido->prox;
    free(no_removido);
}

// Imprimindo os elementos da fila de prioridades
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
    adicionar_elemento(&fila, 10);
    adicionar_elemento(&fila, 7);
    adicionar_elemento(&fila, 2);
    adicionar_elemento(&fila, 15);
    imprimir_fila(&fila);
    remover_elemento(&fila);
    remover_elemento(&fila);
    imprimir_fila(&fila);
    return 0;
}
