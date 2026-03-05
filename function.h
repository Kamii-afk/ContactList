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
void upperString (char *string, int *check); //uppercase
void validaNumero (char *p, int *check); //Validação de Número
void validaEmail (char *p, int *check); //Velidação de e-mail 
void buscarContato (struct contact *p);
void listarContato (struct contact *p);
void editarContato (struct contact *p);
void printStruct (struct contact *p, int i);
int auxiliarEdit (struct contact *p); //Função de Busca de contatos
void excluirContato (struct contact *p);
void showDash (struct contact *p, int cont); //Função para exibição de estatísticas

//Funções auxiliares de ShowDash
void buscarInicial (char initial, struct contact *p);

#endif