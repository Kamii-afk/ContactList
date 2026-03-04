#include "function.h"
#include <stdio.h>

void errorRep (int errorNum) {
    switch (errorNum) {
        case 1: //Valor não encontrado
        printf("Erro, valor não encontrado, tente novamente\n");
        break;

        case 2:
        printf("Opção Inválida, tente novamente\n");
        break;

        case 3:
        printf("Índice vazio, tente outro\n");
        break;

        case 4:
        printf("Valor excedeu o limite de memória, tente um menor\n");
        break;
    }
}