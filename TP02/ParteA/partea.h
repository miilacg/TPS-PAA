#include <time.h>

#define modoDebug 1 //definir como 1 se deseja ter as informações do modoDebug e 0 se não desejar

typedef struct Piramide{
    int **espaco;
    int qtdLinhas;
    int **caminhoPercorrido;
}TipoPiramide;

typedef struct Analise{
	double tempoSoma;
	double tempoCaminho;
	double memoriaSoma;
	double memoriaCaminho;
	double qtdChamadaRecursiva;
}TipoAnalise;

//funcoes principais
int piramideMemoization(TipoPiramide *piramide, TipoAnalise *analise, int caminho[piramide->qtdLinhas][piramide->qtdLinhas], int linha, int coluna);
int piramideIterativa(TipoPiramide *piramide, int caminho[piramide->qtdLinhas][piramide->qtdLinhas]);
int piramideRecursiva(TipoPiramide *piramide, TipoAnalise *analise, int caminho[piramide->qtdLinhas][piramide->qtdLinhas], int linha, int coluna);

//funcoes auxiliares
int lerArquivo(TipoPiramide *piramide, char *nomeArquivo);
void alocaEspaco(TipoPiramide *piramide);
int contaLinhas(TipoPiramide *piramide, char *nomeArquivo);
int geraPiramide(int i, int tamanho, int contador);
void solucao(TipoPiramide *piramide, TipoAnalise *analise, int tipo, int modoAnalise);
void caminhoPercorrido(TipoPiramide *piramide, int caminho[piramide->qtdLinhas][piramide->qtdLinhas], TipoAnalise *analise);
void tempoInicial(clock_t *tempo);
double tempoFinalizado(clock_t tempo);

//funcoes para teste automatico
void teste(TipoPiramide *piramide, TipoAnalise *analise, int quantidade);
void solucaoTeste(TipoPiramide *piramide, TipoAnalise *analise, int tipo);
