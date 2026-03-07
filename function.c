#include "function.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

void cadastrarContato (struct contact *p) {
    int check = 0;
    do {
    printf("Insira o Nome:\n");
    fgets(p->name, sizeof(p->name), stdin);
    p->name[strcspn(p->name, "\n")] = '\0';
    upperString(p->name, &check);
    } while (!check);

    check = 0;

    do {
    printf("Insira o Número:\n");
    fgets(p->number, sizeof(p->number), stdin);
    p->number[strcspn(p->number, "\n")] = '\0';
    validaNumero(p->number, &check);
    } while (!check);

    check = 0;

    do {
    printf("Insira o E-mail:\n");
    fgets(p->email, sizeof(p->email), stdin);
    p->email[strcspn(p->email, "\n")] = '\0';
    validaEmail(p->email, &check);
    } while (!check);

    check = 0;
    
    p->used = 1;

    printf("===== Valores inseridos =====\n");
    printf("Nome: %s\n", p->name);
    printf("Número: %s\n", p->number);
    printf("E-mail: %s\n", p->email);
    
}

void upperString (char *string, int *check) {
    int firstLetter = 1;

    if(string[0] == '\0') {
        errorRep(6);
        *check = 0;
        return;
    } else {
        *check = 1;
    }

    for(int i = 0; i < string[i] != '\0'; i++) {
        if(string[i] == ' ') {
            firstLetter = 1;
        } else if(firstLetter) {
            string[i] = toupper(string[i]);
            firstLetter = 0;
        } else {
            string[i] = tolower(string[i]);
        }
    }
}

void validaNumero (char *p, int *check) {
    if(p[0] == '\0') {
        errorRep(6);
        *check = 0;
        return;
    } else if(strlen(p) <= 8) {
        errorRep(7);
        *check = 0;
        return;
    } else {
        *check = 1;
        return;
    }
}

void validaEmail (char *p, int *check) {
    if(p[0] == '\0') {
        errorRep(6);
        *check = 0;
    } else {
        *check = 1;
    }
}

void listarContato (struct contact *p) {
    int contador, livre;
    contador = 0;

    system("cls");

    for (int i = 0; i < 100; i++) {
        if(p[i].used == 1) {
            printf("================= Contato Número %d =================\n", i + 1);
            printf("%s\n", p[i].name);
            printf("%s\n", p[i].number);
            printf("%s\n", p[i].email);

            contador++;
        } else {
            break;
        }
    }

    livre = 100 - contador;

    printf("Número de contatos Encontrados: %d\n", contador);
    printf("Número de contatos Livres: %d\n", livre);
    system("pause");
}

void buscarContato(struct contact *p) {
    int option, indice;
    char name[100], number[20], email[100];

    system("cls");
    
    do {
        printf("De que maneira deseja fazer a consulta?\n");
        printf("01 - Índide, 02 - Nome, 03 - Número, 04 - E-mail ou 05 - Retornar ao menu anterior\n");
        option = getch();
        switch (option) {
            case '1':
            system("cls");
            printf("Consulta por Índice\n");
            printf("Insira o número índice que deseja fazer a consulta:\n");
            scanf("%d", &indice);
            getchar();

            if(indice < 1 || indice > 100) {
                errorRep(4);
                break;
            } 

            if(p[indice - 1].used == 1) {
                printf("%s\n", p[indice - 1].name);
                printf("%s\n", p[indice - 1].number);
                printf("%s\n", p[indice - 1].email);
                system("pause");
                break;
            } else {
                errorRep(3);
                system("pause");
                system("cls");
                break;
            }
            
            case '2': {
            int found = 0;
            int check = 0;

            system("cls");
            printf("Consulta por nome\n");
            printf("Insira o nome a ser buscado:\n");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            upperString(name, &check);

            for (int i = 0; i < 100; i++) {
                if (strcmp(p[i].name, name) == 0) {
                    printf("Nome encontrado!\n");
                    printf("%s\n", p[i].name);
                    printf("%s\n", p[i].number);
                    printf("%s\n", p[i].email);
                    system("pause");
                    found = 1;
                    break;
                }
            }

            if (found != 1) {
                errorRep(3);
                break;
            }
            break;
        }

            case '3': {
            int found = 0;

            system("cls");
            printf("Consulta por Número\n");
            printf("Insira o número a ser consultado:\n");
            fgets(number, sizeof(number), stdin);
            number[strcspn(number, "\n")] = '\0';

            for(int i = 0; i < 100; i++) {
                if(strcmp(p[i].number, number) == 0) {
                    printf("Nome encontrado!\n");
                    printf("%s\n", p[i].name);
                    printf("%s\n", p[i].number);
                    printf("%s\n", p[i].email);
                    system("pause");
                    found = 1;
                    break;
                }
            }

            if(found != 1) {
                errorRep(3);
                break;
            }
            
            break;
        }

            case '4': {
            int found = 0;

            system("cls");
            printf("Consulta por E-mail\n");
            printf("Insira o E-mail a ser consultado:\n");
            fgets(email, sizeof(email), stdin);
            email[strcspn(email, "\n")] = '\0';

            for (int i= 0; i < 100; i++) {
                if(strcmp(p[i].email, email) == 0) {
                    printf("Nome encontrado!\n");
                    printf("%s\n", p[i].name);
                    printf("%s\n", p[i].number);
                    printf("%s\n", p[i].email);
                    system("pause");
                    found = 1;
                    break;
                }
            }

            if(found != 1) {
                errorRep(3);
                break;
            }

            break;
        }

            case '5':
            break;

            default:
            errorRep(2);
            break;
        }
    } while (option != '5');
}

