/*
6) Utilizando somente operações de empilhar e desempilhar, escreva um programa que remove um
item com chave c fornecida pelo usuário da pilha. Ao final da execução da função, a pilha deve ser
igual à original, exceto pela ausência do item removido.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    int dados;
    struct No *prox;
} No;

typedef struct {
    No *topo;
} pilha;

void criarPilha(pilha *pilha) {
    pilha->topo = NULL;
}

void push(pilha *pilha, int chave, int dados) {
    No *novoNo = malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->dados = dados;
    novoNo->prox = pilha->topo;
    pilha->topo = novoNo;
}

int auxPilha(pilha *pilha) {
    if (pilha->topo == NULL) {
        printf("Erro: pilha vazia\n");
        exit(EXIT_FAILURE);
    }
    No * ant = pilha->topo;
    int dados =  ant->dados;
    pilha->topo =  ant->prox;
    free(ant);
    return dados;
}

void removerPorChave(pilha *pilha, int chave) {
    if (pilha->topo == NULL) {
        printf("Erro: pilha vazia\n");
        exit(EXIT_FAILURE);
    }
    No *NoAtual = pilha->topo;
    No *antNo = NULL;
    while (NoAtual != NULL) {
        if (NoAtual->chave == chave) {
            if (antNo == NULL) {
                pilha->topo = NoAtual->prox;
            } else {
                antNo->prox = NoAtual->prox;
            }
            free(NoAtual);
            return;
        }
        antNo = NoAtual;
        NoAtual = NoAtual->prox;
    }
    printf("Erro: chave nao encontrada\n");
    exit(EXIT_FAILURE);
}

void imprimir(pilha *pilha) {
    No *NoAtual = pilha->topo;
    while (NoAtual != NULL) {
        printf("%d: %d\n", NoAtual->chave, NoAtual->dados);
        NoAtual = NoAtual->prox;
    }
}

int main() {
    pilha pilha;
    criarPilha(&pilha);

    push(&pilha, 1, 10);
    push(&pilha, 2, 20);
    push(&pilha, 3, 30);
    push(&pilha, 4, 40);
    push(&pilha, 5, 50);

    printf("Pilha original:\n");
    imprimir(&pilha);

    int ChaveParaSerRemovida;
    printf("Digite a chave do elemento a ser removido: ");
    scanf("%d", &ChaveParaSerRemovida);

    removerPorChave(&pilha, ChaveParaSerRemovida);

    printf("Pilha apos remocao:\n");
    imprimir(&pilha);

    return 0;
}
