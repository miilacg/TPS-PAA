#include <time.h>

#define modoDebug 1 //definir como 1 se deseja ter as informações do modoDebug e 0 se não desejar

typedef struct Piramide{
    int **espaco;
    int qtdLinhas;
}TipoPiramide;

typedef struct Analise{
	double tempoTotal;
	long int memoria;
	int qtdChamadaRecursiva;
}TipoAnalise;

int lerArquivo(TipoPiramide *piramide, char *nomeArquivo);
void alocaEspaco(TipoPiramide *piramide);
int contaLinhas(TipoPiramide *piramide, char *nomeArquivo);
int geraPiramide(int i, int tamanho, int contador);
int piramideRecursiva(TipoPiramide *piramide, TipoAnalise *analise, int caminho[piramide->qtdLinhas][piramide->qtdLinhas], int linha, int coluna);
int piramideIterativa(TipoPiramide *piramide, int caminho[piramide->qtdLinhas][piramide->qtdLinhas]);

//funcoes auxiliares
void solucao(TipoPiramide *piramide, TipoAnalise *analise, int tipo, int modoAnalise);
void caminhoPercorrido(TipoPiramide *piramide, int caminho[piramide->qtdLinhas][piramide->qtdLinhas], TipoAnalise *analise);
void tempoInicial(clock_t *tempo);
double tempoFinalizado(clock_t tempo);

//funcoes para testes
void imprimir(TipoPiramide *piramide);

