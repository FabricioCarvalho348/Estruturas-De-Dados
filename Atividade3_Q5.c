/*
5) Faça um programa que leia uma sequência de caracteres a exiba criptograficamente segundo as
seguintes regras:
→ Toda não consoante é exibida diretamente
→ Toda sequência de consoantes é exibida na ordem inversa obtida

*/

#include <stdio.h>
#include <string.h>

int eConsoante(char c) {
    char vogais[] = {'a', 'e', 'i', 'o', 'u'};
    int i;
    for (i = 0; i < 5; i++) {
        if (c == vogais[i] || c == vogais[i] - 32) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char SequenciaDeLetras[1000], Consoantes[1000], NaoEConsoante[1000];
    int i, j = 0, k = 0;
    
    printf("Digite a sequencia de caracteres: ");
    fgets(SequenciaDeLetras, sizeof(SequenciaDeLetras), stdin);
    
    for (i = 0; i < strlen(SequenciaDeLetras); i++) {
        if (eConsoante(SequenciaDeLetras[i])) {
            Consoantes[j++] = SequenciaDeLetras[i];
        }
        else {
            NaoEConsoante[k++] = SequenciaDeLetras[i];
        }
    }
    Consoantes[j] = '\0';
    NaoEConsoante[k] = '\0';
    
    printf("Vogais: %s \nConsoantes: %s", NaoEConsoante, strrev(Consoantes));
    
    return 0;
}
