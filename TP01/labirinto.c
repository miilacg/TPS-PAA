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
    labirinto->espaco = (char **) malloc(labirinto->linhas * sizeof(char *));
    for (i = 0; i < labirinto->linhas; i++) {
        labirinto->espaco[i] = (char *) malloc(labirinto->colunas * sizeof(char));
    }
}

//le o arquivo para saber o desenho do labirinto e posicao do estudante
int lerArquivo(TipoLabirinto *labirinto, char *nomeArquivo){
	FILE *arquivo;
    char caminhoArquivo[150], cor;
    int i, j, linhas, colunas, chaves;
    strcpy(caminhoArquivo, "C:\\Users\\Camila\\Desktop\\Camila\\Trabalho\\Superior\\PAA\\TPS-PAA\\TP01\\"); //caminho ate o arquivo
    strcat(caminhoArquivo, nomeArquivo); //nome do arquivo recebido pelo usuario
    strcat(caminhoArquivo, ".txt");
    arquivo = fopen(caminhoArquivo, "r"); //une as partes que compoem o caminhoArquivo
    if (arquivo == NULL) {
        printf("\nErro de leitura do arquivo\n");
        return 0; //retorna 0 caso nao seja possivel ler o arquivo
    }else{
        fscanf(arquivo, "%d %d %d\n", &linhas, &colunas, &chaves); //faz a lelitura de quantas linhas, colunas e chave tem no arquivo
        labirinto->linhas = linhas;
        labirinto->colunas = colunas;
        labirinto->chaves = chaves;
        alocaEspaco(labirinto); //chama a funcao que faz a alocao do espaco para o labirinto
        while (!feof(arquivo)) { //enquanto nao for o fim do arquivo
            for (i = 0; i < labirinto->linhas; i++) { //percorre o arquivo
                for (j = 0; j < labirinto->colunas; j++) {
                    fscanf(arquivo, "%c ", &cor); //le o que tem na posicao
                    labirinto->espaco[i][j] = cor; //preenche o labirinto
                }
            }
        }
	}
    fclose(arquivo);
    return 1; //retorna 1 se a leitura for feita com sucesso
}

