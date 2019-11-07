#ifndef PARTEB_DISTANCIAEDICAO_H
#define PARTEB_DISTANCIAEDICAO_H

typedef struct {
    int **Numero;
    int **Custo;
    int **Operacoes;
}MatrizDistancia;

void distancia(char *FirstWord, char *SecondWord, int m, int n, MatrizDistancia *p);
void distanciaIterativo(char *FirstWord, char *SecondWord, int m, int n, MatrizDistancia *p);
void InicializaMatrizDistancia(MatrizDistancia *mD, int SizeFirstWord, int SizeSecondWord);
int Minimo(int Deletar, int Inserir, int Substituir);
int distanciaEdicao(char *FirstWord, char *SecondWord, int m, int n);
void CalculaOperacoes(MatrizDistancia *p, int m, int n);
void imprimeMatriz(MatrizDistancia *p, int m, int n);

#endif //PARTEB_DISTANCIAEDICAO_H
