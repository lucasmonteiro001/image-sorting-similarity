#include <stdio.h>
#include <stdlib.h>
#include "io.h"

FILE *AbreArquivo(char *nome_arquivo, char *modo_leitura) {
    FILE *arquivo;

    if(!(arquivo = fopen(nome_arquivo, modo_leitura))) {
        printf("\nErro ao abrir o arquivo\n");
        exit(0);
    }
    else printf("\nArquivo aberto com sucesso!\n\n");

    return arquivo;
}

void MostrarParametrosPassados(int argc, char *argv[]) {

    int count;

    printf ("\nO programa foi chamado pelo caminho: \"%s\".\n\n", argv[0]);

    if (argc > 1)
        for (count = 1; count < argc; count++)
            printf("argv[%d] = %s\n", count, argv[count]);
    else
        printf("O comando não possui argumentos.\n");
    printf("\n");
}

void FechaArquivo(FILE *arquivo) {

    if(!fclose(arquivo))// Se fechou arq1
            printf("\nArquivos fechado com sucesso!!!\n");
}
