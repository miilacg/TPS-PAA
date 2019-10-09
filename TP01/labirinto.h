#define modoAnalise 1 //analisa a quantidade de chamadas recursivas e o n�vel maximo de recursao alcancada

typedef struct Posicao{
    int x, y; //y � coluna e x � linha
}TipoPosicao;

typedef struct Estudante{
    TipoPosicao pInicial;
    TipoPosicao pAtual;
    TipoPosicao pFinal;
}TipoEstudante;

typedef struct Labirinto{
    char **espaco;
    int linhas; 
    int colunas;
	int chaves; 
}TipoLabirinto;

typedef struct Analise{
	int qtdChamadaRecursiva;
	int qtdMovimento;
	int nivelMaximo;
}TipoAnalise;

void alocaEspaco(TipoLabirinto *Labirinto);
int lerArquivo(TipoLabirinto *labirinto, char *nomeArq);
void imprimir(TipoLabirinto *labirinto);
int movimenta_estudante(TipoEstudante *estudante, TipoLabirinto *labirinto, TipoAnalise *analise, int x, int y, int caminho[labirinto->linhas][labirinto->colunas]); //encontrar a posicao do estudante e depois chamar essa funcao uma unica vez
void imprimirResposta();
int inicializacoes(TipoLabirinto *labirinto, TipoEstudante *estudante, TipoAnalise *analise);

