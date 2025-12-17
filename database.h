
#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    int age;
} pessoa;

FILE *abrir_arquivo(const char *fname);
void adicionar_pessoa(FILE *fname);
void listar_pessoas(FILE *fname);
int buscar_pessoa(FILE *fname, const char *nome);
bool alterar_nome(FILE *fname);







#endif