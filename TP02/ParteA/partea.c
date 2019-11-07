#include "partea.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int piramideRecursiva(TipoPiramide *piramide, TipoAnalise *analise, int caminho[piramide->qtdLinhas][piramide->qtdLinhas], int linha, int coluna){//piramide recursiva
	int baixo = 0, direita = 0;

	if (linha < piramide->qtdLinhas - 1 && coluna <= linha){
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
	}else{
		//printf ("%d", coluna);
		return (piramide->espaco[linha][coluna]);
	}
}

int piramideMemoization(TipoPiramide *piramide, TipoAnalise *analise, int caminho[piramide->qtdLinhas][piramide->qtdLinhas], int linha, int coluna){//piramide com memoization
	int baixo = 0, direita = 0;

    if(linha == piramide->qtdLinhas - 1){ //ultima linha
        return (piramide->espaco[linha][coluna]);
    }

    if(caminho[linha + 1][coluna] == 0){
        baixo = piramideMemoization(piramide, analise, caminho, linha + 1, coluna);
		analise->qtdChamadaRecursiva ++;
    } else{
        baixo = caminho[linha + 1][coluna];
    }
    if(caminho[linha + 1][coluna + 1] == 0){
        direita = piramideMemoization(piramide, analise, caminho, linha + 1, coluna + 1);
        analise->qtdChamadaRecursiva ++;
    } else{
        direita = caminho[linha + 1][coluna + 1];
    }

    if(baixo>=direita){
        caminho[linha][coluna] = piramide->espaco[linha][coluna] + baixo;
		return caminho[linha][coluna];
    } else{
        caminho[linha][coluna] = piramide->espaco[linha][coluna] + direita;
		return caminho[linha][coluna];
    }
}

int piramideIterativa(TipoPiramide *piramide, int caminho[piramide->qtdLinhas][piramide->qtdLinhas]){//piramide de tras pra frente
	int baixo, direita, i, j;

	for(i = 0; i < piramide->qtdLinhas; i++){
        for(j = 0; j <= i; j++){
            caminho[i][j] = piramide->espaco[i][j];
        }
    }

    for(i = piramide->qtdLinhas - 2; i >= 0; i--){
        for(j = 0; j <= i; j++){
            baixo = caminho[i+1][j];
            direita = caminho[i+1][j+1];
            if (baixo>=direita){
            	caminho[i][j] = caminho[i][j] + baixo;
			}else{
				caminho[i][j] = caminho[i][j] + direita;
			}
        }
    }
    return caminho[0][0];
}

