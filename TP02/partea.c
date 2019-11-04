#include "partea.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
int lerArquivo(TipoPiramide *piramide, char *nomeArquivo){//le o arquivo
	int num, i, j, qtdLinhas, aux = 0;
	FILE *arquivo;
    char caminhoArquivo[150];
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
                    fscanf(arquivo, "%d ", &num); //le o que tem na posicao
                    piramide->espaco[i][j] = num; //preenche o labirinto
                }
            }
        }
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
            	caracter = rand()%100;
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

int piramideRecursiva(TipoPiramide *piramide, TipoAnalise *analise, int caminho[piramide->qtdLinhas][piramide->qtdLinhas], int linha, int coluna){//piramide recursiva
	int baixo = 0, direita = 0;
	
	if (linha == piramide->qtdLinhas - 1){
		return piramide->espaco[linha][coluna];
	}
	
	baixo = piramideRecursiva(piramide, analise, caminho, linha + 1, coluna + 1);
	direita = piramideRecursiva (piramide, analise, caminho, linha + 1, coluna);
	analise->qtdChamadaRecursiva = analise->qtdChamadaRecursiva + 2; //uma chamada para baixo e outra para direita
	
	if (baixo>=direita){
		caminho[linha][coluna] = baixo + piramide->espaco[linha][coluna];
		return (baixo + piramide->espaco[linha][coluna]); 
	}else{
		caminho[linha][coluna] = direita + piramide->espaco[linha][coluna];
		return (direita + piramide->espaco[linha][coluna]);
	}
}

//funcoes auxiliares
void solucao(TipoPiramide *piramide, TipoAnalise *analise, int tipo, int modoAnalise){
	int soma = 0, i, j;
	int caminho[piramide->qtdLinhas][piramide->qtdLinhas];
	clock_t tempo;
	analise->tempoTotal = 0;
	analise->memoria = 0;
	
	//memoria utilizada na matriz usada para piramide
    for (i= 0; i < piramide->qtdLinhas; i++){
    	analise->memoria = (piramide->qtdLinhas * sizeof(int)) + analise->memoria;	
	}
	
	if (tipo == 1){
		//inicializacao da matriz caminho
		for (i = 0; i < piramide->qtdLinhas; i++){ 
			for (j = 0; j <= i; j++) {
	            caminho[i][j] = 0;
	        }
	    }	
	    
	    //memoria utilizada na matriz caminho
	    for (i= 0; i < piramide->qtdLinhas; i++){
	    	analise->memoria = (piramide->qtdLinhas * sizeof(int)) + analise->memoria;	
		}
			    	    
	    tempoInicial(&tempo);
		soma = piramideRecursiva(piramide, analise, caminho, 0, 0);
		analise->tempoTotal = tempoFinalizado(tempo);
		if (modoAnalise == modoDebug){
			printf ("\nMaior soma possivel: %d\n", soma);
			caminhoPercorrido (piramide, caminho, analise);
			analise->memoria = (analise->qtdChamadaRecursiva * sizeof(int)) + analise->memoria;
			printf("\nTamanho da piramide", piramide->qtdLinhas);
			printf("\nTempo total gasto para a solucao: %.10lf ms", analise->tempoTotal);
			printf ("\nQuantidade de chamadas recursivas: %d", analise->qtdChamadaRecursiva);
			printf ("\nQuantidade de memoria utilizada: %d", analise->memoria);
			printf ("\n");
		}else{
			printf ("\nMaior soma possivel: %d\n", soma);
			caminhoPercorrido (piramide, caminho, analise);
			printf ("\n");
		}	
	}
}

void caminhoPercorrido (TipoPiramide *piramide, int caminho[piramide->qtdLinhas][piramide->qtdLinhas], TipoAnalise *analise){
	int i, j, coluna = 0, caminhoPercorrido[piramide->qtdLinhas][piramide->qtdLinhas];
	
	caminho[0][0] = piramide->espaco[0][0]; //inicializa a primeira linha do caminho
	for (j = 0; j < piramide->qtdLinhas; j++) { //inicializa a ultima linha do caminho 
        caminho[piramide->qtdLinhas - 1][j] = piramide->espaco [piramide->qtdLinhas - 1][j];
    }
	
	//inicializacao da matriz que e utilizada para verificar o caminho percorrido
	for (i = 0; i < piramide->qtdLinhas; i++){
		for (j = 0; j <= i; j++) {
            caminhoPercorrido[i][j] = 0;
        }
    }
    
    //memoria utilizada na matriz caminhoPercorrido
    for (i= 0; i < piramide->qtdLinhas; i++){
    	analise->memoria = (piramide->qtdLinhas * sizeof(int)) + analise->memoria;	
	}
        
    for (i = 0; i < piramide->qtdLinhas; i++){ //coloca 1 no celula que foi utilizada na soma
    	caminhoPercorrido[0][0] = 1;				
		if(caminho[i+1][coluna]>caminho[i+1][coluna+1]){
			caminhoPercorrido[i+1][coluna] = 1;
		}else{
			caminhoPercorrido[i+1][coluna+1] = 1;
			coluna++;
		}
	}
    
	printf ("Caminho percorrido: "); //imprimi o caminho percorrido
	for (i = 0; i < piramide->qtdLinhas; i++) {
        for (j = 0; j <= i; j++){
            if (caminhoPercorrido[i][j] == 1){
				printf ("%d", piramide->espaco[i][j]);
			}
			if (caminhoPercorrido[i][j] == 1 && i < piramide->qtdLinhas - 1){//nao deixa imprimir -> depois que nao tiver mais numeros
				printf (" -> ");
			}
    	}
    }
}

void tempoInicial(clock_t *tempo){
    *tempo = clock();
}

double tempoFinalizado(clock_t tempo){
    clock_t tempoFinal;    
    tempoFinal = clock();    
    return (double)((tempoFinal - tempo)* 1000.0)/CLOCKS_PER_SEC; 
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

