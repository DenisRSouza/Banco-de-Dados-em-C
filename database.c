#include "database.h"

FILE *abrir_arquivo(const char *fname){
    FILE *file = fopen(fname, "r+b");
    if(file == NULL){
        file = fopen(fname, "w+b");
        if(file == NULL){
            printf("Erro ao abrir arquivo");
            exit(EXIT_FAILURE);
        }
    }
    return file;
}

void adicionar_pessoa(FILE *fname){
    
    pessoa buffer;
    char opcao;

    fseek(fname, 0, SEEK_END);
    do{
        printf("Digite o nome: ");
        scanf("%49s", buffer.name);
        getchar();

        printf("Digite a idade: ");
        scanf("%d", &buffer.age);
        getchar();

        fwrite(&buffer, sizeof(pessoa), 1, fname);
        printf("Deseja adicionar mais uma pessoa? (Y/n): ");
        scanf("%c", &opcao);

    } while(opcao != 'N' && opcao != 'n');
    fflush(fname);
    listar_pessoas(fname);
    

}

void listar_pessoas(FILE *fname){
    fseek(fname, 0, SEEK_SET);

    pessoa buffer;
    while(fread(&buffer, sizeof(pessoa), 1, fname) == 1){
        printf("Nome: %s, Idade: %d\n", buffer.name, buffer.age);
    }
}

int buscar_pessoa(FILE *fname, const char *nome){ //retorna o indice do nome da pessoa
    pessoa p;
    fseek(fname, 0, SEEK_SET);
    int idx = 0;
    while(fread(&p, sizeof(pessoa), 1, fname) == 1){
        if(strcmp(p.name, nome) == 0){
            return idx;
        }
        idx++;
    }

    return - 1;
}

bool alterar_nome(FILE *fname){
    char nome_antigo[50];
    printf("Digite o nome que deve ser alterado: ");
    scanf("%49s", &nome_antigo);

    char nome_novo[50];
    printf("Digite o novo nome: ");
    scanf("%49s", &nome_novo);
    int idx = buscar_pessoa(fname, nome_antigo);
    if(idx == - 1){
        return false;
    }

    pessoa p;
    fseek(fname, idx * sizeof(pessoa), SEEK_SET);
    fread(&p, sizeof(pessoa), 1, fname);
    strcpy(p.name, nome_novo);
    fseek(fname, idx * sizeof(pessoa), SEEK_SET);
    fwrite(&p, sizeof(pessoa), 1, fname);
    listar_pessoas(fname);
    return true;

}