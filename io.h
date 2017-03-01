#ifndef IO_H_
#define IO_H_

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void AbreArquivosEntradaSaida(char *paramEntrada, char *paramSaida)
Função: Abre os arquivos de entrada e saida para leitura e escrita, respectivamente
Entrada: Nome do arquivo de entrada e nome do arquivo de saída
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
FILE *AbreArquivo(char *nome_arquivo, char *modo_leitura);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void MostrarParametrosPassados(int argc, char *argv[])
Função: Mostra tudo o que foi passado na linha de comando. É uma função de auxílio para tratamento da linha de comando
Entrada: Número de argumentos passados na linha de comando e arquivos e flags passados pela linha de comando também
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void MostrarParametrosPassados(int argc, char *argv[]);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: FILE* FechaArquivos(char *arq1, char *arq2)
Função: Fecha os arquivos aberto
Entrada: Nome dos arquivo
Saída: nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void FechaArquivo(FILE *arquivo);

#endif /* IO_H_ */
