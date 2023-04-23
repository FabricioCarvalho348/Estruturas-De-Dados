/*
1.1 Considere uma Pilha de elementos inteiros positivos onde é aceito a inserção de elementos iguais.
Crie os seguintes funções:

a) Adicionar um elemento na pilha;
Função add do código.

b) Remover um elemento da pilha;
Função remover do código.

c) Imprimir os elementos da pilha;
Função imprimir do código

d) Retornar o tamanho da pilha;
variavél tam que conta quantos elementos tem na pilha, printf que printa o tamanho da pilha.

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no * prox;
}NO;

NO * inicio = NULL; //topo
int tam = 0;


void add(int valor){
    
        NO * novo = malloc(sizeof(NO));
        novo->valor = valor;
        novo->prox = NULL;

        if(inicio == NULL){//pilha esta vazia
            inicio = novo;
         
        }else {  //inicio - topo
                novo->prox = inicio;
                inicio = novo;
        }
        tam++;
    
}

void imprimir(){
    
     NO * aux = inicio;
                   
    for(int i = 0; i<tam; i++){
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
            printf("Pilha vazia! \n :(");
            return -1;
        }
    
    return 0;
}

int main(){
    add(18);
    add(19);
    add(17);
    add(28);
    add(39);
    add(45);
    imprimir();
    printf("tamanho da pilha: %d", tam);
    
    return 0;
}
