#include "casamentoExato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//algoritmo de forca bruta
int forcaBruta(TipoTexto texto, TipoPadrao *padrao){
    long int i, j, k, o = 0;
	        
    padrao->qtdOcorrencia = 0;
    padrao->tamanhoPadrao = strlen(padrao->palavraPadrao); //calcula o tamanho do padrao
  	
    for (i = 0; i <= (texto.tamanho - padrao->tamanhoPadrao + 1); i++){
        j = 0;
		k = i;          

		while (toupper(texto.caracteres[k]) == toupper(padrao->palavraPadrao[j])){//toupper ignora maiuscula e minuscula
			j++;
			k++;
		}
	
		if (j == (padrao->tamanhoPadrao)){
        	padrao->posicaoOcorrencias[o] = i;
            padrao->qtdOcorrencia ++;
            o++;
        }	
    }
	
    if (padrao->qtdOcorrencia == 0){
        return 0;
	}else{
		return 1;
	}
}

//algoritmo 2
int BMHS(TipoTexto texto, TipoPadrao *padrao){
    long int i, j, k, d[MAXTAM + 1], o = 0;
    
    padrao->tamanhoPadrao = strlen(padrao->palavraPadrao);
	padrao->qtdOcorrencia = 0;
	
    //Pre-processamento do padrão para se obter a tabela de deslocamentos.
    for (j = 0; j <= MAXTAM; j++){
    	d[j] = padrao->tamanhoPadrao + 1;
	}        

    for (j = 1; j <= padrao->tamanhoPadrao; j++){
    	d[padrao->palavraPadrao[j - 1]] = padrao->tamanhoPadrao - j + 1;
	}       

    i = padrao->tamanhoPadrao;

    // Pesquisa
    while (i <= texto.tamanho) {
        k = i;
        j = padrao->tamanhoPadrao;
        
        while (toupper(texto.caracteres[k - 1]) == toupper(padrao->palavraPadrao[j - 1]) && j > 0){
            k--;
            j--;
        }
        if (j == 0) {
            padrao->posicaoOcorrencias[o] = i - 1;
            padrao->qtdOcorrencia ++;
            o++;
        }
        
        // Deslocamento da janela 
        i = i + d[texto.caracteres[i]];
    }

    if (padrao->qtdOcorrencia == 0){
        return 0;
	}else{
		return 1;
	}
}

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
        //printf ("%d\n", texto->tamanho);
	}
	fclose(arquivo);
}

void imprimeTeste(TipoTexto *texto){
	int i;
	printf ("\n ");
    for (i = 0; i < texto->tamanho; i++){
    	printf ("%c", texto->caracteres[i]);
	}
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
		printf("\n ");  
    	while ((caracter = fgetc(arquivo)) != EOF){ 
            printf ("%c", caracter);
        }
        printf("\n");
	}    
	fclose(arquivo);
}

void solucao(TipoTexto texto, TipoPadrao *padrao, TipoAnalise *analise, int algoritmo, int modoAnalise){
	int verificacao, i;
	clock_t tempo;
	
	padrao->posicaoOcorrencias = malloc(texto.tamanho * sizeof(char)); //alocacao do espaco para o vetor posicaoOcorrencias 
		
	if (algoritmo == 1){//algoritmo de forca bruta
		tempoInicial(&tempo);
		verificacao = forcaBruta(texto, padrao);
		analise->tempo = tempoFinalizado(tempo);
		
		if (verificacao == 0){
			if (modoAnalise == modoDebug){
				printf ("\n ****************************** Modo analise ativo ******************************\n\n");
				printf ("\n Implementacao escolhida: Forca bruta");
				printf ("\n Nao foi encontrada nenhuma recorrencia do padrao");
				printf ("\n Tamanho do texto: %d", texto.tamanho);
				printf ("\n Tempo utilizado na busca: %.5lf ms \n\n", analise->tempo);
			}else{
				printf ("\n **************************** Modo analise desativado ***************************\n\n");
				printf ("\n Implementacao escolhida: Forca Bruta");
				printf ("\n Nao foi encontrada nenhuma recorrencia do padrao \n\n");
			}
		}else{
			if (modoAnalise == modoDebug){
				printf ("\n ****************************** Modo analise ativo ******************************\n\n");				
				printf ("\n Implementacao escolhida: Forca Bruta");
				printf ("\n Numero de padroes encontrados: %d", padrao->qtdOcorrencia);
				printf ("\n Ocorrencias dos padroes nas posicoes: ");
				for (i = 0; i < padrao->qtdOcorrencia; i++){
					printf ("%d", padrao->posicaoOcorrencias[i]);
					if (i < padrao->qtdOcorrencia - 1){
						printf (", ");
					}
				}
				printf ("\n Tamanho do texto: %d", texto.tamanho);
				printf ("\n Tempo utilizado na busca: %.5lf ms\n\n", analise->tempo);
			}else{
				printf ("\n **************************** Modo analise desativado ***************************\n\n");
				printf ("\n Implementacao escolhida: Forca bruta");
				printf ("\n Numero de padroes encontrados: %d", padrao->qtdOcorrencia);
				printf ("\n Ocorrencias dos padroes nas posicoes: ");
				for (i = 0; i < padrao->qtdOcorrencia; i++){
					printf ("%d", padrao->posicaoOcorrencias[i]);
					if (i < padrao->qtdOcorrencia - 1){
						printf (", ");
					}
				}
				printf ("\n\n");
			}	
		}		
	}
	
	if (algoritmo == 2){//algoritmo BMHS
		tempoInicial(&tempo);
		verificacao = BMHS(texto, padrao);
		analise->tempo = tempoFinalizado(tempo);
		
		if (verificacao == 0){
			if (modoAnalise == modoDebug){
				printf ("\n ****************************** Modo analise ativo ******************************\n\n");
				printf ("\n Implementacao escolhida: BMHS");
				printf ("\n Nao foi encontrada nenhuma recorrencia do padrao");
				printf ("\n Tamanho do texto: %d", texto.tamanho);
				printf ("\n Tempo utilizado na busca: %.5lf ms \n\n", analise->tempo);
			}else{
				printf ("\n **************************** Modo analise desativado ***************************\n\n");
				printf ("\n Implementacao escolhida: BMHS");
				printf ("\n Nao foi encontrada nenhuma recorrencia do padrao \n\n");
			}
		}else{
			if (modoAnalise == modoDebug){
				printf ("\n ****************************** Modo analise ativo ******************************\n\n");				
				printf ("\n Implementacao escolhida: BMHS");
				printf ("\n Numero de padroes encontrados: %d", padrao->qtdOcorrencia);
				printf ("\n Ocorrencias dos padroes nas posicoes: ");
				for (i = 0; i < padrao->qtdOcorrencia; i++){
					printf ("%d", padrao->posicaoOcorrencias[i]);
					if (i < padrao->qtdOcorrencia - 1){
						printf (", ");
					}
				}
				printf ("\n Tamanho do texto: %d", texto.tamanho);
				printf ("\n Tempo utilizado na busca: %.5lf ms\n\n", analise->tempo);
			}else{
				printf ("\n **************************** Modo analise desativado ***************************\n\n");
				printf ("\n Implementacao escolhida: BMHS");
				printf ("\n Numero de padroes encontrados: %d", padrao->qtdOcorrencia);
				printf ("\n Ocorrencias dos padroes nas posicoes: ");
				for (i = 0; i < padrao->qtdOcorrencia; i++){
					printf ("%d", padrao->posicaoOcorrencias[i]);
					if (i < padrao->qtdOcorrencia - 1){
						printf (", ");
					}
				}
				printf ("\n\n");
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
