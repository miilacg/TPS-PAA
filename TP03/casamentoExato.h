#include <time.h>

#define modoDebug 1 //definir como 1 se deseja ter as informações do modoDebug e 0 se não desejar

typedef struct Texto{
    char *palavras; //vetor para alocar o texto lido
    long tamanho; //quantidade de caracteres
}TipoTexto;

//funcoes auxiliares
int lerArquivo(TipoTexto *texto, char *nomeArquivo);
void imprimeTexto(TipoTexto texto, char *nomeArquivo);