//funcoes auxiliares
int lerArquivo(TipoPiramide *piramide, char *nomeArquivo){//le o arquivo
	int num, i, j, qtdLinhas, aux = 0;
	FILE *arquivo;
    char caminhoArquivo[150];
    strcpy(caminhoArquivo, "C:\\Users\\Camila\\Desktop\\Camila\\Trabalho\\Superior\\PAA\\TPS-PAA\\TP02\\ParteA\\"); //caminho ate o arquivo
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

void alocaEspaco(TipoPiramide *piramide){//aloca o espaco necessario para a piramide e para matriz caminhoPercorrido
	int i;

	//alocando espaco para piramide
    piramide->espaco = (int **) malloc(piramide->qtdLinhas * sizeof(int *));
    for (i = 0; i < piramide->qtdLinhas; i++) {
        piramide->espaco[i] = (int *) malloc(piramide->qtdLinhas * sizeof(int));
    }

    //alocando espaco para a matriz caminho percorrido
	piramide->caminhoPercorrido = (int **) malloc(piramide->qtdLinhas * sizeof(int *));
    for (i = 0; i < piramide->qtdLinhas; i++) {
        piramide->caminhoPercorrido[i] = (int *) malloc(piramide->qtdLinhas * sizeof(int));
    }
}

int contaLinhas(TipoPiramide *piramide, char *nomeArquivo){//retorna a altura da piramide
	int qtdLinhas = 1;
	char comparacao;
	FILE *arq;
    char caminhoArquivo[150];
    strcpy(caminhoArquivo, "C:\\Users\\Camila\\Desktop\\Camila\\Trabalho\\Superior\\PAA\\TPS-PAA\\TP02\\ParteA\\"); //caminho ate o arquivo
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
	strcpy(caminhoArquivo, "C:\\Users\\Camila\\Desktop\\Camila\\Trabalho\\Superior\\PAA\\TPS-PAA\\TP02\\ParteA\\"); //caminho ate o arquivo
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

void solucao(TipoPiramide *piramide, TipoAnalise *analise, int tipo, int modoAnalise){
	int i, j, soma = 0;
	int caminho[piramide->qtdLinhas][piramide->qtdLinhas];
	clock_t tempo;
	//inicializacao das variaveis de analise
	analise->tempoSoma = 0;
	analise->tempoCaminho = 0;
	analise->memoriaSoma = 0;
	analise->memoriaCaminho = 0;
	analise->qtdChamadaRecursiva = 0;

	//memoria utilizada na matriz usada para piramide
    for (i= 0; i < piramide->qtdLinhas; i++){
    	analise->memoriaSoma = (piramide->qtdLinhas * sizeof(int)) + analise->memoriaSoma;
	}

	//inicializacao da matriz caminho
	for (i = 0; i < piramide->qtdLinhas; i++){
		for (j = 0; j <= i; j++) {
            caminho[i][j] = 0;
        }
    }
    system("cls");
	if (tipo == 1){//recursivo
		//memoria utilizada na matriz caminho
		//essa matriz e uma auxiliar para impressao da rota
	    for (i= 0; i < piramide->qtdLinhas; i++){
	    	analise->memoriaCaminho = (piramide->qtdLinhas * sizeof(int)) + analise->memoriaCaminho;
		}
	    tempoInicial(&tempo);
		soma = piramideRecursiva(piramide, analise, caminho, 0, 0);
		analise->tempoSoma = tempoFinalizado(tempo);
		analise->memoriaSoma = (analise->qtdChamadaRecursiva * sizeof(int)) + analise->memoriaSoma; //memoria utilizada nas chamadas recursivas
		if (modoAnalise == modoDebug){
			printf ("\n ********************************************** Modo analise ativo **********************************************\n\n");
			printf (" Implementacao escolhida: Recursiva");
			printf ("\n Maior soma possivel: %d\n", soma);
			tempoInicial(&tempo);
			caminhoPercorrido(piramide, caminho, analise);
			analise->tempoCaminho = tempoFinalizado(tempo);
			printf (" Caminho percorrido: "); //imprimi o caminho percorrido
			for (i = 0; i < piramide->qtdLinhas; i++) {
		        for (j = 0; j <= i; j++){
		            if (piramide->caminhoPercorrido[i][j] == 1){
						printf ("%d", piramide->espaco[i][j]);
					}
					if (piramide->caminhoPercorrido[i][j] == 1 && i < piramide->qtdLinhas - 1){//nao deixa imprimir -> depois que nao tiver mais numeros
						printf (" -> ");
					}
		    	}
		    }
		    printf ("\n");
			printf("\n Tamanho da piramide: %d", piramide->qtdLinhas);
			printf("\n Tempo utilizado para encontrar a maior soma: %.5lf ms", analise->tempoSoma);
			printf("\n Tempo utilizado para informar a rota: %.5lf ms", analise->tempoCaminho);
			printf("\n Tempo total utilizado: %.5lf ms", analise->tempoSoma + analise->tempoCaminho);
			printf ("\n Quantidade de chamadas recursivas: %.1lf", analise->qtdChamadaRecursiva);
			printf ("\n Quantidade de memoria utilizada para somar: %.1lf", analise->memoriaSoma);
			printf ("\n Quantidade de memoria utilizada para mostrar a rota: %.1lf", analise->memoriaCaminho);
			printf ("\n Quantidade de memoria total utilizada: %.1lf", analise->memoriaCaminho + analise->memoriaSoma);
			printf ("\n");
		}else{
			printf ("\n ********************************************** Modo analise desativado **********************************************\n\n");
			printf (" Implementacao escolhida: Recursiva");
			printf ("\n Maior soma possivel: %d\n", soma);
			caminhoPercorrido(piramide, caminho, analise);
			printf (" Caminho percorrido: "); //imprimi o caminho percorrido
			for (i = 0; i < piramide->qtdLinhas; i++) {
		        for (j = 0; j <= i; j++){
		            if (piramide->caminhoPercorrido[i][j] == 1){
						printf ("%d", piramide->espaco[i][j]);
					}
					if (piramide->caminhoPercorrido[i][j] == 1 && i < piramide->qtdLinhas - 1){//nao deixa imprimir -> depois que nao tiver mais numeros
						printf (" -> ");
					}
		    	}
		    }
		    printf ("\n");
			printf ("\n");
		}
	}

	if (tipo == 2){//Memoization
		//memoria utilizada na matriz caminho
		//a matriz utilizada para calcular soma e imprimir rota
	    for (i= 0; i < piramide->qtdLinhas; i++){
	    	analise->memoriaSoma = (piramide->qtdLinhas * sizeof(int)) + analise->memoriaSoma;
		}

	    tempoInicial(&tempo);
		soma = piramideMemoization(piramide, analise, caminho, 0, 0);
		analise->tempoSoma = tempoFinalizado(tempo);
		analise->memoriaSoma = (analise->qtdChamadaRecursiva * sizeof(int)) + analise->memoriaSoma; //memoria utilizada nas chamadas recursivas
		if (modoAnalise == modoDebug){
			printf ("\n ********************************************** Modo analise ativo **********************************************\n\n");
			printf (" Implementacao escolhida: Memoization");
			printf ("\n Maior soma possivel: %d\n", soma);
			tempoInicial(&tempo);
			caminhoPercorrido(piramide, caminho, analise);
			analise->tempoCaminho = tempoFinalizado(tempo);
			printf (" Caminho percorrido: "); //imprimi o caminho percorrido
			for (i = 0; i < piramide->qtdLinhas; i++) {
		        for (j = 0; j <= i; j++){
		            if (piramide->caminhoPercorrido[i][j] == 1){
						printf ("%d", piramide->espaco[i][j]);
					}
					if (piramide->caminhoPercorrido[i][j] == 1 && i < piramide->qtdLinhas - 1){//nao deixa imprimir -> depois que nao tiver mais numeros
						printf (" -> ");
					}
		    	}
		    }
		    printf ("\n");
		    printf ("\n");
			printf("\n Tamanho da piramide: %d", piramide->qtdLinhas);
			printf("\n Tempo utilizado para encontrar a maior soma: %.5lf ms", analise->tempoSoma);
			printf("\n Tempo utilizado para informar a rota: %.5lf ms", analise->tempoCaminho);
			printf("\n Tempo total utilizado: %.5lf ms", analise->tempoSoma + analise->tempoCaminho);
			printf("\n Quantidade de chamadas recursivas: %.1lf", analise->qtdChamadaRecursiva);
			printf ("\n Quantidade de memoria utilizada para somar: %.1lf", analise->memoriaSoma);
			printf ("\n Quantidade de memoria utilizada para mostrar a rota: %.1lf", analise->memoriaCaminho);
			printf ("\n Quantidade de memoria total utilizada: %.1lf", analise->memoriaCaminho + analise->memoriaSoma);
			printf("\n");
		}else{
			printf ("\n ********************************************** Modo analise desativado **********************************************\n\n");
			printf (" Implementacao escolhida: Memoization");
			printf ("\n Maior soma possivel: %d\n", soma);
			printf (" Caminho percorrido: "); //imprimi o caminho percorrido
			caminhoPercorrido(piramide, caminho, analise);
			for (i = 0; i < piramide->qtdLinhas; i++) {
		        for (j = 0; j <= i; j++){
		            if (piramide->caminhoPercorrido[i][j] == 1){
						printf ("%d", piramide->espaco[i][j]);
					}
					if (piramide->caminhoPercorrido[i][j] == 1 && i < piramide->qtdLinhas - 1){//nao deixa imprimir -> depois que nao tiver mais numeros
						printf (" -> ");
					}
		    	}
		    }
		    printf ("\n");
			printf ("\n");
		}
	}

	if (tipo == 3){//iterativo
		//memoria utilizada na matriz caminho
		//a matriz utilizada para calcular soma e imprimir rota
	    for (i= 0; i < piramide->qtdLinhas; i++){
	    	analise->memoriaSoma = (piramide->qtdLinhas * sizeof(int)) + analise->memoriaSoma;
		}

		tempoInicial(&tempo);
		soma = piramideIterativa(piramide, caminho);
		analise->tempoSoma = tempoFinalizado(tempo);
		if (modoAnalise == modoDebug){
			printf ("\n ********************************************** Modo analise ativo **********************************************\n\n");
			printf (" Implementacao escolhida: De tras pra frente");
			printf ("\n Maior soma possivel: %d\n", soma);
			tempoInicial(&tempo);
			caminhoPercorrido(piramide, caminho, analise);
			analise->tempoCaminho = tempoFinalizado(tempo);
			printf (" Caminho percorrido: "); //imprimi o caminho percorrido
			for (i = 0; i < piramide->qtdLinhas; i++) {
		        for (j = 0; j <= i; j++){
		            if (piramide->caminhoPercorrido[i][j] == 1){
						printf ("%d", piramide->espaco[i][j]);
					}
					if (piramide->caminhoPercorrido[i][j] == 1 && i < piramide->qtdLinhas - 1){//nao deixa imprimir -> depois que nao tiver mais numeros
						printf (" -> ");
					}
		    	}
		    }
		    printf ("\n");
			printf("\n Tamanho da piramide: %d", piramide->qtdLinhas);
			printf("\n Tempo utilizado para encontrar a maior soma: %.5lf ms", analise->tempoSoma);
			printf("\n Tempo utilizado para informar a rota: %.5lf ms", analise->tempoCaminho);
			printf("\n Tempo total utilizado: %.5lf ms", analise->tempoSoma + analise->tempoCaminho);
			printf("\n Quantidade de memoria utilizada para somar: %.1lf", analise->memoriaSoma);
			printf("\n Quantidade de memoria utilizada para mostrar a rota: %.1lf", analise->memoriaCaminho);
			printf("\n Quantidade de memoria total utilizada: %.1lf", analise->memoriaCaminho + analise->memoriaSoma);
			printf("\n");
		}else{
			printf ("\n ********************************************** Modo analise desativado **********************************************\n\n");
			printf (" Implementacao escolhida: De tras pra frente");
			printf ("\n Maior soma possivel: %d\n", soma);
			caminhoPercorrido(piramide, caminho, analise);
			printf (" Caminho percorrido: "); //imprimi o caminho percorrido
			for (i = 0; i < piramide->qtdLinhas; i++) {
		        for (j = 0; j <= i; j++){
		            if (piramide->caminhoPercorrido[i][j] == 1){
						printf ("%d", piramide->espaco[i][j]);
					}
					if (piramide->caminhoPercorrido[i][j] == 1 && i < piramide->qtdLinhas - 1){//nao deixa imprimir -> depois que nao tiver mais numeros
						printf (" -> ");
					}
		    	}
		    }
		    printf ("\n");
			printf ("\n");
		}
	}
}

void caminhoPercorrido(TipoPiramide *piramide, int caminho[piramide->qtdLinhas][piramide->qtdLinhas], TipoAnalise *analise){
	int i, j, coluna = 0;

	caminho[0][0] = piramide->espaco[0][0]; //inicializa a primeira linha do caminho
	for (j = 0; j < piramide->qtdLinhas; j++) { //inicializa a ultima linha do caminho
        caminho[piramide->qtdLinhas - 1][j] = piramide->espaco [piramide->qtdLinhas - 1][j];
    }

	//inicializacao da matriz que e utilizada para verificar o caminho percorrido
	for (i = 0; i < piramide->qtdLinhas; i++){
		for (j = 0; j <= i; j++) {
            piramide->caminhoPercorrido[i][j] = 0;
        }
    }

    //memoria utilizada na matriz caminhoPercorrido
    for (i= 0; i < piramide->qtdLinhas; i++){
    	analise->memoriaCaminho = (piramide->qtdLinhas * sizeof(int)) + analise->memoriaCaminho;
	}

    for (i = 0; i < piramide->qtdLinhas - 1; i++){ //coloca 1 no celula que foi utilizada na soma
    	piramide->caminhoPercorrido[0][0] = 1;
		if(caminho[i+1][coluna]>caminho[i+1][coluna+1]){
			piramide->caminhoPercorrido[i+1][coluna] = 1;
		}else{
			piramide->caminhoPercorrido[i+1][coluna+1] = 1;
			coluna++;
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

//funcoes para testes automaticos
void teste(TipoPiramide *piramide, TipoAnalise *analise, int quantidade){//funcao para fazer os testes automaticamente
	//quantidade - quantidade de testes que a pessoa deseja fazer
	//tipo - qual metodo a pessoa quer testar
	int i, j, contador = 0, tamanho;
	char nomeArquivo[20];
	system("cls");

	for (i = 0; i < quantidade; i++){ //vai rodar o numero de vezes que a pessoa desejar fazer o teste
		tamanho = 1 + rand() % 39; //gera numeros aleatorios de 1 a 30
		contador = geraPiramide(i, tamanho, contador);
		sprintf(nomeArquivo, "piramide%d", i);
		lerArquivo(piramide, nomeArquivo);

		//usado para testar as 3 implementacoes
		printf ("\n\n ********************************************** Piramide de tamanho %d **********************************************\n\n", tamanho);
		for (j = 1; j < 4; j++){ //j e o tipo
			solucaoTeste (piramide, analise, j);
		}
		if (contador == quantidade)
			printf ("\n\n Teste realizado com sucesso\n\n");
	}
}

void solucaoTeste(TipoPiramide *piramide, TipoAnalise *analise, int tipo){
	int i, j, soma = 0, tempoTotal = 0;
	double memoriaTotal = 0;
	clock_t tempo;
	int caminho[piramide->qtdLinhas][piramide->qtdLinhas];

	//inicializacao das variaveis de analise
	analise->tempoSoma = 0;
	analise->tempoCaminho = 0;
	analise->memoriaSoma = 0;
	analise->memoriaCaminho = 0;
	analise->qtdChamadaRecursiva = 0;

	//memoria utilizada na matriz usada para piramide
    for (i= 0; i < piramide->qtdLinhas; i++){
    	analise->memoriaSoma = (piramide->qtdLinhas * sizeof(int)) + analise->memoriaSoma;
	}

	//inicializacao da matriz caminho
	for (i = 0; i < piramide->qtdLinhas; i++){
		for (j = 0; j <= i; j++) {
            caminho[i][j] = 0;
        }
    }

	if (tipo == 1){//recursivo
		//memoria utilizada na matriz caminho
		//essa matriz e uma auxiliar para impressao da rota
	    for (i= 0; i < piramide->qtdLinhas; i++){
	    	analise->memoriaCaminho = (piramide->qtdLinhas * sizeof(int)) + analise->memoriaCaminho;
		}
	    tempoInicial(&tempo);
		soma = piramideRecursiva(piramide, analise, caminho, 0, 0);
		analise->tempoSoma = tempoFinalizado(tempo);
		analise->memoriaSoma = (analise->qtdChamadaRecursiva * sizeof(int)) + analise->memoriaSoma; //memoria utilizada nas chamadas recursivas

		printf ("\n Resultado da soma: %d\n", soma);
		tempoInicial(&tempo);
		caminhoPercorrido(piramide, caminho, analise);
		analise->tempoCaminho = tempoFinalizado(tempo);
		printf (" Caminho percorrido: "); //imprimi o caminho percorrido
		for (i = 0; i < piramide->qtdLinhas; i++) {
	        for (j = 0; j <= i; j++){
	            if (piramide->caminhoPercorrido[i][j] == 1){
					printf ("%d", piramide->espaco[i][j]);
				}
				if (piramide->caminhoPercorrido[i][j] == 1 && i < piramide->qtdLinhas - 1){//nao deixa imprimir -> depois que nao tiver mais numeros
					printf (" -> ");
				}
	    	}
	    }
	    printf ("\n");
	    printf ("\n");

	    memoriaTotal = analise->memoriaCaminho + analise->memoriaSoma;

        printf(" Implementacao: Recursiva");
	    printf("\n Tempo utilizado para encontrar a maior soma: %.5lf ms", analise->tempoSoma);
        printf("\n Tempo utilizado para informar a rota: %.5lf ms", analise->tempoCaminho);
        printf("\n Tempo total utilizado: %.5lf ms", analise->tempoSoma + analise->tempoCaminho);
        printf("\n Quantidade de chamadas recursivas: %.1lf", analise->qtdChamadaRecursiva);
        printf("\n Quantidade de memoria utilizada para somar: %.1lf", analise->memoriaSoma);
        printf("\n Quantidade de memoria utilizada para mostrar a rota: %.1lf", analise->memoriaCaminho);
        printf("\n Quantidade de memoria total utilizada: %.1lf", analise->memoriaCaminho + analise->memoriaSoma);
        printf("\n");
	}

	if (tipo == 2){//Memoization
		//memoria utilizada na matriz caminho
		//a matriz utilizada para calcular soma e imprimir rota
	    for (i= 0; i < piramide->qtdLinhas; i++){
	    	analise->memoriaSoma = (piramide->qtdLinhas * sizeof(int)) + analise->memoriaSoma;
		}

	    tempoInicial(&tempo);
		soma = piramideMemoization(piramide, analise, caminho, 0, 0);
		analise->tempoSoma = tempoFinalizado(tempo);
		analise->memoriaSoma = (analise->qtdChamadaRecursiva * sizeof(int)) + analise->memoriaSoma; //memoria utilizada nas chamadas recursivas

		tempoInicial(&tempo);
		caminhoPercorrido(piramide, caminho, analise);
		analise->tempoCaminho = tempoFinalizado(tempo);

		memoriaTotal = analise->memoriaCaminho + analise->memoriaSoma;

		printf("\n Implementacao: Memoization");
	    printf("\n Tempo utilizado para encontrar a maior soma: %.5lf ms", analise->tempoSoma);
        printf("\n Tempo utilizado para informar a rota: %.5lf ms", analise->tempoCaminho);
        printf("\n Tempo total utilizado: %.5lf ms", analise->tempoSoma + analise->tempoCaminho);
        printf("\n Quantidade de chamadas recursivas: %.1lf", analise->qtdChamadaRecursiva);
        printf("\n Quantidade de memoria utilizada para somar: %.1lf", analise->memoriaSoma);
        printf("\n Quantidade de memoria utilizada para mostrar a rota: %.1lf", analise->memoriaCaminho);
        printf("\n Quantidade de memoria total utilizada: %.1lf", analise->memoriaCaminho + analise->memoriaSoma);
        printf("\n");
	}

	if (tipo == 3){//iterativo
		//memoria utilizada na matriz caminho
		//a matriz utilizada para calcular soma e imprimir rota
	    for (i= 0; i < piramide->qtdLinhas; i++){
	    	analise->memoriaSoma = (piramide->qtdLinhas * sizeof(int)) + analise->memoriaSoma;
		}

		tempoInicial(&tempo);
		soma = piramideIterativa(piramide, caminho);
		analise->tempoSoma = tempoFinalizado(tempo);

		tempoInicial(&tempo);
		caminhoPercorrido(piramide, caminho, analise);
		analise->tempoCaminho = tempoFinalizado(tempo);

		memoriaTotal = analise->memoriaCaminho + analise->memoriaSoma;

		printf("\n Implementacao: De tras pra frente");
	    printf("\n Tempo utilizado para encontrar a maior soma: %.5lf ms", analise->tempoSoma);
        printf("\n Tempo utilizado para informar a rota: %.5lf ms", analise->tempoCaminho);
        printf("\n Tempo total utilizado: %.5lf ms", analise->tempoSoma + analise->tempoCaminho);
        printf("\n Quantidade de memoria utilizada para somar: %.1lf", analise->memoriaSoma);
        printf("\n Quantidade de memoria utilizada para mostrar a rota: %.1lf", analise->memoriaCaminho);
        printf("\n Quantidade de memoria total utilizada: %.1lf", analise->memoriaCaminho + analise->memoriaSoma);
        printf("\n");

	}
}
