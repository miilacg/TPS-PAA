#define modoDebug 1 //definir como 1 se deseja ter as informações do modoDebug e 0 se não desejar

typedef struct Piramide{
    int **espaco;
    int qtdLinhas;
}TipoPiramide;

typedef struct Caminho{
    int linhas;
    int colunas;
}TipoCaminho;

int lerArquivo(TipoPiramide *piramide, char *nomeArquivo);
void alocaEspaco(TipoPiramide *piramide);
int contaLinhas(TipoPiramide *piramide, char *nomeArquivo);
int geraPiramide(int i, int tamanho, int contador);

//funcoes para testes
void imprimir(TipoPiramide *piramide);

