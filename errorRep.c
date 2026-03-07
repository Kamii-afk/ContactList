#include "function.h"
#include <stdio.h>
#include <windows.h>

void errorRep (int errorNum) {
    switch (errorNum) {
        case 1: //Valor não encontrado
        printf("Erro, valor não encontrado, tente novamente\n");
        system("pause");
        break;

        case 2:
        printf("Opção Inválida, tente novamente\n");
        system("pause");
        break;

        case 3:
        printf("Índice vazio, tente outro\n");
        system("pause");
        break;

        case 4:
        printf("Valor excedeu o limite de memória, tente um menor\n");
        system("pause");
        break;

        case 5:
        printf("Não existem valores correspondentes ao filtro\n");
        system("pause");
        break;

        case 6:
        printf("Valor não foi preenchido, tente novamente:\n");
        system("pause");
        break;

        case 7:
        printf("Valor muito pequeno, tente novamente\n");
        system("pause");
        break;

        case 8:
        printf("Valor não possui correspondência\n");
        system("pause");
        break;
    }
}