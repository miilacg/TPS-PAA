#include "casamentoExato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//algoritmo 1

//algoritmo 2

//funcoes auxiliares
int lerArquivo(TipoTexto *texto, char *nomeArquivo){//le o arquivo
	FILE *arquivo;
	int tamanhoTexto, i;
    char caminhoArquivo[150], caracter;
    strcpy(caminhoArquivo, "C:\\Users\\Camila\\Desktop\\Camila\\Trabalho\\Superior\\PAA\\TPS-PAA\\TP03\\"); //caminho ate o arquivo
    strcat(caminhoArquivo, nomeArquivo); //nome do arquivo recebido pelo usuario
    strcat(caminhoArquivo, ".txt");

    arquivo = fopen(caminhoArquivo, "r"); //une as partes que compoem o caminhoArquivo

    if (arquivo == NULL) {
        printf("\nErro de leitura do arquivo\n");
        return 0; //retorna 0 caso nao seja possivel ler o arquivo
    }else{
    	while (fgetc(arquivo) != EOF){ //le caracter por caracter
    		tamanhoTexto++;
		}       
		
        texto->tamanho = tamanhoTexto; //quantidade de caracter do texto
        texto->palavras = malloc(texto->tamanho * sizeof(char)); //alocacao do espaco para o texto 
		    
    	while ((caracter = fgetc(arquivo)) != EOF) { 
            texto->palavras[i] = caracter; 
            i++;
        }
	}
    
	fclose(arquivo);
    return 1; //retorna 1 se a leitura for feita com sucesso
}

void imprimeTexto(TipoTexto texto, char *nomeArquivo){
    FILE *arquivo;
	int tamanhoTexto, i;
    char caminhoArquivo[150], caracter;
    strcpy(caminhoArquivo, "C:\\Users\\Camila\\Desktop\\Camila\\Trabalho\\Superior\\PAA\\TPS-PAA\\TP03\\"); //caminho ate o arquivo
    strcat(caminhoArquivo, nomeArquivo); //nome do arquivo recebido pelo usuario
    strcat(caminhoArquivo, ".txt");

    arquivo = fopen(caminhoArquivo, "r"); //une as partes que compoem o caminhoArquivo

    if (arquivo == NULL) {
        printf("\nErro de leitura do arquivo\n");
    }else{		    
    	while ((caracter = fgetc(arquivo)) != EOF) { 
            printf ("%c", caracter);
            i++;
        }
	}
    
	fclose(arquivo);
}

/*void tempoInicial(clock_t *tempo){
    *tempo = clock();
}

double tempoFinalizado(clock_t tempo){
    clock_t tempoFinal;
    tempoFinal = clock();
    return (double)((tempoFinal - tempo)* 1000.0)/CLOCKS_PER_SEC;
}*/
