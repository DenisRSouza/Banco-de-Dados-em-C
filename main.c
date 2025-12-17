#include "database.h"

int main(){
    FILE *file = abrir_arquivo("database.bin");
    int opcao;
    do {printf("Voce deseja: 1. Ler o arquivo 2. Adicionar pessoas 3. Alterar nome 4. Terminar a operacao: ");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            listar_pessoas(file);
            break;
        case 2: 
            adicionar_pessoa(file);
            break;
        case 3:
            alterar_nome(file);
            break;
    }
    } while(opcao != 4);
    printf("Adeus!");

    fclose(file);
   return 0;
}