//encontrar a posicao do estudante e movimenta ele atraves de chamadas recursivas
int movimenta_estudante(TipoEstudante *estudante, TipoLabirinto *labirinto, TipoAnalise *analise, int caminho[labirinto->linhas][labirinto->colunas], int x, int y, int chave[labirinto->linhas][labirinto->colunas]){
	int i, j, cont = 0, qtdChave;
	estudante->pAtual.x = x;
	estudante->pAtual.y = y;

	analise->maxAux++;
	analise->qtdChamadaRecursiva++;

	for (i = 0; i < labirinto->linhas; i++) { //for usado para contar quantas chaves tem na matriz chave
        for (j = 0; j < labirinto->colunas; j++) {
            if (chave[i][j] == 1) {
                cont++; //quantidade de chaves que eu ja foi usada
            }
        }
    }

	qtdChave = labirinto->chaves - cont;

    //se chegar na primeira linha do labirinto
	if (estudante->pAtual.x == 0 && labirinto->espaco[x][y] != '2'){
		if (labirinto->espaco[x][y] == '3'){ //verifica se a posicao e uma porta
    		if (qtdChave > 0){ //verifica se tem chave suficiente
    			chave[x][y] = 1;
				estudante->pFinal.x = x;
				estudante->pFinal.y = y;
				analise->qtdMovimento++;
				printf("Linha: %d Coluna: %d\n", estudante->pFinal.x, estudante->pFinal.y); //imprime a posicao final do estudante
				return 1;
			}
			return 0;
		}

		estudante->pFinal.x = x;
		estudante->pFinal.y = y;
		analise->qtdMovimento++;
		printf("Linha: %d Coluna: %d\n", estudante->pFinal.x, estudante->pFinal.y);
		return 1;
	}

    //se ainda nao for a primeira linha do labirinto
    //verifica se o estudante ira se movimentar para um espaco dentro do labirinto, que nao seja parede e que ainda nao tenha sido percorrido
    if ((x >= 0) && (x < labirinto->linhas) && (y >= 0) && (y < labirinto->colunas) && (labirinto->espaco[x][y] != '2') && (caminho[x][y] == 0)){
    	caminho[x][y] = 1; //informa que já passou pelo caminho
    	analise->qtdMovimento++;
    	printf("Linha: %d Coluna: %d\n", x, y);//imprime a posicao que o estudante passou

    	if (labirinto->espaco[x][y] == '3'){ //verifica se a posicao e uma porta
    		if (qtdChave > 0){ //verifica se tem chave suficiente
    			chave[x][y] = 1; //informa que usou uma chave
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
				chave[x][y] = 0; //recebe 0 caso tenha que voltar pela porta
			}
			return 0;
		}

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


	if (analise->nivelMaximo < analise->maxAux){
        /*garante que sera informado a maior quantidade de vezes
        que foi feita chamada recursiva sem ter que voltar*/
		analise->nivelMaximo = analise->maxAux;
	}

	analise->maxAux = 0; //se precisar voltar a contagem e zerada
	return 0;
}

int inicializacoes(TipoLabirinto *labirinto, TipoEstudante *estudante, TipoAnalise *analise, int opcao){
    int i, j, x, y;
    int caminho[labirinto->linhas][labirinto->colunas];
    int chave[labirinto->linhas][labirinto->colunas];

    //inicializa posicao
    for (i = 0; i < labirinto->linhas; i++) {
        for (j = 0; j < labirinto->colunas; j++) {
            if (labirinto->espaco[i][j] == '0') {//se a posicao for a do estudante
                estudante->pInicial.x = i;
                estudante->pInicial.y = j;
                estudante->pAtual.x = i;
                estudante->pAtual.y = j;
                estudante->pFinal.x = 0;
                estudante->pFinal.y = 0;
                //x e y sao usados para enviar para as funcoes que movimentam o estudante
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

	//inicializa chaves
    for (i = 0; i < labirinto->linhas; i++) {
        for (j = 0; j < labirinto->colunas; j++){
            chave[i][j] = 0;
    	}
    }

    //inicializa analise
    analise->qtdChamadaRecursiva = -1; //inicializa com -1 pois a primeira chamada nao e recursiva
	analise->qtdMovimento = -1; //no primeiro teste nao ocorre movimento
	analise->nivelMaximo = -1; //inicializa com -1 pois a primeira chamada nao e recursiva
	analise->maxAux = 0;

    //dependendo da escolha do usuario uma funcao de movimentar e escolhida
    if (opcao == 1){
		return (movimenta_estudante(estudante, labirinto, analise, caminho, x, y, chave));
	}else{
		if (opcao == 2){
			return (movimentaEstudanteExtra(estudante, labirinto, analise, caminho, x, y, chave));
		}
	}
}

//aceita que o estudante encontra chaves no chao caso passe pelo caminho
//o estudante nao perde se passar por ele de novo
int movimentaEstudanteExtra(TipoEstudante *estudante, TipoLabirinto *labirinto, TipoAnalise *analise, int caminho[labirinto->linhas][labirinto->colunas], int x, int y, int chave[labirinto->linhas][labirinto->colunas]){
	int i, j, perde = 0, ganha = 0, qtdChave;
	estudante->pAtual.x = x;
	estudante->pAtual.y = y;

	analise->maxAux++;
	analise->qtdChamadaRecursiva++;

	for (i = 0; i < labirinto->linhas; i++) { //for usado para contar quantas chaves tem na matriz chave
        for (j = 0; j < labirinto->colunas; j++) {
            if (chave[i][j] == 1) {
                perde++; //quantidade de chaves que eu já usei
            }
            if (chave[i][j] == 2) {
                ganha++; //quantidade de chaves que eu peguei
            }
        }
    }

	qtdChave = (labirinto->chaves - perde) + ganha; //quantidade de chaves que o estudante tem no momento

    //se chegar na primeira linha do labirinto
	if (estudante->pAtual.x == 0 && labirinto->espaco[x][y] != '2'){//nao importa pegar uma chave na ultima linha
		if (labirinto->espaco[x][y] == '3'){ //verifica se a posicao e uma porta
    		if (qtdChave > 0){ //verifica se tem chave suficiente
    			chave[x][y] = 1;
				estudante->pFinal.x = x;
				estudante->pFinal.y = y;
				analise->qtdMovimento++;
				printf("Linha: %d Coluna: %d\n", estudante->pFinal.x, estudante->pFinal.y);
				printf ("Chaves: %d", qtdChave);
				return 1;
			}
			return 0;
		}

		estudante->pFinal.x = x;
		estudante->pFinal.y = y;
		analise->qtdMovimento++;
		printf("Linha: %d Coluna: %d\n", estudante->pFinal.x, estudante->pFinal.y);
		return 1;
	}

    //verifica se o estudante ira se movimentar para um espaco dentro do labirinto, que nao seja parede e que ainda nao tenha sido percorrido
    if ((x >= 0) && (x < labirinto->linhas) && (y >= 0) && (y < labirinto->colunas) && (labirinto->espaco[x][y] != '2') && (caminho[x][y] == 0)){
    	caminho[x][y] = 1; //informa que já passou pelo caminho
    	analise->qtdMovimento++;
    	printf("Linha: %d Coluna: %d\n", x, y);

    	if (labirinto->espaco[x][y] == '4'){ //verifica se a posicao tem uma chave
			chave[x][y] = 2; //informa que recebeu uma chave
			//tenta movimentar para cima
			if (movimentaEstudanteExtra(estudante, labirinto, analise, caminho, x - 1, y, chave)){
				return 1;
			}
			//tenta movimentar para direita
			if (movimentaEstudanteExtra(estudante, labirinto, analise, caminho, x, y + 1, chave)){
				return 1;
			}
			//tenta movimentar para esquerda
			if (movimentaEstudanteExtra(estudante, labirinto, analise, caminho, x, y - 1, chave)){
				return 1;
			}
			//tenta movimentar para baixo
			if (movimentaEstudanteExtra(estudante, labirinto, analise, caminho, x + 1, y, chave)){
				return 1;
			}
		}

    	if (labirinto->espaco[x][y] == '3'){ //verifica se a posicao e uma porta
    		if (qtdChave > 0){ //verifica se tem chave suficiente
    			chave[x][y] = 1; //informa que usou uma chave
    			//tenta movimentar para cima
				if (movimentaEstudanteExtra(estudante, labirinto, analise, caminho, x - 1, y, chave)){
					return 1;
				}
				//tenta movimentar para direita
				if (movimentaEstudanteExtra(estudante, labirinto, analise, caminho, x, y + 1, chave)){
					return 1;
				}
				//tenta movimentar para esquerda
				if (movimentaEstudanteExtra(estudante, labirinto, analise, caminho, x, y - 1, chave)){
					return 1;
				}
				//tenta movimentar para baixo
				if (movimentaEstudanteExtra(estudante, labirinto, analise, caminho, x + 1, y, chave)){
					return 1;
				}
				chave[x][y] = 0; //recebe 0 caso tenha que voltar pela porta
			}
			return 0;
		}

		//tenta movimentar para cima
		if (movimentaEstudanteExtra(estudante, labirinto, analise, caminho, x - 1, y, chave)){
			return 1;
		}
		//tenta movimentar para direita
		if (movimentaEstudanteExtra(estudante, labirinto, analise, caminho, x, y + 1, chave)){
			return 1;
		}
		//tenta movimentar para esquerda
		if (movimentaEstudanteExtra(estudante, labirinto, analise, caminho, x, y - 1, chave)){
			return 1;
		}
		//tenta movimentar para baixo
		if (movimentaEstudanteExtra(estudante, labirinto, analise, caminho, x + 1, y, chave)){
			return 1;
		}
		return 0;
	}

	if (analise->nivelMaximo < analise->maxAux){
		analise->nivelMaximo = analise->maxAux;
	}
	analise->maxAux = 0;
	return 0;
}

//funcao extra para escrever um arquivo
int geraLabirinto(int linhas, int colunas, int qtdChaves, int qtdPortas, int qtdParedes){
    int i, j, linha, coluna;
    int labirinto[linhas][colunas];
    FILE *arquivo;

    arquivo = fopen("C:\\Users\\Camila\\Desktop\\Camila\\Trabalho\\Superior\\PAA\\TPS-PAA\\TP01\\Arquivo-Teste.txt", "w+"); //caminho e nome do arquivo que sera escrito
    if (arquivo == NULL){
        printf("\nErro\n");
	}else{ //se o arquivo for criado com sucesso
        fprintf(arquivo, "%d %d %d \n", linhas, colunas, qtdChaves);//escrevendo a primeira linha do arquivo

        //inicializando todas as posicoes com 1
        for (i = 0; i < linhas; i++) {
            for (j = 0; j < colunas; j++) {
                labirinto[i][j] = 1;
            }
        }

        linha = rand() % linhas;
        coluna = rand() % colunas;
        labirinto[linha][coluna] = 0; //inicializacao do estudante

        for (i = 0; i < qtdParedes; i++) {
        	while (labirinto[linha][coluna] != 1){ // nao deixa inserir onde ja tem uma parede, porta ou estudante
        		linha = rand()%linhas;
            	coluna = rand()%colunas;
        	}
        	labirinto[linha][coluna] = 2; //inicializando as paredes
        }

        for (i = 0; i < qtdPortas; i++) {
        	while (labirinto[linha][coluna] != 1){ // nao deixa inserir onde ja tem uma parede, porta ou estudante
        		linha = rand()%linhas;
            	coluna = rand()%colunas;
        	}
			labirinto[linha][coluna] = 3; //inicializando as portas
        }


        for (i = 0; i < linhas; i++) { //escreve no arquivo o que esta na matriz
            for (j = 0; j < colunas; j++) {
                fprintf(arquivo, "%d", labirinto[i][j]);
            }
            fprintf(arquivo, "\n");
        }
    }
    fclose(arquivo); //fecha o arquivo depois de escrever
    return 1;
}

//funcoes para testes
void imprimir(TipoLabirinto *labirinto){//imprimi os valores lidos no arquivo
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

void imprimirMatriz(TipoLabirinto *labirinto, int matriz[labirinto->linhas][labirinto->colunas]) { //imprimi alguma matriz para teste
    int i, j;
    printf("\n\n");
    printf("  ");
    for (j = 0; j < labirinto->colunas; j++){
        printf("\t%d ", j);
	}

    for (i = 0; i < labirinto->linhas; i++) {
        printf("\n\n%d ", i);
        for (j = 0; j < labirinto->colunas; j++) {
            printf("\t%d ", matriz[i][j]);
        }
    }
    printf ("\n");
}
