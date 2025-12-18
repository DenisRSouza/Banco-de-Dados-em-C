#include "database.h"

int main(){
    FILE *file = abrir_arquivo("database.bin");
    int opcao;
    do {printf("Voce deseja:\n1. Ler o arquivo\n2. Adicionar pessoas\n3. Alterar nome\n4. Ordenar por idade\n5. Ordenar por nome\n6. Terminar a operacao: ");
    scanf("%d", &opcao);

    pessoa *pessoas;
    int n = ler_pessoas(file, &pessoas);

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
        case 4:
            insertion_sort(pessoas, n, compara_idade);
            imprime_arranjo(pessoas, n);
            free(pessoas);
            break;
        case 5:
            insertion_sort(pessoas, n, compara_nome);
            imprime_arranjo(pessoas, n);
            free(pessoas);
            break;
    }
    } while(opcao != 6);
    printf("Adeus!");

    fclose(file);
   return 0;
}