int auxiliarEdit (struct contact *p) {
    char name [100];
    int ref, found, check;
    
    printf("Insira o nome do contato a ser buscado:\n");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    upperString(name, &check);
    
    for(int i = 0; i < 100; i++) {
        if(strcmp(name, p[i].name) == 0) {
            printf("Nome encontrado:\n");
            printf("Nome: %s\n", p[i].name);
            printf("Número: %s\n", p[i].number);
            printf("E-mail: %s\n", p[i].email);
            found = 1;
            ref = i;
            return ref;
        }
    }

    if(found != 1) {
        errorRep(1);
    } return -1;
    
}

void editarContato (struct contact *p) {
    int ref, option;

    ref = auxiliarEdit(p);

    if(ref == -1) {
        return;
    }

    
    do {
        printf("========== Escolha uma opção para editar: ==========\n");
        printf("1 => Nome\n2 => Número\n3 => E-mail\n4 => Sair\n");
        option = getch();
        switch (option) {
            case '1':
            printf("Insira o novo nome:\n");
            fgets(p[ref].name, sizeof(p[ref].name), stdin);
            p[ref].name[strcspn(p[ref].name, "\n")] = '\0';

            printf("Nome alterado!\n");
            printStruct(p, ref);

            break;

            case '2':
            printf("Insira o novo número:\n");
            fgets(p[ref].number, sizeof(p[ref].number), stdin);
            p[ref].number[strcspn(p[ref].number, "\n")] = '\0';

            printf("Número alterado!\n");
            printStruct(p, ref);
            break;

            case '3':
            printf("Insira o novo E-mail:\n");
            fgets(p[ref].email, sizeof(p[ref].email), stdin);
            p[ref].email[strcspn(p[ref].email, "\n")] = '\0';

            printf("E-mail alterado!\n");
            printStruct(p, ref);
            break;

            case '4':
            return;

            default:
            errorRep(2);
        }
    } while (option != '4');
}

void printStruct (struct contact *p, int i) {

    if(i < 0 || i > 100) {
        errorRep(1);
        return;
    }

    if(p[i].used != 1) {
        errorRep(3);
        return;
    }
    
    printf("Nome: %s\n", p[i].name);
    printf("Número: %s\n", p[i].number);
    printf("E-mail: %s\n", p[i].email);
}

void excluirContato (struct contact *p, int *c) {
    int ref;
    char confirm;
    struct contact *addres;

    ref = auxiliarEdit(p);

    if(ref == -1) {
        return;
    }

    addres = &p[ref];

    printf("Deseja realmente excluir o contato listado? S/N\n");
    confirm = getch();

    if(confirm == 's' || confirm == 'S') {
        memset(addres, 0, sizeof(struct contact));
        *c--;
    }else {
        printf("Exclusão Cancelada\n");
        system("pause");
    }

}

void showDash (struct contact *p, int cont) {
    printf("========== Estatísticas ==========\n");
    printf("Número de contatos salvos: %d", cont);
    printf("Número de espaços livres para contatos: %d", 100 - cont);

{
    int option;
    do {

        printf("Escolha uma das opções abaixo:\n");
        printf("1 - Listar contatos por inicial\n");
        printf("2 - Mostrar e-mail por filtro\n");
        printf("3 - Mostrar contatos com DDD específico\n");
        option = getch();

        char initial, dominio[20];
        char name[100];
        int *check;

        switch(option) {
            case '1':
            printf("Insira a inicial a ser encontrada:\n");
            initial = getchar();
            buscarInicial(initial, p);
            break;

            case '2':
            printf("Insira o domínio de e-mail a ser encontrado:\n");
            fgets(dominio, sizeof(dominio), stdin);
            dominio[strcspn(dominio, "\n")] = '\0';
            buscarDominio(p, dominio, check);
        }
        
    } while (option != 4);
}
}

void buscarInicial (char initial, struct contact *p) {
    int existe = 0;
    
    for(int i = 0; i < 100; i++) {
        if(p[i].used == 1 && p[i].name[0] == initial) {
            printStruct(p, i);
            existe = 1;
            system("pause");
        }
    }

    if(existe != 1) {
        errorRep(5);
    }
}