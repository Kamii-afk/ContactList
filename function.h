#ifndef FUNCTION_H
#define FUNCTION_H

#define TAM_NAME 100
#define TAM_NUMBER 20
#define TAM_EMAIL 100

struct contact {
    char name[TAM_NAME];
    char number[TAM_NUMBER];
    char email[TAM_EMAIL];
    int used;
};

void errorRep (int errorNum);

void cadastrarContato (struct contact *p);
void buscarContato (struct contact *p);
void listarContato (struct contact *p);
void editarContato (struct contact *p);

#endif