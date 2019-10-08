#define modoAnalise 1 //analisa a quantidade de chamadas recursivas e o nível maximo de recursao alcancada

typedef struct Posicao{
    int x, y;
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
	int nivelMAximo;
}TipoAnalise;

void alocaEspaco(TipoLabirinto *Labirinto);
int lerArquivo(TipoLabirinto *labirinto, char *nomeArq);
void imprimir(TipoLabirinto *labirinto);
int movimenta_estudante(); //encontrar a posicao do estudante e depois chamar essa funcao uma unica vez
void imprimirResposta();
void inicializaPosicoes(TipoLabirinto *labirinto, TipoEstudante *estudante);

