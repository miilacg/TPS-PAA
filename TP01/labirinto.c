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

void imprimir(TipoLabirinto *labirinto){
    int i, j;
    
    printf("  ");
    for (j = 0; j < labirinto->colunas; j++){
        printf("\t%d ", j);
	}
        
    for (i = 0; i < labirinto->linhas; i++) {
    	printf("\n\n%d ", i);
        for (j = 0; j < labirinto->colunas; j++) {
            printf("\t%c ", labirinto->espaco[i][j]);
        }
    }
}

//encontrar a posicao do estudante e depois chamar essa funcao uma unica vez
int movimenta_estudante(TipoEstudante *estudante, TipoLabirinto *labirinto, TipoAnalise *analise, int x, int y, int caminho[labirinto->linhas][labirinto->colunas]){
	estudante->pAtual.x = x;
    estudante->pAtual.y = y;
    
    analise->qtdChamadaRecursiva++;
    analise->nivelMaximo++;

    //caso o estudante chegue na primeira linha retorna 1 (encontrou a solucao) e encerra
    if (estudante->pAtual.x == 0) {
    	printf("Linha: %d Coluna: %d\n", x, y);
        estudante->pFinal.x = x;
        estudante->pFinal.y = y;
        caminho[x][y] = 1;
        return 1;
    }
    
    if ((x > 0) && (y >= 0) && (x < labirinto->linhas) && (y < labirinto->colunas) && (caminho[x][y] == 0) && (labirinto->espaco[x][y] != '2')){
    	caminho[x][y] = 1; //seta para 1 o caminho
    	
    	//Tenta movimentar para cima 
    	if (labirinto->espaco[x-1][y] == '3'){
    		if (labirinto->chaves >= 1){
		        if (movimenta_estudante(estudante, labirinto, analise, x-1, y, caminho)){
		        	printf("Linha: %d Coluna: %d\n", x, y);
        			analise->qtdMovimento++;
		        	labirinto->chaves--;
					return 1;
				}
			}
		}			
		if (labirinto->espaco[x-1][y] == '1'){
			if (movimenta_estudante(estudante, labirinto, analise, x-1, y, caminho)){
				printf("Linha: %d Coluna: %d\n", x, y);
        		analise->qtdMovimento++;
				return 1;
			}	
		}

		//Tenta movimentar para esquerda
		if (labirinto->espaco[x][y-1] == '3'){
    		if (labirinto->chaves >= 1){
		        if (movimenta_estudante(estudante, labirinto, analise, x, y-1, caminho)){
		        	printf("Linha: %d Coluna: %d\n", x, y);
        			analise->qtdMovimento++;
		        	labirinto->chaves--;
					return 1;
				}
			}
		}			
		if (labirinto->espaco[x][y-1] == '1'){
			if (movimenta_estudante(estudante, labirinto, analise, x, y-1, caminho)){
				printf("Linha: %d Coluna: %d\n", x, y);
        		analise->qtdMovimento++;
				return 1;
			}	
		}
		
		//Tenta movimentar para direita
		if (labirinto->espaco[x][y+1] == '3'){
    		if (labirinto->chaves >= 1){ 
		        if (movimenta_estudante(estudante, labirinto, analise, x, y+1, caminho)){
		        	printf("Linha: %d Coluna: %d\n", x, y);
        			analise->qtdMovimento++;
		        	labirinto->chaves--;
					return 1;
				}	
			}
		}
		if (labirinto->espaco[x][y+1] == '1'){
			if (movimenta_estudante(estudante, labirinto, analise, x, y+1, caminho)){
				printf("Linha: %d Coluna: %d\n", x, y);
        		analise->qtdMovimento++;
				return 1;
			}
		}
		
		//Tenta movimentar para baixo	
		if (labirinto->espaco[x+1][y] == '3'){
    		if (labirinto->chaves >= 1){
		        if (movimenta_estudante(estudante, labirinto, analise, x+1, y, caminho)){
		        	printf("Linha: %d Coluna: %d\n", x, y);
        			analise->qtdMovimento++;
		        	labirinto->chaves--;
					return 1;
				}
			}
		}
		if (labirinto->espaco[x+1][y] == '1'){
			if (movimenta_estudante(estudante, labirinto, analise, x+1, y, caminho)){
				printf("Linha: %d Coluna: %d\n", x, y);
        		analise->qtdMovimento++;
				return 1;
			}
		}
		
        // Memoriza o caminho e ativa o backtracking quando a tentativa de caminhar falha. 
        caminho[x][y] = 0;
        analise->nivelMaximo = 0;
        return 0;		
	}
	return 0;  
} 

int inicializacoes(TipoLabirinto *labirinto, TipoEstudante *estudante, TipoAnalise *analise){
    int i, j, x, y;
    int caminho[labirinto->linhas][labirinto->colunas];
    
    //inicializa posicao
    for (i = 0; i < labirinto->linhas; i++) {
        for (j = 0; j < labirinto->colunas; j++) {
            if (labirinto->espaco[i][j] == '0') {//se a posicao for o que o estudante 
                estudante->pInicial.x = i;
                estudante->pInicial.y = j;
                estudante->pAtual.x = i;
                estudante->pAtual.y = j;
                estudante->pFinal.x = 0;
                estudante->pFinal.y = 0;
                x = estudante->pAtual.x;
                y = estudante->pAtual.y;
            }
        }
    }
    
    //inicializa caminho
    for (i = 0; i < labirinto->linhas; i++) {
        for (j = 0; j < labirinto->colunas; j++){
            caminho[i][j] = 0;
    	}
    }
    
    //inicializa analise
    analise->qtdChamadaRecursiva = -1; //inicializa com -1 pois a primeira chamada nao e recursiva
	analise->qtdMovimento = 0;
	analise->nivelMaximo = -1; //inicializa com -1 pois a primeira chamada nao e recursiva
    
    // Verifica se o problema tem solucao
    return movimenta_estudante(estudante, labirinto, analise, x, y, caminho);
}

void imprimirSolucao(TipoLabirinto *labirinto, int caminho[labirinto->linhas][labirinto->colunas]) {
    int i, j;
    printf("\n\n");
    printf("  ");
    for (j = 0; j < labirinto->colunas; j++)
        printf("\t%d ", j);

    for (i = 0; i < labirinto->linhas; i++) {
        printf("\n\n%d ", i);
        for (j = 0; j < labirinto->colunas; j++) {
            printf("\t%d ", caminho[i][j]);
        }
    }
}
