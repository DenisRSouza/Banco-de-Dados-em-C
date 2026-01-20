# Sistema de Cadastro de Pessoas em Arquivo Binário (C)

Este repositório contém um programa em C que implementa um sistema simples de cadastro de pessoas utilizando arquivos binários.
O sistema permite adicionar, listar, buscar, alterar e ordenar registros armazenados em disco.

O projeto tem como foco o estudo de:
- Manipulação de arquivos binários (FILE*)
- Estruturas em C (struct)
- Alocação dinâmica de memória
- Algoritmos de ordenação (Insertion Sort)
- Uso de ponteiros e funções como parâmetros

# Estrutura do projeto 

```kotlin
├── main.c          # Função principal e menu interativo
├── database.c      # Implementação das funções de manipulação do banco
├── database.h      # Declarações, structs e protótipos
├── database.bin    # Arquivo binário gerado em tempo de execução
└── README.md
```

# Estrutura de Dados

```c
typedef struct {
    char name[50];
    int age;
} pessoa;
```

# Menu do Programa

```markdown
1. Ler o arquivo
2. Adicionar pessoas
3. Alterar nome
4. Ordenar por idade
5. Ordenar por nome
6. Terminar a operação
```

# Compilação e Execução

Utilize o GCC para compilar:

```bash
gcc main.c database.c -o cadastro
```

Execute o programa:

```bash
./cadastro
```
