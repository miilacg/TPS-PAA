#define modoDebug 1 //definir como 1 se deseja ter as informações do modoDebug e 0 se não desejar

typedef struct Piramide{
    int **espaco;
    int qtdLinhas;
}TipoPiramide;

int lerArquivo(TipoPiramide *piramide, char *nomeArquivo);
void alocaEspaco(TipoPiramide *piramide);
int contaLinhas(TipoPiramide *piramide, char *nomeArquivo);
int geraPiramide(int i, int tamanho, int contador);
int piramideRecursiva(TipoPiramide *piramide, int caminho[piramide->qtdLinhas][piramide->qtdLinhas], int y, int x);
void solucao(TipoPiramide *piramide, int tipo);
void caminhoPercorrido(TipoPiramide *piramide, int caminho[piramide->qtdLinhas][piramide->qtdLinhas]);

//funcoes para testes
void imprimir(TipoPiramide *piramide);

