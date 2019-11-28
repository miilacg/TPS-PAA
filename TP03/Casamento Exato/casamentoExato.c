#include "casamentoExato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//algoritmo de forca bruta
/*int forcaBruta(TipoTexto texto, TipoPadrao *padrao){
    long int i, j, k, o;
	        
    padrao->qtdOcorrencia = 0;
    padrao->tamanhoPadrao = strlen(padrao->palavraPadrao); //calcula o tamnho do padrao
  	
    for (i = 1; i <= (texto.tamanho - padrao->tamanhoPadrao + 1); i++){
        j = 0;       
        
        while (texto.caracteres[i+j] == padrao->palavraPadrao[j+1] && j < padrao->tamanhoPadrao){
        	printf ("%c ", texto.caracteres[i+j]);
        	printf ("%c \n", padrao->palavraPadrao[j+1]);
			j++;
        }

        if (j == padrao->tamanhoPadrao) {
        	padrao->posicaoOcorrencias[o] = i;
            //printf("Padrao encontrado na posicao %ld!\n", i);
            padrao->qtdOcorrencia ++;
        }
    }
	
    if (padrao->qtdOcorrencia == 0){
        return 0;
	}else{
		return 1;
	}
}

//algoritmo 2
int BMHS(TipoTexto texto, TipoPadrao *padrao) {
    long i, j, k, d[256 + 1], m, ocorrencia = 0;
    m = strlen(padrao->palavraPadrao);

    /* Pré-processamento para se obter a tabela de deslocamentos. */
    /*for (j = 0; j <= 256; j++)
        d[j] = m + 1;

    for (j = 1; j <= m; j++)
        d[padrao->palavraPadrao[j - 1]] = m - j + 1;

    i = m;

    /* Pesquisa */
    /*while (i <= texto.tamanho) {
        k = i;
        j = m;
        
        /* Pesquisa por um sufixo do texto (janela) que casa com texto (janela) 
         * que casa com um sufixo do padrão. */
     /*   while (texto.caracteres[k - 1] == padrao->palavraPadrao[j - 1] && j > 0) {
            k--;
            j--;
        }
        if (j == 0) {
            printf("Padrao encontrado na posicao %ld!\n", i);
            ocorrencia = 1;
        }
        
        /* Deslocamento da janela de acordo com o valor da tabela de 
         * deslocamentos relativo ao caractere que está na i-ésima posição 
         * do texto, ou seja, a posição seguinte ao último caractere do padrão 
         * (Sunday). */
     /*   i += d[texto.caracteres[i]];
    }

    if (!ocorrencia)
        printf("Padrao nao encontrado!\n");
        return 0;
}*/

//funcoes auxiliares
int lerArquivo(TipoTexto *texto, char *nomeArquivo){//le o arquivo
	FILE *arquivo;
	int tamanhoTexto, i = 0;
    char caminhoArquivo[150], caracter;
    strcpy(caminhoArquivo, "C:\\Users\\Camila\\Desktop\\Camila\\Trabalho\\Superior\\PAA\\TPS-PAA\\TP03\\Casamento Exato\\"); //caminho ate o arquivo
    strcat(caminhoArquivo, nomeArquivo); //nome do arquivo recebido pelo usuario
    strcat(caminhoArquivo, ".txt");

    arquivo = fopen(caminhoArquivo, "r"); //une as partes que compoem o caminhoArquivo

    if (arquivo == NULL) {
        printf("\nErro de leitura do arquivo\n");
        return 0; //retorna 0 caso nao seja possivel ler o arquivo
    }else{
    	calculaTamanho(texto, nomeArquivo);
    	while ((caracter = fgetc(arquivo)) != EOF){ //le o caractere na posicao atual enquanto o arquivo nao acabar
			texto->caracteres[i] = caracter;
            i++;
        }
	}
    
	fclose(arquivo);
    return 1; //retorna 1 se a leitura for feita com sucesso
}

void calculaTamanho(TipoTexto *texto, char *nomeArquivo){ //calculo do tamnho do texto e alocacao de memoria
	FILE *arquivo;
	int tamanhoTexto = 0, i = 0;
    char caminhoArquivo[150], caracter;
    strcpy(caminhoArquivo, "C:\\Users\\Camila\\Desktop\\Camila\\Trabalho\\Superior\\PAA\\TPS-PAA\\TP03\\Casamento Exato\\"); //caminho ate o arquivo
    strcat(caminhoArquivo, nomeArquivo); //nome do arquivo recebido pelo usuario
    strcat(caminhoArquivo, ".txt");

    arquivo = fopen(caminhoArquivo, "r"); //une as partes que compoem o caminhoArquivo

    if (arquivo == NULL) {
        printf("\nErro de leitura do arquivo\n");
    }else{
    	while (fgetc(arquivo) != EOF){ //le caracter por caracter
    		tamanhoTexto++;
		}       
		texto->tamanho = tamanhoTexto; //quantidade de caracter do texto
        texto->caracteres = malloc(texto->tamanho * sizeof(char)); //alocacao do espaco para o texto
	}
	fclose(arquivo);
}

