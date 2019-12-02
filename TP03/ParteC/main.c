#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ParteC.h"

int main() {
    VetorChar *V;
    MascaraBits *M;
    VetoresR *R;
    int QtdCharRepetidos;
    int op, k;
    char *PalavraPadrao;
    char *Texto;
    clock_t start_t, end_t;
    double total_t = 0;

    do{
        //menu para selecao das opcoes
        printf ("\n****************************************************************************************");
        printf ("\n*                                                                                      *");
        printf ("\n*                            Escolha uma das opcoes abaixo                             *");
        printf ("\n*                           1 - Algoritmo Shift-And Exato                              *");
        printf ("\n*                           2 - Algoritmo Shift-And Aproximado                         *");
        printf ("\n*                           3 - Sair                                                   *");
        printf ("\n*                                                                                      *");
        printf ("\n****************************************************************************************");
        printf ("\n");
        do{
            printf ("Entre com a opcao valida: ");
            scanf ("%d", &op);
        }while (op < 0 || op > 3); //garante que a opcao de entrada sera valida

        switch(op) {
            case 1:
                PalavraPadrao = (int*)malloc(46 * sizeof(int));
                Texto = (int*)malloc(256 * sizeof(int));
                printf("Entre com a palavra Padrao: \n");
                getchar();
                gets(PalavraPadrao);
                printf("Entre com o Texto: \n");
                gets(Texto);
                start_t = clock(); //Inicio da contagem do tempo
                IniciarVetorChar(&V, PalavraPadrao);
                QtdCharRepetidos = Retorna(&V);
                IniciarMascara(&M, &V, QtdCharRepetidos, PalavraPadrao);
                ShiftAnd(&M, &R,  &V,PalavraPadrao, Texto);
                end_t = clock(); //Final da contagem do tempo
                printf("Tempo gasto em Milissegundos: %lf\n", total_t);
                break;
            case 2:
                PalavraPadrao = (int*)malloc(46 * sizeof(int));
                Texto = (int*)malloc(256 * sizeof(int));
                printf("Entre com a palavra Padrao: \n");
                getchar();
                gets(PalavraPadrao);
                printf("Entre com o Texto: \n");
                gets(Texto);
                printf("Entre com o K: \n");
                scanf ("%d", &k);
                start_t = clock(); //Inicio da contagem do tempo
                IniciarVetorChar(&V, PalavraPadrao);
                QtdCharRepetidos = Retorna(&V);
                IniciarMascara(&M, &V, QtdCharRepetidos, PalavraPadrao);
                ShiftAndAproximado(&M, &R,  &V,PalavraPadrao, Texto, k);
                end_t = clock(); //Final da contagem do tempo
                printf("Tempo gasto em Milissegundos: %lf\n", total_t);
                break;
            case 3:
                exit(0);
        }
    }while(op!=3);
}