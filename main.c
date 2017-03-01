#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "image.h"
#include "ordenacao.h"

int main(int argc, char *argv[]) {
    // Abre os arquivos para leitura e escrita, respectivamente
    FILE *arqEntrada    = AbreArquivo(argv[1], "r");
    FILE *arqSaida      = AbreArquivo(argv[2], "w");

    // Variável estruturada que conterá o N,K,P
    BancoImagens b;

    // Criação de um vetor contendo o número exato de imagens que tem no arquivo
    TipoImagem **vetorImagens = AlocaVetorImagens(arqEntrada, &b);

    // Percorre o arquivo e preenche a variável vetorImagens com todas as imagens passadas no arquivo
    PreencheVetorImagens(arqEntrada, vetorImagens, b);
//
//    // Para cada imagem, calcula a distância dela para todas as outras
    PreencheDistanciaImagemParaImagem(vetorImagens, b);
//
//    // Cria um vetor, de tamanho igual ao número de elementos da matriz triangular superior de Qut_imagens x Qut_imagens e preenche com todas as distâncias entre imagens
    TipoDistanciaEntreParImagens *vetorDistancias = CriaVetorComTodasDistancias(vetorImagens, b);
//
    // Se o valor de BancoImagens.Algoritmo = 1, o algoritmo de ordenação será o SelectSort O(n²)
    // Se o valor de BancoImagens.Algortimo = 2, o algoritmo de ordenação será o QuickSort O(nlogn)
    if(b.Algoritmo == 2)
        // Uso do algoritmo QuickSort para ordenar a distância entre um par de imagens
        AlgoritmoQuickSortTipoDistanciaEntreParImagens(vetorDistancias, b);
    else if(b.Algoritmo == 1)
        // Uso do algoritmo de Selecao para ordenar a distância entre um par de imagens
        AlgoritmoSelecaoTipoDistanciaEntreParImagens(vetorDistancias, b);
//
      // Uso do algoritmo QuickSort + SelectionSort para ordenação dos k-ésimos elementos da distância entre cada imagem e as outras
    AlgoritmoQuickSortSelectSortVetorDistancias(vetorImagens, b);
//
    ImprimeDistanciaImagemParaImagem(vetorImagens, b, arqSaida);
//
    ImprimeVetorComTodasDistancias(vetorDistancias, b, arqSaida);
//
//
    FechaArquivo(arqEntrada);
    FechaArquivo(arqSaida);
    return 0;
}
