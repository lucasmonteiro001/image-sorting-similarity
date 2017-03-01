#include "io.h"
#include "image.h"


// Lê o número de imagens que o arquivo terá
TipoImagem **AlocaVetorImagens(FILE *arqEntrada, BancoImagens *b) {

    TipoImagem **imagem;

    // Pega os valores do Número de imagens, k primeiras imagens mais próximas e os p pares mais próximos
    fscanf(arqEntrada, "%d", &b->N);
    fscanf(arqEntrada, "%d", &b->K);
    fscanf(arqEntrada, "%d", &b->P);
    fscanf(arqEntrada, "%d", &b->Algoritmo);



    imagem = (TipoImagem **)malloc(b->N * sizeof(TipoImagem*));

    int i = 0;

    // Aloca espaço para o vetor que conterá as imagens
    for(i = 0; i < b->N; i++) {
        imagem[i] = (TipoImagem *)malloc(sizeof(TipoImagem));
        imagem[i]->distancia_entre_imagem = AlocaTipoDistancia(b);
    }

    return imagem;
}
//
//// Lê o arquivo e preenche os dados na matriz
void PreencheVetorImagens(FILE *arqEntrada, TipoImagem **imagem, BancoImagens b){

    int i = 0;
    int j = 0;

    for(i = 0; i < b.N; i++) {
        for(j = 0; j <= COLUNAS; j++) {
            if(j == 0) {// Pega o nome da imagem
                fscanf(arqEntrada, "%s", imagem[i]->nomeImagem);
            }
            else { // Pega o valor de cada elemento do vetor descritor e atribui para  a imagem
                fscanf(arqEntrada, "%f", &imagem[i]->descritor[j - 1]);
            }

        }
    }
}
//
void ImprimeMatrizImagens(TipoImagem **imagem, BancoImagens b) {
    int i = 0, j = 0;
    printf("\n\n\n");
    for(i = 0; i < b.N; i++) {
        for(j = 0; j <= COLUNAS; j++) {
            if(j == 0) {
                printf("%s ", imagem[i]->nomeImagem);
            } else {
                printf("%f ", imagem[i]->descritor[j - 1]);
            }
        }
        printf("\n\n");
    }
}
//
float CalculaDistancia(float *v1, float *v2) {
    int i = 0;      // Auxiliar contador
    float soma = 0;//  Receberá a soma das distânciaa


    for(i = 0; i < COLUNAS; i++) {
        soma += pow(v1[i] - v2[i], 2); // Cálculo de v1[x] - v2[x] ao quadrado
    }

    float distancia = 0;
    distancia = sqrt(soma); // Cálculo da raiz quadrada da soma de todas as distâncias entre cada ponto

    return distancia;
}
//
TipoDistancia *AlocaTipoDistancia(BancoImagens *b) {
    TipoDistancia *distancia;
    distancia = (TipoDistancia *)malloc( (b->N - 1) * sizeof(TipoDistancia));

    return distancia;
}
//
void PreencheDistanciaImagemParaImagem(TipoImagem **imagem, BancoImagens b) {
    int i = 0, j = 0;

    for(i = 0; i < b.N; i++) {
        //printf("%s - ", imagem[i]->nomeImagem);
        for(j = 0; j < b.N; j++) {
            if(i < j) {
                // Coloca o nome da imagem na qual a imagem na posição j está sendo comparada
                strcpy(imagem[i]->distancia_entre_imagem[j-1].img2, imagem[j]->nomeImagem);
                // Calcula a distância
                imagem[i]->distancia_entre_imagem[j-1].distancia = CalculaDistancia(imagem[i]->descritor, imagem[j]->descritor);
                //printf("%s(%.4lf) ", imagem[i]->distancia_entre_imagem[j-1].img2, imagem[i]->distancia_entre_imagem[j-1].distancia);
            }
            else if(i > j) {
                // Coloca o nome da imagem na qual a imagem na posição j está sendo comparada
                strcpy(imagem[i]->distancia_entre_imagem[j].img2, imagem[j]->nomeImagem);
                // Calcula a distância
                imagem[i]->distancia_entre_imagem[j].distancia = CalculaDistancia(imagem[i]->descritor, imagem[j]->descritor);
                //printf("%s(%.4lf) ", imagem[i]->distancia_entre_imagem[j-1].img2, imagem[i]->distancia_entre_imagem[j-1].distancia);
            }
        }
        //printf("\n\n");
    }
}

void ImprimeDistanciaImagemParaImagem(TipoImagem **imagem, BancoImagens b, FILE *arqSaida) {
    int i = 0, j = 0;

    for(i = 0; i < b.N; i++) {
        //printf("%s - ", imagem[i]->nomeImagem);
        fprintf(arqSaida, "%s - ", imagem[i]->nomeImagem);
        for(j = 0; j < b.K; j++) {
            //printf("%s(%.4lf)", imagem[i]->distancia_entre_imagem[j].img2, imagem[i]->distancia_entre_imagem[j].distancia);
            fprintf(arqSaida,"%s(%.4lf)", imagem[i]->distancia_entre_imagem[j].img2, imagem[i]->distancia_entre_imagem[j].distancia);
            if(j < b.K-1) fprintf(arqSaida," ");
        }
        //printf("\n\n");
        fprintf(arqSaida,"\n");
    }
    fprintf(arqSaida,"\n");
}

TipoDistanciaEntreParImagens *CriaVetorComTodasDistancias(TipoImagem **imagem, BancoImagens b) {
    TipoDistanciaEntreParImagens *vetor;
    int num_elem = ((b.N * b.N) - b.N) / 2; // Número de elementos da matriz triangular superior
                                            // Fórmula para calcular número de elementos de uma matriz triangular superior quadrado
                                            // onde N = número de linhas, colunas
                                            // (N² - N)/2

    vetor = (TipoDistanciaEntreParImagens *)malloc(num_elem * sizeof(TipoDistanciaEntreParImagens));

    int i = 0, j = 0 , k = 0;

    for(i = 0; i < b.N; i++) {
        for(j = i + 1; j < b.N; j++) {
            if(i < j) {
                strcpy(vetor[k].img1, imagem[i]->nomeImagem);
                strcpy(vetor[k].img2, imagem[i]->distancia_entre_imagem[j-1].img2);
                vetor[k].distancia = imagem[i]->distancia_entre_imagem[j-1].distancia;
            }
            else if(i > j) {
                strcpy(vetor[k].img1, imagem[i]->nomeImagem);
                strcpy(vetor[k].img2, imagem[i]->distancia_entre_imagem[j].img2);
                vetor[k].distancia = imagem[i]->distancia_entre_imagem[j].distancia;
            }
            k++;
        }
    }

    return vetor;
}

void ImprimeVetorComTodasDistancias(TipoDistanciaEntreParImagens *vetor, BancoImagens b, FILE *arqSaida) {

    int i = 0;

    for(i = 0; i < b.P; i++) {
            //printf("%s,%s - %.4lf\n", vetor[i].img1, vetor[i].img2, vetor[i].distancia);
            fprintf(arqSaida, "%s,%s - %.4lf\n", vetor[i].img1, vetor[i].img2, vetor[i].distancia);
    }
    fprintf(arqSaida, "\n");
}

