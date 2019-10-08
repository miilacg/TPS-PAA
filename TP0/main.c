//Universidade Federal de Viçosa - Campus Florestal
//Curso de Ciência da Computação
//Disciplina de Projeto e Analise de Algoritmos
//Professor Daniel Mendes
//Aluna: Camila C. Guimarães - 2256
//Trabalho Prático 00

#include "TP0.c"

int main(){
    srand(time(NULL)); //usado para funcao rand gerar numeros diferentes em um pequeno tempo
    char quadro[linha][coluna]; //declaracao do quadro de tamanho 20 X 80
    delimita(quadro); //chama a funcao que faz a margem do quadro

    int op, qnt, novoQuadro; //declaracao de variaveis
    do{
        system("cls");
        //menu para selecao das opcoes
        printf ("\n*************************************************************************");
        printf ("\n*                                                                       *");
        printf ("\n*     Escolha o tipo de figura basica a ser usada para criar a obra     *");
        printf ("\n*                  1 - Asterisco simples                                *");
        printf ("\n*                  2 - Simbolo de soma com asteriscos                   *");
        printf ("\n*                  3 - Letra X com asteriscos                           *");
        printf ("\n*                  4 - Figuras aleatorias                               *");
        printf ("\n*                  5 - Obra de arte                                     *");
        printf ("\n*                  0 - Sair                                             *");
        printf ("\n*                                                                       *");
        printf ("\n*************************************************************************");
        printf ("\n");
        do{
            printf ("Entre com a opcao valida: ");
            scanf ("%d", &op);
        }while (op < 0 || op > 5); //garante que a opcao de entrada sera valida

        if (op != 0){//pergunta a quantidade de figuras apenas se o usuario nao desejar sair
            printf ("\nDigite a quantidade de figuras (menor ou igual a 0 para aleatorio): ");
            scanf ("%d", &qnt);
        }
        system("cls");

        if (qnt <= 0){
            qnt = numAleatorio();
        }
        if (qnt > 100){
            qnt = 100;
        }
        escolha (quadro, op, qnt); //chama a funcao que trata qual obra vai aparecer
    }while(op!=0);// enquanto a opcao foi diferente de 0 o menu volta a aparecer

    return 0;
}
