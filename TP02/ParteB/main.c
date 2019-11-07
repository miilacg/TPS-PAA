//Universidade Federal de Vicosa - Campus Florestal
//Curso de Ciencia da Computacao
//Disciplina de Projeto e Analise de Algoritmos
//Professor Daniel Mendes
//Alunos: Camila C. Guimaraes - 2256 e Samuel Silva - 2662
//Trabalho Pratico 02

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "DistanciaEdicao.h"

#define DEBUG 1 ///DEBUG pode ser 1 ou 0. 1 ativa e 0 desativa o modo DEBUG.

int main() {

    char *FirstWord;
    char *SecondWord;
    int SizeFirstWord = 0;
    int SizeSecondWord = 0;
    int op, i = 0;
    clock_t start_t, end_t; //Tipo da biblioteca <time.h>
    double total_t = 0;
    char vetorFirstWord[10][46] = {"caco","zelda","paralelograma","thor","desinstitucionalizado","transdisciplinaridade","Exornar","Alcunha","nintendo","marx"};
    char vetorSecondWord[10][46] = {"macaco","link","liquidificador","zeus","extraterritorialidade","pluridisciplinaridade","Exorar","Ardiloso","sega","engels"};
    MatrizDistancia h;


    #if(DEBUG == 0)
        do{
            //menu para selecao das opcoes
            printf ("\n****************************************************************************************");
            printf ("\n*                                                                                      *");
            printf ("\n*                            Escolha uma das opcoes abaixo                             *");
            printf ("\n*                               1 - Distancia de edicao iterativo                      *");
            printf ("\n*                               2 - Distancia de edicao recursivo                      *");
            printf ("\n*                               3 - Sair                                               *");
            printf ("\n*                                                                                      *");
            printf ("\n****************************************************************************************");
            printf ("\n");
            do{
                printf ("Entre com a opcao valida: ");
                scanf ("%d", &op);
            }while (op < 0 || op > 3); //garante que a opcao de entrada sera valida

            switch(op) {
                case 1:
                    FirstWord = (int*)malloc(46 * sizeof(int));
                    SecondWord = (int*)malloc(46 * sizeof(int));
                    printf("Entre com a primeira palavra: \n");
                    getchar();
                    gets(FirstWord);
                    printf("Entre com a segunda palavra: \n");
                    gets(SecondWord);
                    SizeFirstWord = strlen(FirstWord);
                    SizeSecondWord = strlen(SecondWord);
                    InicializaMatrizDistancia(&h, SizeFirstWord+1, SizeSecondWord+1);
                    distanciaIterativo(FirstWord, SecondWord, SizeFirstWord+1, SizeSecondWord+1, &h);
                    CalculaOperacoes(&h, SizeFirstWord, SizeSecondWord);
                    PrintaMatriz(&h, SizeFirstWord, SizeSecondWord);
                    break;
                case 2:
                    FirstWord = (int*)malloc(46 * sizeof(int));
                    SecondWord = (int*)malloc(46 * sizeof(int));
                    printf("Entre com a primeira palavra: \n");
                    getchar();
                    gets(FirstWord);
                    printf("Entre com a segunda palavra: \n");
                    gets(SecondWord);
                    SizeFirstWord = strlen(FirstWord);
                    SizeSecondWord = strlen(SecondWord);
                    InicializaMatrizDistancia(&h, SizeFirstWord+1, SizeSecondWord+1);
                    distancia(FirstWord, SecondWord, SizeFirstWord+1, SizeSecondWord+1, &h);
                    printf("Resultado da menor distancia entre as palavras pelo algoritmo recursivo: %d\n", distanciaEdicao(FirstWord, SecondWord, SizeFirstWord, SizeSecondWord));
                    CalculaOperacoes(&h, SizeFirstWord, SizeSecondWord);
                    PrintaMatriz(&h, SizeFirstWord, SizeSecondWord);
                    break;
                case 3:
                    exit(0);
            }
        }while(op!=3);
    #elif(DEBUG == 1)
        do{
            //menu para selecao das opcoes
            printf ("\n****************************************************************************************");
            printf ("\n*                                                                                      *");
            printf ("\n*                            Escolha uma das opcoes abaixo                             *");
            printf ("\n*                               1 - Distancia de edicao iterativo modo DEBUG           *");
            printf ("\n*                               2 - Distancia de edicao recursivo modo DEBUG           *");
            printf ("\n*                               3 - Sair                                               *");
            printf ("\n*                                                                                      *");
            printf ("\n****************************************************************************************");
            printf ("\n");
            do{
                printf ("Entre com a opcao valida: ");
                scanf ("%d", &op);
            }while (op < 0 || op > 3); //garante que a opcao de entrada sera valida

            switch(op) {
                case 1:
                    for(i = 0; i < 10; i++) {
                        SizeFirstWord = strlen(vetorFirstWord[i]);
                        SizeSecondWord = strlen(vetorSecondWord[i]);
                        InicializaMatrizDistancia(&h, SizeFirstWord+1, SizeSecondWord+1);
                        start_t = clock(); //Inicio da contagem do tempo
                        distanciaIterativo(vetorFirstWord[i], vetorSecondWord[i], SizeFirstWord+1, SizeSecondWord+1, &h);
                        end_t = clock(); //Final da contagem do tempo
                        CalculaOperacoes(&h, SizeFirstWord, SizeSecondWord);
                        total_t = ((end_t - start_t)*1000/ CLOCKS_PER_SEC) + total_t;
                        //PrintaMatriz(&h, SizeFirstWord, SizeSecondWord);
                    }
                    printf("Tempo gasto em Milissegundos: %lf\n", total_t/10);
                    break;
                case 2:
                    for(i = 0; i < 10; i++) {
                        SizeFirstWord = strlen(vetorFirstWord[i]);
                        SizeSecondWord = strlen(vetorSecondWord[i]);
                        InicializaMatrizDistancia(&h, SizeFirstWord+1, SizeSecondWord+1);
                        distancia(vetorFirstWord[i], vetorSecondWord[i], SizeFirstWord+1, SizeSecondWord+1, &h);
                        start_t = clock(); //Inicio da contagem do tempo
                        printf("Resultado da menor distancia entre as palavras pelo algoritmo recursivo: %d\n", distanciaEdicao(vetorFirstWord[i], vetorSecondWord[i], SizeFirstWord, SizeSecondWord));
                        end_t = clock(); //Final da contagem do tempo
                        CalculaOperacoes(&h, SizeFirstWord, SizeSecondWord);
                        total_t = ((end_t - start_t)*1000/ CLOCKS_PER_SEC) + total_t;
                        //PrintaMatriz(&h, SizeFirstWord, SizeSecondWord);
                    }
                    printf("Tempo gasto em Milissegundos: %lf\n", total_t/10);
                    break;
                case 3:
                    exit(0);
            }
        }while(op!=3);
    #endif


    return 0;
}