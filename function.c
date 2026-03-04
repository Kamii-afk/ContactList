#include "function.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

void cadastrarContato (struct contact *p) {
    printf("Insira o Nome:\n");
    fgets(p->name, sizeof(p->name), stdin);
    p->name[strcspn(p->name, "\n")] = '\0';

    printf("Insira o Número:\n");
    fgets(p->number, sizeof(p->number), stdin);
    p->number[strcspn(p->number, "\n")] = '\0';

    printf("Insira o E-mail:\n");
    fgets(p->email, sizeof(p->email), stdin);
    p->email[strcspn(p->email, "\n")] = '\0';

    p->used = 1;

    printf("===== Valores inseridos =====\n");
    printf("Nome: %s\n", p->name);
    printf("Número: %s\n", p->number);
    printf("E-mail: %s\n", p->email);
    
}

void listarContato (struct contact *p) {
    int contador, livre;
    contador = 0;

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

            if(indice < 0 || indice > 100) {
                errorRep(4);
                break;
            } 

            if(p[indice - 1].used == 1) {
                printf("%s\n", p[indice - 1].name);
                printf("%s\n", p[indice - 1].number);
                printf("%s\n", p[indice - 1].email);
                system("pause");
            } else {
                errorRep(3);
                system("cls");
                break;
            }
            
            case '2':
            system("cls");
            printf("Consulta por nome\n");
            printf("Insira o nome a ser buscado:\n");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            for (int i = 0; i < 100; i++) {
                if (strcmp(p[i].name, name) == 0) {
                    printf("Nome encontrado!\n");
                    printf("%s\n", p[i].name);
                    printf("%s\n", p[i].number);
                    printf("%s\n", p[i].email);
                    system("pause");
                    break;
                }
            }
            break;

            case '3':
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
                    break;
                }
            }
            break;

            case '4':
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
                    break;
                }
            }
            break;

            case '5':
            break;

            default:
            errorRep(2);
            break;
        }
    } while (option != '5');
}

void editarContato (struct contact *p) {
    
}