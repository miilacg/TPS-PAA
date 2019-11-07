//
// Created by Samuel on 11/5/19.
//

#include "DistanciaEdicao.h"
#include <stdlib.h>
#include <stdio.h>

int aux = 0;

void InicializaMatrizDistancia(MatrizDistancia *mD, int SizeFirstWord, int SizeSecondWord) {
    int i;

    mD->Numero = (int**)malloc(SizeFirstWord * sizeof(int*));
    for(i = 0; i<SizeFirstWord; i++) {
        mD->Numero[i] = (int*)malloc(SizeSecondWord * sizeof(int));
    }
    mD->Custo = (int**)malloc(SizeFirstWord * sizeof(int*));
    for(i = 0; i<SizeFirstWord; i++) {
        mD->Custo[i] = (int*)malloc(SizeSecondWord * sizeof(int));
    }
    mD->Operacoes = (int**)malloc(SizeFirstWord * sizeof(int*));
    for(i = 0; i<SizeFirstWord; i++) {
        mD->Operacoes[i] = (int*)malloc(SizeSecondWord * sizeof(int));
    }
}

int Minimo(int Deletar, int Inserir, int Substituir) {
    if (Deletar <= Inserir && Deletar <= Substituir) {
        aux = 2;
        return Deletar;
    }
    if (Inserir <= Deletar && Inserir <= Substituir) {
        aux = 3;
        return Inserir;
    }else {
        aux = 4;
        return Substituir;
    }
}

void distanciaIterativo(char *FirstWord, char *SecondWord, int m, int n, MatrizDistancia *p) {
    int i = 0, j = 0;

    for(i = 0; i < m; i++) {
        p->Numero[i][0] = i;
        //printf("%d", p->Numero[i][0]);
    }
    printf("\n");
    for(i = 0; i < n; i++) {
        p->Numero[0][i] = i;
        //printf("%d", p->Numero[0][i]);
    }
    printf("\n");
    for(i = 1; i < m; i++) {
        for(j = 1; j < n; j++) {
            if(FirstWord[i-1] == SecondWord[j-1]) {
                p->Custo[i][j] = 0;
            }else {
                p->Custo[i][j] = 1;
            }
            p->Numero[i][j] = Minimo((p->Numero[i-1][j] + 1),(p->Numero[i][j-1] + 1),(p->Numero[i-1][j-1] + p->Custo[i][j]));
            if(aux == 2) {
                p->Operacoes[i][j] = aux;
            }
            if(aux == 3) {
                p->Operacoes[i][j] = aux;
            }
            if(aux == 4) {
                p->Operacoes[i][j] = aux;
            }
        }
    }
    printf("Resultado da menor distancia entre as palavras pelo algoritmo iterativo: %d\n", p->Numero[m-1][n-1]);
}

void CalculaOperacoes(MatrizDistancia *p, int m, int n) {
    int i = m, j = n;
    int delete = 0, inserir = 0, substituir = 0, manter = 0;

    while(i != 0 && j != 0) {
        if(p->Operacoes[i][j] == 2) {
            i--;
            delete++;
        }
        if(p->Operacoes[i][j] == 3) {
            j--;
            inserir++;
        }
        if(p->Operacoes[i][j] == 4 && p->Custo[i][j] != 0) {
            i--;
            j--;
            substituir++;
        }
        if(p->Operacoes[i][j] == 4 && p->Custo[i][j] == 0) {
            i--;
            j--;
            manter++;
        }
    }
    printf("Quantidade de operacoes Deletar: %d\n", delete);
    printf("Quantidade de operacoes Inserir: %d\n", inserir);
    printf("Quantidade de operacoes Substituir: %d\n", substituir);
    printf("Quantidade de operacoes Manter: %d\n", manter);
}

int distanciaEdicao(char *FirstWord, char *SecondWord, int m, int n) {
    int custo;

    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }
    if (FirstWord[m - 1] == SecondWord[n - 1]) {
        custo = 0;
    } else {
        custo = 1;
    }
    return Minimo((distanciaEdicao(FirstWord, SecondWord, m, n - 1) + 1), //Apagar
                  (distanciaEdicao(FirstWord, SecondWord, m - 1, n) + 1), //Introduzir
                  (distanciaEdicao(FirstWord, SecondWord, m - 1, n - 1) + custo)); //Substituir
}

void PrintaMatriz(MatrizDistancia *p, int m, int n) {
    int i, j;

    printf("Matriz gerada:\n");
    for(i = 0; i < m; i ++) {
        for(j = 0; j < n; j++) {
            printf("%d", p->Numero[i][j]);
        }
        printf("\n");
    }
}
