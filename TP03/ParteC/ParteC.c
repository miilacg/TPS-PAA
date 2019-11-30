//
// Created by Samuel on 29/11/2019.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ParteC.h"

void IniciarVetorChar(VetorChar *V, char *Palavra) {
    int TamPalavra, i, j, cont = 0, k = 0;
    char aux[56];
    TamPalavra = strlen(Palavra);
    strcpy(aux, Palavra);
    for(i = 0; i < TamPalavra; i++) {
        for(j = i+1; j < TamPalavra; j++) {
            if(Palavra[i] == aux[j]) {
                aux[j] = 48;
            }
        }
    }
    for(i = 0; i < TamPalavra; i++) {
        if(aux[i] != 48) {
            cont++;
        }
    }
    V->CaracteresEspecificos = malloc(cont * sizeof(int));
    V->QtdCarac = cont;
    for(i = 0; i < TamPalavra; i++) {
        if(aux[i] != 48) {
            V->CaracteresEspecificos[k] = aux[i];
            k++;
        }
    }
}

int Retorna(VetorChar *V) {
    return V->QtdCarac;
}

void IniciarMascara(MascaraBits *M, VetorChar *V,  int QtdCharRepetidos, char *Palavra) {
    int i, j;
    int TamPalavra;

    TamPalavra = strlen(Palavra);
    M->VetorMascara = malloc(QtdCharRepetidos * sizeof(int));
    for(i = 0; i < QtdCharRepetidos; i++) {
        M->VetorMascara[i].Caractere = V->CaracteresEspecificos[i];
        M->VetorMascara[i].VetorBitsdoCaractere = malloc(TamPalavra * sizeof(int));
    }

    for(i = 0; i < QtdCharRepetidos; i++) {
        for(j = 0; j < TamPalavra; j++) {
            M->VetorMascara[i].VetorBitsdoCaractere[j] = 0;
        }
    }

    for(i = 0; i < QtdCharRepetidos; i++) {
        for(j = 0; j < TamPalavra; j ++) {
            if(M->VetorMascara[i].Caractere == Palavra[j]) {
                M->VetorMascara[i].VetorBitsdoCaractere[j] = 1;
            }
        }
    }

    for(i = 0; i < QtdCharRepetidos; i++) {
        printf("O Caractere e: %c\n", M->VetorMascara[i].Caractere);
        printf("Seu vetor de bits e: ");
        for(j = 0; j < TamPalavra; j++) {
            printf("%d", M->VetorMascara[i].VetorBitsdoCaractere[j]);
        }
        printf("\n");
    }
}

void ShiftAnd(MascaraBits *M, VetoresR *Vet, VetorChar *V, char *Palavra, char *Texto) {
    int k = 0;
    int i, j, x;
    int TamPalavra, TamTexto;
    int aux;

    TamPalavra = strlen(Palavra);
    TamTexto = strlen(Texto);

    printf("Tamanho Texto: %d\n", TamTexto);

    Vet->R = (int**)malloc(TamTexto * sizeof(int*));
    Vet->RLinha = (int**)malloc(TamTexto * sizeof(int*));
    for(i = 0; i < TamTexto; i++) {
        Vet->R[i] = (int*)malloc(TamPalavra * sizeof(int));
        Vet->RLinha[i] = (int*)malloc(TamPalavra * sizeof(int));
    }

    for(i = 0; i < TamTexto; i++) {
        for(j = 0; j < TamPalavra; j++) {
            Vet->R[i][j] = 0;
            Vet->RLinha[i][j] = 0;
        }
    }
    Vet->R[0][0] = 1;

    for(i = 0; i < TamTexto; i++) {
        printf("Vetor RLinha e: ");
        for(j = 0; j < TamPalavra; j++) {
            for(x = 0; x < V->QtdCarac; x++) {
                if(Texto[i] == M->VetorMascara[x].Caractere) {
                    k = x;
                }
            }
            if(Texto[i] == M->VetorMascara[k].Caractere) {
                if(Vet->R[i][j] == 0 && M->VetorMascara[k].VetorBitsdoCaractere[j] == 0) {
                    Vet->RLinha[i][j] = 0;
                }
                if(Vet->R[i][j] == 0 && M->VetorMascara[k].VetorBitsdoCaractere[j] == 1) {
                    Vet->RLinha[i][j] = 0;
                }
                if(Vet->R[i][j] == 1 && M->VetorMascara[k].VetorBitsdoCaractere[j] == 0) {
                    Vet->RLinha[i][j] = 0;
                }
                if(Vet->R[i][j] == 1 && M->VetorMascara[k].VetorBitsdoCaractere[j] == 1) {
                    Vet->RLinha[i][j] = 1;
                }
                printf("%d", Vet->RLinha[i][j]);
            }else {
                Vet->RLinha[i][j] = 0;
                printf("%d", Vet->RLinha[i][j]);
            }
        }
        printf("\n");
        if(i+1 < TamTexto) {
            for(j = 0; j < TamPalavra; j++) {
                if(Vet->RLinha[i][j] == 1) {
                    aux = Vet->RLinha[i][j];
                    Vet->R[i+1][j] = Vet->RLinha[i][j+1];
                    Vet->R[i+1][j+1] = aux;
                }
            }
            Vet->R[i+1][0] = 1;
            printf("Vetor R e: ");
            for(j = 0; j < TamPalavra; j++) {
                printf("%d",Vet->R[i+1][j]);
            }
            printf("\n");
        }
        if(Vet->RLinha[i][TamPalavra-1] == 1) {
            printf("Casou!");
        }
    }
}