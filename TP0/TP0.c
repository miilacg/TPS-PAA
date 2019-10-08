//Universidade Federal de Viçosa - Campus Florestal
//Curso de Ciência da Computação
//Disciplina de Projeto e Analise de Algoritmos
//Professor Daniel Mendes
//Aluna: Camila C. Guimarães - 2256
//Trabalho Prático 00

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define coluna 80
#define linha 20

//declaracao de variavel
int pLinha();
int pColuna();
int asterisco(char quadro[linha][coluna], int qnt);
int soma(char quadro[linha][coluna], int qnt);
int letraX(char quadro[linha][coluna], int qnt);
int figuraAleatoria(char quadro[linha][coluna], int qnt);
int obra(char quadro[linha][coluna], int qnt);
int imprime(char quadro[linha][coluna], int op, int qnt);
int numAleatorio();
int delimita(char quadro[linha][coluna]);
int escolha (char quadro[linha][coluna], int op, int qnt);

int pLinha(){ //calculo aleatorio da linha
    return 1 + rand()%linha;
}

int pColuna(){ //calculo aleatorio da coluna
    return 1 + rand()%coluna;
}

int numAleatorio(){ //calculo da quantidade aleatoria de figuras
    return 1 + rand()%100;
}

int asterisco(char quadro[linha][coluna], int qnt){ //figura com asterisco simples
    int i, x, y, cont = 0;
    while (cont<qnt){//verificacao da quantidade de imagens
        x = pLinha();
        y = pColuna();

        if (quadro[x][y] == ' '){ //verificao se o espaco esta vazio
            quadro [x][y] = '*';
            cont++; //o contador aumenta apenas quando a figura puder ser desenhada
        }
    }
}

int soma(char quadro[linha][coluna], int qnt){ //figura de coma com asteriscos
    int i = 0, x, y;
    int cont = 0;
    while (cont<qnt){
        //pega a posicao do meio do simbolo
        x = pLinha();
        y = pColuna();

        //veirifica se já não existe uma figura no
        if (quadro[x][y] == ' '){ //posicao do meio
            if (quadro[x-1][y] == ' '){ //posicao acima da coluna do meio
                if (quadro[x+1][y] == ' '){ //posicao abaixo da coluna do meio
                    if (quadro[x][y-1] == ' '){ //posicao mais a esquerda da coluna do meio
                        if (quadro[x][y+1] == ' '){ //posicao mais a direita da linha do meio
                            quadro [x][y] = '*';
                            quadro [x][y+1] = '*';
                            quadro [x][y-1] = '*';
                            quadro [x+1][y] = '*';
                            quadro [x-1][y] = '*';
                            cont ++;
                        }
                    }
                }
            }
        }
    }
}

int imprime (char quadro[linha][coluna], int op, int qnt){ //uncao usada para imprimir a obra
    int i, j,novoQuadro;
    for (i=0; i<linha; i++){
        for (j=0; j<coluna; j++){
            printf("%c", quadro[i][j]);
        }
        printf("\n");
    }
    delimita(quadro); //chama a funcao delimita para poder limpar o quadro para uma nova obra
    do{
        printf ("Voce deseja fazer um outro quadro com esses mesmos valores?\n");
        printf ("Digite 1 para sim e 0 para nao\n");
        scanf("%d", &novoQuadro);
        printf ("\n");
        if (novoQuadro == 1){
            system("cls");
            escolha (quadro, op, qnt);//se o usuario desejar refazer o quadro a funcao e chamada
        }
    }while (novoQuadro != 1 && novoQuadro != 0); //garante que vai ser uma opcao valida

}

int delimita(char quadro[linha][coluna]){ // a funcao delimita o quadro e coloca um espaco em branco nas outras posicoes
    int i, j;
    for (i=0; i<linha; i++){
        for (j=0; j<coluna; j++){
            quadro[i][j] = ' '; //coloca espaco vazio para servir de comparacao na hora de olhar se o espaco já esta ocupado
            if (i == 0 || i == linha - 1){
                quadro[i][j] = '-';
            }
            if ((j==0 && i != 0 && i != linha - 1) || (j == coluna-1 && i != 0 && i != linha - 1)){
                quadro[i][j] = '|';
            }
        }
    }
}

int letraX(char quadro[linha][coluna], int qnt){ //figura da letra X com asteriscos
    int i = 0, x, y;
    int cont = 0;
    while (cont<qnt){
        //pega a posicao do meio do simbolo
        x = pLinha();
        y = pColuna();

        //veirifica se já não existe uma figura no local
        if (quadro[x][y] == ' '){ //posicao do meio
            if (quadro[x-1][y-1] == ' '){ //posicao acima mais a esquerda
                if (quadro[x+1][y-1] == ' '){ //posicao acima mais a direita
                    if (quadro[x-1][y+1] == ' '){ //posicao abaixo mais a esquerda
                        if (quadro[x-1][y+1] == ' '){ //posicao abaixo mais a direita
                            quadro [x][y] = '*';
                            quadro [x+1][y+1] = '*';
                            quadro [x+1][y-1] = '*';
                            quadro [x-1][y+1] = '*';
                            quadro [x-1][y-1] = '*';
                            cont ++; // soma um no contador caso a imagem possa ser desenhada
                        }
                    }
                }
            }
        }
    }
}

