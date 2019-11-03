#include "partea.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//le o arquivo para saber o desenho do labirinto e posicao do estudante
int lerArquivo(TipoPiramide *piramide, char *nomeArquivo){
	int num, i, j, qtdLinhas;
	FILE *arquivo;
    char caminhoArquivo[150], comparacao;
    strcpy(caminhoArquivo, "C:\\Users\\Camila\\Desktop\\Camila\\Trabalho\\Superior\\PAA\\TPS-PAA\\TP02\\"); //caminho ate o arquivo
    strcat(caminhoArquivo, nomeArquivo); //nome do arquivo recebido pelo usuario
    strcat(caminhoArquivo, ".txt");
    
    arquivo = fopen(caminhoArquivo, "r"); //une as partes que compoem o caminhoArquivo
    
    if (arquivo == NULL) {
        printf("\nErro de leitura do arquivo\n");
        return 0; //retorna 0 caso nao seja possivel ler o arquivo
    }else{
    	qtdLinhas = contaLinhas(piramide, nomeArquivo);
    	while (!feof(arquivo)) { //enquanto nao for o fim do arquivo
            for (i = 0; i < qtdLinhas; i++) { //percorre o arquivo
                for (j = 0; j <= i; j++) {
                    fscanf(arquivo, "%c ", &num); //le o que tem na posicao
                    piramide->espaco[i][j] = num; //preenche o labirinto
                }
            }
        }
        //imprimir(piramide);
	}
	fclose(arquivo);
    return 1; //retorna 1 se a leitura for feita com sucesso
}

//aloca o espaco necessario para o labirinto de acordo com os tamanhos lidos no arquivo
void alocaEspaco(TipoPiramide *piramide){
	int i;
    piramide->espaco = (char **) malloc(piramide->qtdLinhas * sizeof(char *));
    for (i = 0; i < piramide->qtdLinhas; i++) {
        piramide->espaco[i] = (char *) malloc(piramide->qtdLinhas * sizeof(char));
    }
}

int contaLinhas(TipoPiramide *piramide, char *nomeArquivo){
	int qtdLinhas = 1;
	char comparacao;	
	FILE *arq;
    char caminhoArquivo[150];
    strcpy(caminhoArquivo, "C:\\Users\\Camila\\Desktop\\Camila\\Trabalho\\Superior\\PAA\\TPS-PAA\\TP02\\"); //caminho ate o arquivo
    strcat(caminhoArquivo, nomeArquivo); //nome do arquivo recebido pelo usuario
    strcat(caminhoArquivo, ".txt");
    
    arq = fopen(caminhoArquivo, "r"); //une as partes que compoem o caminhoArquivo
    
	while (!feof(arq)){ //enquanto nao for o fim do arquivo
		fscanf(arq, "%c", &comparacao); //le o que tem na posicao
		if (comparacao == '\n'){
			qtdLinhas++;
		}
    }
    piramide->qtdLinhas = qtdLinhas;
    alocaEspaco(piramide); //chama a funcao que faz a alocao do espaco para a piramide
    return qtdLinhas;
}

//funcoes para testes
void imprimir(TipoPiramide *piramide){//imprimi os valores lidos no arquivo
    int i, j;
    for (i = 0; i < piramide->qtdLinhas; i++) {
        for (j = 0; j <=i; j++) {
            printf("\t%c ", piramide->espaco[i][j]);
        }
        printf ("\n");
    }
}
