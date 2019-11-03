#define modoDebug 1 //definir como 1 se deseja ter as informa��es do modoDebug e 0 se n�o desejar

typedef struct Piramide{
    char **espaco;
    int qtdLinhas;
}TipoPiramide;

int lerArquivo(TipoPiramide *piramide, char *nomeArquivo);
void alocaEspaco(TipoPiramide *piramide);
int contaLinhas(TipoPiramide *piramide, char *nomeArquivo);

//funcoes para testes
void imprimir(TipoPiramide *piramide);
