
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

//algoritmos de ordenacao
int ler_pessoas(FILE *fname, pessoa **arr);
int compara_idade(pessoa *p1, pessoa *p2);
int compara_nome(pessoa *p1, pessoa *p2);
void insertion_sort(pessoa *arr, int n, int (*cmp) (pessoa*, pessoa*));
void insercao(pessoa *arr, int n, pessoa valor, int (*cmp) (pessoa*, pessoa*));
void imprime_arranjo(pessoa *arr, int n);





#endif