int figuraAleatoria(char quadro[linha][coluna], int qnt){ //desenha imagens aleatorias
    int fig, cont = 0; //o cont é usado para contabilizar se a imagem foi desenhada
                       //e comparar com a quantidade de imagens que deve ser desenhada
    while (cont<qnt){
        fig = 1 + rand()%3; // utiliza a funcao rand para deteminar qual figura sera desenhada
        switch (fig){
            case 1: //asterisco
                asterisco(quadro, 1); //nesse caso é enviado apenas uma quantidade porque a funcao é chamada varias vezes
                cont++;
            break;
            case 2: //soma
                soma(quadro, 1);
                cont++;
            break;
            case 3: //X
                letraX(quadro, 1);
                cont++;
            break;
        }
    }
}

int obra(char quadro[linha][coluna], int qnt){
    //a poderá ser um circulo ou um triangulo
    int i = 0, x, y, fig;
    int cont = 0;
    while (cont<qnt){
        fig = 1 + rand()%2; // utiliza a funcao rand para deteminar qual figura sera desenhada
        switch (fig){
            case 1: //circulo
                //pega uma posicao inicial para comparaçao
                    x = pLinha();
                    y = pColuna();

                    //veirifica se já não existe uma figura no local
                    //comparacao da primeira linha
                    if (quadro[x-1][y] == ' '){
                        if (quadro[x-1][y+1] == ' '){
                            if (quadro[x-1][y+2] == ' '){
                                //comaracao da segunda linha
                                if (quadro[x][y-1] == ' '){
                                    if (quadro[x][y+3] == ' '){
                                        //comparacao da terceira linha
                                        if (quadro[x+1][y-1] == ' '){
                                            if (quadro[x+1][y+3] == ' '){
                                                //comparacao da quarta linha
                                                if (quadro[x+2][y] == ' '){
                                                    if (quadro[x+2][y+1] == ' '){
                                                        if (quadro[x+2][y+2] == ' '){
                                                            //preenche o circulo
                                                            quadro[x-1][y] = '*'; //primeira linha
                                                            quadro[x-1][y+1] = '*'; //primeira linha
                                                            quadro[x-1][y+2] = '*'; //primeira linha
                                                            quadro[x][y-1] = '*'; //segunda linha
                                                            quadro[x][y+3] = '*'; //segunda linha
                                                            quadro[x+1][y-1] = '*'; //terceira linha
                                                            quadro[x+1][y+3] = '*'; //terceira linha
                                                            quadro[x+2][y] = '*'; //quarta linha
                                                            quadro[x+2][y+1] = '*'; //quarta linha
                                                            quadro[x+2][y+2] = '*'; //quarta linha
                                                            cont ++;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
            break;
            case 2: //triangulo
                x = pLinha();
                y = pColuna();

                //veirifica se já não existe uma figura no local
                if (quadro[x][y] == ' '){
                    if (quadro[x-1][y+1] == ' '){
                        if (quadro[x+1][y+1] == ' '){
                            if (quadro[x-2][y+2] == ' '){
                                if (quadro[x-1][y+2] == ' '){
                                    if (quadro[x][y+2] == ' '){
                                        if (quadro[x+1][y+2] == ' '){
                                            if (quadro[x+2][y+2] == ' '){
                                                //preenche o triangulo
                                                quadro[x][y] = '*';
                                                quadro[x-1][y+1] = '*';
                                                quadro[x+1][y+1]  = '*';
                                                quadro[x-2][y+2] = '*';
                                                quadro[x-1][y+2] = '*';
                                                quadro[x][y+2] = '*';
                                                quadro[x+1][y+2] = '*';
                                                quadro[x+2][y+2] = '*';
                                                cont ++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            break;
        }
    }
}

 int escolha (char quadro[linha][coluna], int op, int qnt){ //funcao que trata as opcoes enviadas pelo usuario atraves do menu
    // permite o usuario escolher qual o tipo de figura
    switch (op){
        case 1: //asterisco
            asterisco(quadro, qnt);
            imprime (quadro, op, qnt);
            printf ("\n");
            printf ("\n");
        break;
        case 2: //soma
            soma(quadro, qnt);
            imprime (quadro, op, qnt);
            printf ("\n");
            printf ("\n");
        break;
        case 3: //X
            letraX(quadro, qnt);
            imprime (quadro, op, qnt);
            printf ("\n");
            printf ("\n");
        break;
        case 4: //figuras aleatorias
            figuraAleatoria(quadro, qnt);
            imprime (quadro, op, qnt);
            printf ("\n");
            printf ("\n");
        break;
        case 5: //obra
            obra(quadro, qnt);
            imprime (quadro, op, qnt);
            printf ("\n");
            printf ("\n");
         break;
         case 0:
            exit(-1);
    }
}
