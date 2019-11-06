//
// Created by caio on 11/5/19.
//

#ifndef PARTEB_DISTANCIAEDICAO_H
#define PARTEB_DISTANCIAEDICAO_H

typedef struct {
    int OperacaoApagar;
    int OperacaoIntroduzir;
    int OperacaoSubstituir;
    int OperacaoManter;
    int ResultadoRecursao;
}ContabilizaOperacoes;

void InicializaOperacoes(ContabilizaOperacoes *Op);
int Minimo(int x, int y, int z);
int distanciaEdicao(char *FirstWord, char *SecondWord, int m, int n, int aux, ContabilizaOperacoes *Op);
void ImprimeQtdOperacoes(ContabilizaOperacoes Op);
void printa();

#endif //PARTEB_DISTANCIAEDICAO_H
