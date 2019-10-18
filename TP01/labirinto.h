//analisa a quantidade de chamadas recursivas e o nível maximo de recursao alcancada
#define modoAnalise 1 //definir como 1 se deseja ter as informações do modoAnalise e 0 se não desejar

//coordenadas da posicao
typedef struct Posicao{
    int x, y; //y é coluna e x é linha
}TipoPosicao;

//posicoes do estudante em alguns momentos
typedef struct Estudante{
    TipoPosicao pInicial;
    TipoPosicao pAtual;
    TipoPosicao pFinal;
}TipoEstudante;

//dados do labirinto
typedef struct Labirinto{
    char **espaco; //posicoes do labirinto
    int linhas; //quantidade de linhas
    int colunas; //quantidade de colunas
	int chaves; //quantidade de chaves
}TipoLabirinto;

typedef struct Analise{
	int qtdChamadaRecursiva;
	int qtdMovimento;
	int nivelMaximo;
	int maxAux;
}TipoAnalise;

//escopo das funcoes
void alocaEspaco(TipoLabirinto *Labirinto);
int lerArquivo(TipoLabirinto *labirinto, char *nomeArquivo);
int movimenta_estudante(TipoEstudante *estudante, TipoLabirinto *labirinto, TipoAnalise *analise, int caminho[labirinto->linhas][labirinto->colunas], int x, int y, int chave[labirinto->linhas][labirinto->colunas]);
int inicializacoes(TipoLabirinto *labirinto, TipoEstudante *estudante, TipoAnalise *analise, int opcao);
int movimentaEstudanteExtra(TipoEstudante *estudante, TipoLabirinto *labirinto, TipoAnalise *analise, int caminho[labirinto->linhas][labirinto->colunas], int x, int y, int chave[labirinto->linhas][labirinto->colunas]);
int geraLabirinto(int linhas, int colunas, int qtdChaves, int qtdPortas, int qtdParedes);
void imprimir(TipoLabirinto *labirinto);
void imprimirMatriz(TipoLabirinto *labirinto, int matriz[labirinto->linhas][labirinto->colunas]);
