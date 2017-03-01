#ifndef ORDENACAO_H_INCLUDED
#define ORDENACAO_H_INCLUDED
#include "image.h"



void AlgoritmoSelecaoTipoDistanciaEntreParImagens(TipoDistanciaEntreParImagens *A, BancoImagens b);

void OrdenaTipoDistanciaEntreParImagens(int Esq, int Dir, TipoDistanciaEntreParImagens *A);

void ParticaoTipoDistanciaEntreParImagens(int Esq, int Dir, int *i, int *j, TipoDistanciaEntreParImagens *A);

void AlgoritmoQuickSortTipoDistanciaEntreParImagens(TipoDistanciaEntreParImagens *A, BancoImagens b);


void TrocaVetorDistancias(TipoDistancia *A, int i, int p);

void SelecionaVetorDistancias(TipoDistancia *A, int e, int d, int k);

int ParticionaVetorDistancias(TipoDistancia *A, int e, int d);

void AlgoritmoQuickSortSelectSortVetorDistancias(TipoImagem **A, BancoImagens b);


#endif // ORDENACAO_H_INCLUDED
