//Universidade Federal de Vicosa - Campus Florestal
//Curso de Ciencia da Computacao
//Disciplina de Projeto e Analise de Algoritmos
//Professor Daniel Mendes
//Alunos: Camila C. Guimar√£es - 2256 e Samuel Silva - 2662
//Trabalho Pratico 02

//#include "partea.c"
#include <stdio.h>

int main(){
	srand(time(NULL)); //usado para funcao rand gerar numeros diferentes em um pequeno tempo
	
	int op, leuArquivo, opcao;
	char nomeArquivo[50];

	do{
		//menu para selecao das opcoes
	    printf ("\n**************************************************************************");
	    printf ("\n*                                                                        *");
	    printf ("\n*                      Escolha uma das opcoes abaixo                     *");
	    printf ("\n*                   1 - Carregar novo arquivo de dados                   *");
		printf ("\n*                   2 - Sair                                             *");
	    printf ("\n*                                                                        *");
	    printf ("\n**************************************************************************");
	    printf ("\n");
        do{
            printf ("Entre com a opcao valida: ");
            scanf ("%d", &op);
        }while (op < 0 || op > 2); //garante que a opcao de entrada sera valida
        
        switch(op){
            case 1:
                printf("Digite o nome do arquivo de texto (sem a extensao): ");
                scanf("%s", nomeArquivo);
                leuArquivo = lerArquivo(&piramide, nomeArquivo);
                if (leuArquivo){ //se o arquivo foi lido com sucesso
                	system("cls");
                	printf ("\nArquivo lido com sucesso!\n\n");
                	
                	
                	//menu para selecao das opcoes
                	printf ("\n**************************************************************************");
				    printf ("\n*                                                                        *");
				    printf ("\n*                 Escolha qual forma voce deseja executar                *");
				    printf ("\n*                         1 - Recursao                                   *");
				    printf ("\n*                         2 - Memoization                                *");
				    printf ("\n*                         3 - De tr·s pra frente                         *");
				    printf ("\n*                         4 - Voltar                                     *");
				    printf ("\n*                         5 - Sair do programa                           *");
				    printf ("\n*                                                                        *");
				    printf ("\n**************************************************************************");
	
				    printf ("\n");
			        do{
			            printf ("Entre com a opcao valida: ");
			            scanf ("%d", &opcao);
			        }while (opcao < 0 || opcao > 5); //garante que a opcao de entrada sera valida
			        
			        switch(opcao){
			            case 1:
			            	system("cls");
		            	break;
		            	case 2:
		            	break;
		            	case 3:
		            	break;
		                case 4:
		                	//so volta pro menu anterior	
						break;						
						case 5:
							exit(0);
						break;
			        }
            	}else{
            		printf ("\nEntre com um arquivo valido\n\n");
				}       
	        break;
        }
    }while(op!=2);   
	 
    return 0;
}
