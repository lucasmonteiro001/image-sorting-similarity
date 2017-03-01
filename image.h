#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define COLUNAS 128

//int qut_imagens; // Quantidade de imagens que o arquivo possui
//

typedef struct BancoImagens{
    int N;         // N imagens
    int K;         // K candidatos mais similares de uma imagem
    int P;         // P pares de imagens mais similares
    int Algoritmo; // Tipo do algoritmo escolhido
} BancoImagens;

typedef struct TipoDistancia {
    char    img2[40];
    float  distancia;
} TipoDistancia;

typedef struct TipoImagem {
    char nomeImagem[40];
    float descritor[COLUNAS];
    TipoDistancia *distancia_entre_imagem;// Cada imagem terá a distância de N - 1 imagens
} TipoImagem;

typedef struct TipoDistanciaEntreParImagens {
    char img1[40];
    char img2[40];
    float distancia;
} TipoDistanciaEntreParImagens;


//
TipoImagem **AlocaVetorImagens(FILE *arqEntrada, BancoImagens *b);
//
void PreencheVetorImagens(FILE *arqEntrada, TipoImagem **imagem, BancoImagens b);
//
void ImprimeMatrizImagens(TipoImagem **imagem, BancoImagens b);
//
//// Retorna a distância entre duas imagens
float CalculaDistancia(float *v1, float *v2);
//
// Aloca TipoDistancia
TipoDistancia *AlocaTipoDistancia(BancoImagens *b);
//
// Calcula a distância entre cada imagem
void PreencheDistanciaImagemParaImagem(TipoImagem **imagem, BancoImagens b);
//
// Imprime a distancia entre as imagens
void ImprimeDistanciaImagemParaImagem(TipoImagem **imagem, BancoImagens b, FILE *arqSaida);
//
//Cria uma vetor com todas as imagens e suas respectivas distâncias
TipoDistanciaEntreParImagens *CriaVetorComTodasDistancias(TipoImagem **imagem, BancoImagens b);
//
// Imprime o vetor que contém todas as distâncias
void ImprimeVetorComTodasDistancias(TipoDistanciaEntreParImagens *vetor, BancoImagens b, FILE *arqSaida);



#endif // IMAGE_H_INCLUDED
