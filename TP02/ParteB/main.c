#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DistanciaEdicao.h"

int main() {
    char FirstWord[46];
    char SecondWord[46];
    int m = 0, n = 0;
    ContabilizaOperacoes contabilizar;

    InicializaOperacoes(&contabilizar); //Inicializa as variaveis da struct ContabilizaOperacoes
    printf("Entre com a primeira palavra: \n");
    scanf("%s", FirstWord);
    printf("Entre com a segunda palavra: \n");
    scanf("%s", SecondWord);
    m = strlen(FirstWord);
    n = strlen(SecondWord);
    //printf("m: %d\n", m);
    //printf("n: %d\n", n);
    printf("Resultado: %d\n", distanciaEdicao(FirstWord, SecondWord, m, n, 0, &contabilizar));
    ImprimeQtdOperacoes(contabilizar);
    printa();
    return 0;
}