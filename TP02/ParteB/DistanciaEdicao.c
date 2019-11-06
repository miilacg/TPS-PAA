//
// Created by Samuel on 11/5/19.
//

#include "DistanciaEdicao.h"
#include <stdlib.h>
#include <stdio.h>

int i = -1;
int apagar = 0, introduzir = 0, substituir = 0;

void InicializaOperacoes(ContabilizaOperacoes *Op) {
    Op->OperacaoApagar = 0;
    Op->OperacaoIntroduzir = 0;
    Op->OperacaoSubstituir = 0;
    Op->OperacaoManter = 0;
    Op->ResultadoRecursao = -1;
}

int Minimo(int x, int y, int z) {
    if (x <= y && x <= z) {
        printf("valor de x: %d\n", x);
        return x;
    }
    if (y <= x && y <= z) {
        printf("valor de y: %d\n", y);
        return y;
    }else {
        printf("valor de z: %d\n", z);
        return z;
    }
}

int distanciaEdicao(char *FirstWord, char *SecondWord, int m, int n, int aux, ContabilizaOperacoes *Op) {
    /*if (aux == 1) {
        Op->OperacaoApagar = Op->OperacaoApagar + 1;
    }
    if (aux == 2) {
        Op->OperacaoIntroduzir = Op->OperacaoIntroduzir + 1;
    }
    if (aux == 3) {
        Op->OperacaoSubstituir = Op->OperacaoSubstituir + 1;
    }
    if (aux == 4) {
        Op->OperacaoManter = Op->OperacaoManter + 1;
    }*/
    i++;
    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }
    if (FirstWord[m - 1] == SecondWord[n - 1]) {
        distanciaEdicao(FirstWord, SecondWord, m - 1, n - 1, 4, &Op);
    }
    return 1 + Minimo(distanciaEdicao(FirstWord, SecondWord, m, n - 1, 1, &Op), //Apagar
                      distanciaEdicao(FirstWord, SecondWord, m - 1, n, 2, &Op), //Introduzir
                      distanciaEdicao(FirstWord, SecondWord, m - 1, n - 1, 3, &Op)); //Substituir
}

void printa() {
    printf("%d\n", i);
    printf("%d\n", apagar);
    printf("%d\n", introduzir);
    printf("%d\n", substituir);
}

void ImprimeQtdOperacoes(ContabilizaOperacoes Op) {
    printf("A Quantidade de Operações do tipo Apagar feitas foram: %d\n", Op.OperacaoApagar);
    printf("A Quantidade de Operações do tipo Introduzir feitas foram: %d\n", Op.OperacaoIntroduzir);
    printf("A Quantidade de Operações do tipo Substituir feitas foram: %d\n", Op.OperacaoSubstituir);
    printf("A Quantidade de Operações do tipo Manter feitas foram: %d\n", Op.OperacaoManter);
    printf("A Quantidade de Operações do tipo Recursao feitas foram: %d\n", Op.ResultadoRecursao);
}