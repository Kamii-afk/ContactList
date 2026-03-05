#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>

#define TAM_LIST 100

#include "function.h"

typedef struct contact contact;

int main () {
    SetConsoleOutputCP(CP_UTF8);
    int option;
    int cont = 0;
    char resp;

    contact list[TAM_LIST] = {0};

    printf("======= Lista de Contatos =======\nPara continuar pressione Enter...\n");
    getchar();

    do {
        printf("Insira um opcao no menu a seguir:\n");
        printf("01 - Novo Cadastro\n02 - Listar contatos\n03 - Buscar nomes\n04 - Editar\n05- Excluir\n06 - Estatísticas\n07 - Sair\n");
        option = getch();

        switch(option) {
            case '1':
            do {
                system("cls");
                printf("Novo cadastro\n");
                cadastrarContato(&list[cont]);
                cont++;
                printf("Deseja Inserir mais algum? (S/N)\n");
                scanf("%c", &resp);
                getchar();
            
            } while (resp == 'S' || resp == 's');
            break;

            case '2':
            printf("Listar contatos\n");
            listarContato(list);
            break;
            
            case '3':
            printf("Buscar Nomes\n");
            buscarContato(list);

            break;

            case '4':
            printf("Editar\n");
            editarContato2(list);
            break;

            case '5':
            printf("Excluir\n");
            break;

            case '6':
            printf("Estatísticas\n");
            break;

            case '7':
            return 0;

            default:
            errorRep(2);
            break;
        }

    } while (option != 7);

    return 0;
}