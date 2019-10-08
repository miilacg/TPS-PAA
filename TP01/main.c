//Universidade Federal de Viçosa - Campus Florestal
//Curso de Ciência da Computação
//Disciplina de Projeto e Analise de Algoritmos
//Professor Daniel Mendes
//Alunos: Camila C. Guimarães - 2256 e Samuel Silva
//Trabalho Prático 01

#include "labirinto.c"
#include <stdio.h>

int main(){
	int op, leuArquivo;
	char nomeArq[50];
	
    system("cls");
	do{
		 //menu para selecao das opcoes
	    printf ("\n*******************************************************************");
	    printf ("\n*                                                                 *");
	    printf ("\n*                  Escolha uma das opcoes abaixo                  *");
	    printf ("\n*                1 - Carregar novo arquivo de dados               *");
	    printf ("\n*                2 - Processar e exibir reposta                   *");
	    printf ("\n*                3 - Sair do programa                             *");
	    printf ("\n*                                                                 *");
	    printf ("\n*******************************************************************");
	    printf ("\n");
        do{
            printf ("Entre com a opcao valida: ");
            scanf ("%d", &op);
        }while (op < 0 || op > 3); //garante que a opcao de entrada sera valida
        
        switch(op){
            case 1:
                printf("Digite o nome do arquivo: ");
                scanf("%s", nomeArq);
                leuArquivo = //confere se recebeu um arquivo
                printf("\n");
                break;
            case 2:
                if (leuArquivo){
                    
                }else{
                    printf("Carregue antes um arquivo de dados\n");
                }
                break;
        }
    }while(op!=3);

    
    return 0;
}
