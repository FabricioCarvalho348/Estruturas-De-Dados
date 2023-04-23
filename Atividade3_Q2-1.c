/*
2.2 Considere uma Fila de elementos inteiros positivos onde é aceito a inserção de elementos iguais.
Crie os seguintes funções:

a) Adicionar um elemento na fila;
Função add no código.

b) Remover um elemento da fila;
Função remover no código.

c) Imprimir os elementos da fila;
Função imprimir no código. 

d) Retornar o tamanho da fila;
variável tam que percorre a fila e conta os elementos, printf no final depois do imprimir dentro do método main.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no * prox;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;


void add(int valor){

    NO * novo = malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;

    if(inicio == NULL){//fila esta vazia
        inicio = novo;
        fim = novo;

    }else {  //fim
        fim->prox = novo;
        fim = novo;
    }
    tam++;

}

void imprimir(){

    NO * aux = inicio;

    for(int i = 0; i < tam; i++){
        printf("valor: %d\n", aux->valor);
        aux = aux->prox;
    }


}

int remover(){

    if(tam > 0){ //inicio

        NO *lixo = inicio;
        int valor = inicio->valor;
        inicio = inicio->prox;
        free(lixo);
        tam--;
        return valor;
    }else{
        printf("Fila vazia! \n :(");
        return -1;
    }

    return 0;
}

int main(){
    add(60);
    add(22);
    add(16);
    add(29);
    add(12);
    add(48);
    imprimir();
    printf("Tamanho da fila: %d", tam);
    return 0;
}