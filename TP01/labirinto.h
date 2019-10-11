#define modoAnalise 0//analisa a quantidade de chamadas recursivas e o nível maximo de recursao alcancada

typedef struct Posicao{
    int x, y; //y é coluna e x é linha
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
int lerArquivo(TipoLabirinto *labirinto, char *nomeArquivo);
void imprimir(TipoLabirinto *labirinto);
void imprimirCaminho(TipoLabirinto *labirinto, int caminho[labirinto->linhas][labirinto->colunas]);
int movimenta_estudante(TipoEstudante *estudante, TipoLabirinto *labirinto, TipoAnalise *analise, int caminho[labirinto->linhas][labirinto->colunas], int x, int y, int chave[labirinto->linhas][labirinto->colunas]); //encontrar a posicao do estudante e depois chamar essa funcao uma unica vez
int inicializacoes(TipoLabirinto *labirinto, TipoEstudante *estudante, TipoAnalise *analise);

