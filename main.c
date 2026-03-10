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

    FILE *fp = fopen("contatos.bin", "ab+");
    
    if(!fp) {
        printf("Não foi possível abrir o arquivo!\n");
        return 1;
    }

    rewind(fp);
    
    int option;
    int cont = 0;
    int livre;
    char resp;
    
    contact list[TAM_LIST] = {0};

    lerRegistro(list, fp, &cont);
    
    printf("======= Lista de Contatos =======\nPara continuar pressione Enter...\n");
    getchar();

    do {
        printf("Insira um opcao no menu a seguir:\n");
        printf("01 - Novo Cadastro\n02 - Listar contatos\n03 - Buscar nomes\n04 - Editar\n05- Excluir\n06 - Estatísticas\n07 - Sair\n");
        option = getch();

        switch(option) {
            case '1':
            do {
                checkUse(list, &livre);
                system("cls");
                printf("Novo cadastro\n");
                cadastrarContato(&list[livre], fp);
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
            editarContato(list);
            break;

            case '5':
            checkUse(list, &livre);
            printf("Excluir\n");
            excluirContato(list, &livre, &cont);
            printf("%d", cont);
            system("pause");
            break;

            case '6':
            printf("Estatísticas\n");
            showDash(list, cont);
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