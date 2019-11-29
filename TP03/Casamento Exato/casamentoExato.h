#include <time.h>

#define modoDebug 1 //definir como 1 se deseja ter as informações do modoDebug e 0 se não desejar
#define MAXTAM 256

typedef struct Texto{
    char *caracteres; //vetor para alocar o texto lido
    long int tamanho; //quantidade de caracteres
}TipoTexto;

typedef struct Padrao{
	char *palavraPadrao; //vetor para salvar o padrao
    long int qtdOcorrencia;
    long int *posicaoOcorrencias; //vetor das ocorrencias
    long int tamanhoPadrao;
}TipoPadrao;

typedef struct Analise{
	double tempo;
}TipoAnalise;

//algoritmos de casamento
int forcaBruta(TipoTexto texto, TipoPadrao *padrao);
int BMHS(TipoTexto texto, TipoPadrao *padrao);

//funcoes auxiliares
int lerArquivo(TipoTexto *texto, char *nomeArquivo);
void calculaTamanho(TipoTexto *texto, char *nomeArquivo);
void imprimeTeste(TipoTexto *texto);
void imprimeTexto(char *nomeArquivo);
void solucao(TipoTexto texto, TipoPadrao *padrao, TipoAnalise *analise, int algoritmo, int modoAnalise);
void tempoInicial(clock_t *tempo);
double tempoFinalizado(clock_t tempo);
