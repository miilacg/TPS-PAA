#include "labirinto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//0 - celula onde o estudante está incialmente
//1 - celula vazia
//2 - celula ocupada com parede
//3 - celula acessivel apenas por chave

//aloca o espaco necessario para o labirinto de acordo com os tamanhos lidos no arquivo
void alocaEspaco(TipoLabirinto *labirinto){
	int i;
    labirinto->espaco = (char **) malloc(labirinto->linhas * sizeof(char *));//saber quanto espaco o char ocupa
    for (i = 0; i < labirinto->linhas; i++) {
        labirinto->espaco[i] = (char *) malloc(labirinto->colunas * sizeof(char));
    }
}

//le o arquivo para saber o desenho do labirinto e posicao do estudante
int lerArquivo(TipoLabirinto *labirinto, char *nomeArquivo){
	FILE *arquivo;
    char caminhoArquivo[150], cor;
    int i, j, linhas, colunas, chaves;
    strcpy(caminhoArquivo, "C:\\Users\\Camila\\Desktop\\Camila\\Trabalho\\Superior\\PAA\\TPS\\TP01\\");
    strcat(caminhoArquivo, nomeArquivo);
    strcat(caminhoArquivo, ".txt");
    arquivo = fopen(caminhoArquivo, "r"); //une as partes que compoem o caminhoArquivo
    /*for (i = 0; i<150; i++){
    	printf ("%c", caminhoArquivo[i]);
	}*/
    if (arquivo == NULL) {
        printf("Erro de leitura do arquivo\n");
        return 0; //retorna 0 caso nao seja possivel ler o arquivo
    }else{
        fscanf(arquivo, "%d %d %d\n", &linhas, &colunas, &chaves); //faz a lelitura de quantas linhas e colunas tera no labirinto
        labirinto->linhas = linhas;
        labirinto->colunas = colunas;
        labirinto->chaves = chaves;
        alocaEspaco(labirinto);
        while (!feof(arquivo)) { //enquanto nao for o fim do arquivo
            for (i = 0; i < labirinto->linhas; i++) { //preenche o espaco reservado de acordo com o arquivo
                for (j = 0; j < labirinto->colunas; j++) {
                    fscanf(arquivo, "%c ", &cor);
                    labirinto->espaco[i][j] = cor;
                }
            }
        }
        //imprimir(labirinto);
	}
    fclose(arquivo);
    return 1; //retorna 1 se a leitura for feita com sucesso
}

void imprimir(TipoLabirinto *labirinto) {
    int i, j;
    for (i = 0; i < labirinto->linhas; i++) {
        for (j = 0; j < labirinto->colunas; j++) {
            printf("\t%c ", labirinto->espaco[i][j]);
        }
    }
}

//encontrar a posicao do estudante e depois chamar essa funcao uma unica vez
int movimenta_estudante(){
	return 0;
} 

void imprimirResposta();

int inicializaPosicoes(TipoLabirinto *labirinto, TipoEstudante *estudante){
    int i, j;
    for (i = 0; i < labirinto->linhas; i++) {
        for (j = 0; j < labirinto->colunas; j++) {
            if (labirinto->espaco[i][j] == 0) {//se a posicao for a que o estudante esta
                estudante->pInicial.x = i;
                estudante->pInicial.y = j;
                estudante->pAtual.x = i;
                estudante->pAtual.y = j;
                estudante->pFinal.x = 0;
                estudante->pFinal.y = 0;
            }
        }
    }
    return movimenta_estudante();
}