void imprimeTexto(char *nomeArquivo){
    FILE *arquivo;
	int tamanhoTexto, i;
    char caminhoArquivo[150], caracter;
    strcpy(caminhoArquivo, "C:\\Users\\Camila\\Desktop\\Camila\\Trabalho\\Superior\\PAA\\TPS-PAA\\TP03\\Casamento Exato\\"); //caminho ate o arquivo
    strcat(caminhoArquivo, nomeArquivo); //nome do arquivo recebido pelo usuario
    strcat(caminhoArquivo, ".txt");

    arquivo = fopen(caminhoArquivo, "r"); //une as partes que compoem o caminhoArquivo

    if (arquivo == NULL) {
        printf("\nErro de leitura do arquivo\n");
    }else{		    
    	while ((caracter = fgetc(arquivo)) != EOF){ 
            printf ("%c", caracter);
        }
	}    
	fclose(arquivo);
}

void solucao(TipoTexto texto, TipoPadrao *padrao, TipoAnalise *analise, int algoritmo, int modoAnalise){
	int verificacao = 1;
	clock_t tempo;
	
	padrao->posicaoOcorrencias = malloc(texto.tamanho * sizeof(char)); //alocacao do espaco para o vetor posicaoOcorrencias 
		
	if (algoritmo == 1){//algoritmo 1
		tempoInicial(&tempo);
		//verificacao = chamar o algoritmo 2
		analise->tempo = tempoFinalizado(tempo);
		
		if (verificacao == 0){
			if (modoAnalise == modoDebug){
				printf ("\n ********************************************** Modo analise ativo **********************************************\n\n");
				printf (" Implementacao escolhida: Algoritmo 1");
				printf ("\n Nao foi encontrada nenhuma recorrencia do padrao");
				printf ("\n Tempo utilizado na busca: %.5lf ms", analise->tempo);
			}else{
				printf ("\n ********************************************** Modo analise desativado **********************************************\n\n");
				printf (" Implementacao escolhida: Algoritmo 1");
				printf ("\n Nao foi encontrada nenhuma recorrencia do padrao");
			}
		}else{
			if (modoAnalise == modoDebug){
				printf ("\n ********************************************** Modo analise ativo **********************************************\n\n");
				printf (" Implementacao escolhida: Algoritmo 1");
				printf ("\n Numero de padroes encontrados: %d\n", padrao->qtdOcorrencia);
				printf ("\n Ocorrencias dos padroes: %d\n", padrao->qtdOcorrencia);
				printf ("\n Tempo utilizado na busca: %.5lf ms", analise->tempo);
			}else{
				printf ("\n ********************************************** Modo analise desativado **********************************************\n\n");
				printf (" Implementacao escolhida: Algoritmo 1");
				printf ("\n Numero de padroes encontrados: %d\n", padrao->qtdOcorrencia);
				printf ("\n Ocorrencias dos padroes: %d\n", padrao->qtdOcorrencia);
			}	
		}		
	}
	
	if (algoritmo == 2){//algoritmo 2
		tempoInicial(&tempo);
		//verificacao = chamar o algoritmo 2
		analise->tempo = tempoFinalizado(tempo);
		
		if (verificacao == 0){
			if (modoAnalise == modoDebug){
				printf ("\n ********************************************** Modo analise ativo **********************************************\n\n");
				printf (" Implementacao escolhida: Algoritmo 2");
				printf ("\n Nao foi encontrada nenhuma recorrencia do padrao");
				printf ("\n Tempo utilizado na busca: %.5lf ms", analise->tempo);
			}else{
				printf ("\n ********************************************** Modo analise desativado **********************************************\n\n");
				printf (" Implementacao escolhida: Algoritmo 2");
				printf ("\n Nao foi encontrada nenhuma recorrencia do padrao");
			}
		}else{
			if (modoAnalise == modoDebug){
				printf ("\n ********************************************** Modo analise ativo **********************************************\n\n");
				printf (" Implementacao escolhida: Algoritmo 2");
				printf ("\n Numero de padroes encontrados: %d\n", padrao->qtdOcorrencia);
				printf ("\n Ocorrencias dos padroes: %d\n", padrao->qtdOcorrencia);
				printf ("\n Tempo utilizado na busca: %.5lf ms", analise->tempo);
			}else{
				printf ("\n ********************************************** Modo analise desativado **********************************************\n\n");
				printf (" Implementacao escolhida: Algoritmo 2");
				printf ("\n Numero de padroes encontrados: %d\n", padrao->qtdOcorrencia);
				printf ("\n Ocorrencias dos padroes: %d\n", padrao->qtdOcorrencia);
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
