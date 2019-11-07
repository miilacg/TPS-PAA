#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DistanciaEdicao.h"

int main() {

    char *FirstWord;
    char *SecondWord;
    int SizeFirstWord = 0;
    int SizeSecondWord = 0;
    MatrizDistancia h;

    FirstWord = (int*)malloc(46 * sizeof(int));
    SecondWord = (int*)malloc(46 * sizeof(int));
    printf("Entre com a primeira palavra: \n");
    gets(FirstWord);
    printf("Entre com a segunda palavra: \n");
    gets(SecondWord);
    SizeFirstWord = strlen(FirstWord);
    SizeSecondWord = strlen(SecondWord);

    InicializaMatrizDistancia(&h, SizeFirstWord+1, SizeSecondWord+1);
    distanciaIterativo(FirstWord, SecondWord, SizeFirstWord+1, SizeSecondWord+1, &h);
    CalculaOperacoes(&h, SizeFirstWord, SizeSecondWord);
    printf("Resposta: %d\n", distanciaEdicao(FirstWord, SecondWord, SizeFirstWord, SizeSecondWord));
    PrintaMatriz(&h, SizeFirstWord, SizeSecondWord);
    return 0;
}