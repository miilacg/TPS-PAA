#include "partea.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
int lerArquivo(TipoPiramide *piramide, char *nomeArquivo){//le o arquivo
	int num, i, j, qtdLinhas, aux = 0;
	FILE *arquivo;
    char caminhoArquivo[150], caracter;
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
                    fscanf(arquivo, "%c ", &caracter); //le o que tem na posicao
                    num = caracter - '0'; //convertendo char em int
                    piramide->espaco[i][j] = num; //preenche o labirinto
                }
            }
        }
        imprimir(piramide);
	}
	fclose(arquivo);
    return 1; //retorna 1 se a leitura for feita com sucesso
}

void alocaEspaco(TipoPiramide *piramide){//aloca o espaco necessario para o labirinto de acordo com os tamanhos lidos no arquivo
	int i;
    piramide->espaco = (int **) malloc(piramide->qtdLinhas * sizeof(int *));
    for (i = 0; i < piramide->qtdLinhas; i++) {
        piramide->espaco[i] = (int *) malloc(piramide->qtdLinhas * sizeof(int));
    }
}

int contaLinhas(TipoPiramide *piramide, char *nomeArquivo){//retorna a altura da piramide
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

int geraPiramide(int num, int tamanho, int contador){//funcao extra para gerar piramides
    int piramide[tamanho][tamanho], j, i, caracter;
    FILE *arquivo; 
    char caminhoArquivo[150], nomeArquivo[11]; 
	    
	sprintf(nomeArquivo, "piramide%d", num);		
	strcpy(caminhoArquivo, "C:\\Users\\Camila\\Desktop\\Camila\\Trabalho\\Superior\\PAA\\TPS-PAA\\TP02\\"); //caminho ate o arquivo
    strcat(caminhoArquivo, nomeArquivo); 
    strcat(caminhoArquivo, ".txt");
    arquivo = fopen(caminhoArquivo, "w+");
    
    //caminho e nome do arquivo que sera escrito
    if (arquivo == NULL){
        printf("\nErro\n");
	}else{//se o arquivo for criado com sucesso
		for (i = 0; i < tamanho; i++) {
            for (j = 0; j <= i; j++) {
            	caracter = rand()%10;
                piramide[i][j] = caracter;
            }
        }
        for (i = 0; i < tamanho; i++) { //escreve no arquivo o que esta na matriz
            for (j = 0; j <= i; j++) {
                fprintf(arquivo, "%d ", piramide[i][j]);
            }
            if (i<tamanho-1)
            	fprintf(arquivo, "\n");
        }
		contador ++;
	}
    fclose(arquivo); //fecha o arquivo depois de escrever
    return contador; // o contador e utilizado para contar quantas piramides foram criadas
}

int piramideRecursiva(TipoPiramide *piramide, TipoCaminho *caminho, int linha, int coluna){//piramide recursiva
	int somaBaixo = 0, somaDireita = 0;	
	
	//se nao for a ultima linha da piramide
	//verifica se vai somar se ainda estiver dentro do labirinto e se ainda nao tiver tentado aquela posicao
	if ((linha >= 0) && (linha < piramide->qtdLinhas) && (coluna >= 0) && (coluna < piramide->qtdLinhas) && (caminho->caminhoPercorrido == 0)){
		caminho->caminhoPercorrido[linha][coluna] = 1;
		somaBaixo = (piramideRecursiva(piramide, caminho, linha, coluna+1) + piramide->espaco[linha][coluna-1]);
		somaDireita = (piramideRecursiva(piramide, caminho, linha+1, coluna+1) + piramide->espaco[linha-1][coluna-1]);
		if (somaBaixo<somaDireita){
			return somaDireita;
		}else{
			return somaBaixo;
		}
	}    
	
	//se chegar na ultima linha da piramide
	if ((caminho->linha == piramide->qtdLinhas - 1){
		if(maxSoma > maxSomaAtual){
			printf ("A maior soma é: %d\n", maxSoma);
			return 1;
		}
		return 0;
	}	
}

//encontrar a posicao do estudante e movimenta ele atraves de chamadas recursivas
int movimenta_estudante(TipoEstudante *estudante, TipoLabirinto *labirinto, TipoAnalise *analise, int caminho[labirinto->linhas][labirinto->colunas], int x, int y, int chave[labirinto->linhas][labirinto->colunas]){
	int i, j, cont = 0, qtdChave;
	estudante->pAtual.x = x;
	estudante->pAtual.y = y;

    if ((x >= 0) && (x < labirinto->linhas) && (y >= 0) && (y < labirinto->colunas) && (labirinto->espaco[x][y] != '2') && (caminho[x][y] == 0)){

		//tenta movimentar para cima
		if (movimenta_estudante(estudante, labirinto, analise, caminho, x - 1, y, chave)){
			return 1;
		}
		//tenta movimentar para direita
		if (movimenta_estudante(estudante, labirinto, analise, caminho, x, y + 1, chave)){
			return 1;
		}
		//tenta movimentar para esquerda
		if (movimenta_estudante(estudante, labirinto, analise, caminho, x, y - 1, chave)){
			return 1;
		}
		//tenta movimentar para baixo
		if (movimenta_estudante(estudante, labirinto, analise, caminho, x + 1, y, chave)){
			return 1;
		}
		return 0;
	}

	return 0;
}

//funcoes para testes
void imprimir(TipoPiramide *piramide){//imprimi os valores lidos no arquivo
    int i, j;
    for (i = 0; i < piramide->qtdLinhas; i++) {
        for (j = 0; j <=i; j++) {
            printf("\t%d ", piramide->espaco[i][j]);
        }
        printf ("\n");
    }
}

