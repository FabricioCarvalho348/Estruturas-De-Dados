/*
3) Uma empilhadeira carrega caixas de 7, 5, 3 toneladas. Há três pilhas A, B, C. A pilha A é onde se
encontram todas as caixas que chegam no depósito. Com um detalhe: caixas maiores não podem ser
empilhadas sobre caixas menores. Elabore um programa que efetue o controle das caixas, de forma
que caso uma caixa de maior peso do que uma que já está em A deva ser empilhada, então, todas as
caixas que estão em A são movidas para as pilhas auxiliares B (contendo somente caixa de 5
toneladas) e C (contendo somente caixas de 3 toneladas) até que se possa empilhar a nova caixa.
Depois, todas as caixas são movidas de volta para a pilha A.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {

    int peso;
    struct 
    No * embaixo;
}Pilhas;

//int sizeA = 0, sizeB = 0, sizeC = 0;

Pilhas * pilhaA = NULL;
Pilhas * pilhaB = NULL;
Pilhas * pilhaC = NULL;

void empilhadeira (int CaixasParaEmpilhar){//função para adicionar nova carga na pilha preferencialmente na pilha A

    if ((CaixasParaEmpilhar >= 3 || CaixasParaEmpilhar <= 7) && CaixasParaEmpilhar != 4){

        Pilhas * novoCaixasParaEmpilhar = malloc(sizeof(Pilhas));
        novoCaixasParaEmpilhar -> peso = CaixasParaEmpilhar;
        novoCaixasParaEmpilhar -> embaixo = NULL;

        if (pilhaA == NULL){//pilha A vazia, então pode adicionar sem problema com a carga
            pilhaA = novoCaixasParaEmpilhar;
        }else{//pilha A já existe

            if (CaixasParaEmpilhar == 7 && pilhaA -> peso == CaixasParaEmpilhar){
                novoCaixasParaEmpilhar -> embaixo = pilhaA;
                pilhaA = novoCaixasParaEmpilhar;
            }else if (CaixasParaEmpilhar == 7){

                while (pilhaA != NULL){

                    if (pilhaA -> peso == 5){

                        Pilhas * auxPilha = pilhaA;
                        pilhaA = pilhaA -> embaixo;
                        auxPilha -> embaixo = pilhaB;
                        pilhaB = auxPilha;
                    }else{

                        Pilhas * auxPilha = pilhaA;
                        pilhaA = pilhaA -> embaixo;
                        auxPilha -> embaixo = pilhaC;
                        pilhaC = auxPilha;
                    }

                    if (pilhaA != NULL){
                        if (pilhaA -> peso == 7){break;}
                    }
                }

                novoCaixasParaEmpilhar -> embaixo = pilhaA;
                pilhaA = novoCaixasParaEmpilhar;
            }else if (CaixasParaEmpilhar == 5){

                while (pilhaA != NULL){

                    if (pilhaA -> peso == 3){

                        Pilhas * auxPilha = pilhaA;
                        pilhaA = pilhaA -> embaixo;
                        auxPilha -> embaixo = pilhaC;
                        pilhaC = auxPilha;
                    }

                    if (pilhaA != NULL){
                        if ((pilhaA -> peso == 5 || pilhaA -> peso == 7)){break;}
                    }
                }

                novoCaixasParaEmpilhar -> embaixo = pilhaA;
                pilhaA = novoCaixasParaEmpilhar;
            }else{

                novoCaixasParaEmpilhar -> embaixo = pilhaA;
                pilhaA = novoCaixasParaEmpilhar;
            }
        }

        while (pilhaB != NULL){

            Pilhas * auxPercorrePilha = pilhaB;
            pilhaB = pilhaB -> embaixo;
            auxPercorrePilha -> embaixo = pilhaA;
            pilhaA = auxPercorrePilha;
        }

        while (pilhaC != NULL){

            Pilhas * auxPercorrePilha = pilhaC;
            pilhaC = pilhaC -> embaixo;
            auxPercorrePilha -> embaixo = pilhaA;
            pilhaA = auxPercorrePilha;
        }
    }else{ printf("Caixa inválida para ser adicionada na pilha.\n"); }
}

void imprimir(void){

    Pilhas * auxImprimirPilhaA = pilhaA;
    Pilhas * auxImprimirPilhaB = pilhaB;
    Pilhas * auxImprimirPilhaC = pilhaC;

    while (auxImprimirPilhaA != NULL){

        printf("Caixas: %d toneladas\n", auxImprimirPilhaA -> peso);
        auxImprimirPilhaA = auxImprimirPilhaA -> embaixo;
    }
    if (auxImprimirPilhaB == NULL && auxImprimirPilhaC == NULL){
        printf("Pilhas B e C estao vazias.\n");
    }else{ printf("Tem alguma caixa em B ou C.\n"); }
}

int main(void){

    empilhadeira(3);
    empilhadeira(7);
    empilhadeira(5);
        empilhadeira(5);
    empilhadeira(5);
    empilhadeira(5);
        empilhadeira(7);
    empilhadeira(7);
    empilhadeira(7);
        empilhadeira(3);
    empilhadeira(3);
    empilhadeira(3);
        empilhadeira(3);
    empilhadeira(7);
    empilhadeira(5);

    imprimir();

    return 0;
}