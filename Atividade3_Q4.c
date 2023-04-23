/*
4) Implemente uma calculadora pós-fixada, contendo as operações básicas (+, -, *, /). Dica: notação
pós-fixada é aquela que se digita primeiro os numerosero depois os operandos (1 2 - 4 5 + * = -9).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    double valor;
    struct No *prox;
} No;

typedef struct {
    No *top;
} Pilha;

void push(Pilha *s, double valor) {
    No *NovoNo = malloc(sizeof(No));
    NovoNo->valor = valor;
    NovoNo->prox = s->top;
    s->top = NovoNo;
}

double pop(Pilha *s) {
    if (s->top == NULL) {
        printf("Pilha vazia\n");
        exit(1);
    }
    double valor = s->top->valor;
    No *old_top = s->top;
    s->top = s->top->prox;
    free(old_top);
    return valor;
}

int main() {
    Pilha Pilha = { .top = NULL };
    char inserirCalculo[100];
    printf("Digite a expressao pos-fixada:\n");
    fgets(inserirCalculo, 100, stdin);
    int i = 0;
    while (inserirCalculo[i] != '\0') {
        if (inserirCalculo[i] >= '0' && inserirCalculo[i] <= '9') {
            double numeros = 0;
            while (inserirCalculo[i] >= '0' && inserirCalculo[i] <= '9') {
                numeros = numeros * 10 + (inserirCalculo[i] - '0');
                i++;
            }
            push(&Pilha, numeros);
        } else if (inserirCalculo[i] == '+' || inserirCalculo[i] == '-' || inserirCalculo[i] == '*' || inserirCalculo[i] == '/') {
            double op2 = pop(&Pilha);
            double op1 = pop(&Pilha);
            double resultadoCalculo;
            switch (inserirCalculo[i]) {
                case '+':
                    resultadoCalculo = op1 + op2;
                    break;
                case '-':
                    resultadoCalculo = op1 - op2;
                    break;
                case '*':
                    resultadoCalculo = op1 * op2;
                    break;
                case '/':
                    resultadoCalculo = op1 / op2;
                    break;
            }
            push(&Pilha, resultadoCalculo);
            i++;
        } else {
            i++;
        }
    }
    double resultadoCalculo = pop(&Pilha);
    if (Pilha.top != NULL) {
        printf("Expressão inválida\n");
        exit(1);
    }
    printf("resultado Calculado = %1.f\n", resultadoCalculo);
    return 0;
}
