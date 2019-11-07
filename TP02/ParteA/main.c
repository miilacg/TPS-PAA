//Universidade Federal de Vicosa - Campus Florestal
//Curso de Ciencia da Computacao
//Disciplina de Projeto e Analise de Algoritmos
//Professor Daniel Mendes
//Alunos: Camila C. Guimaraees - 2256 e Samuel Silva - 2662
//Trabalho Pratico 02

#include <stdio.h>
#include "partea.c"

int main(){
	srand(time(NULL)); //usado para funcao rand gerar numeros diferentes em um pequeno tempo
	
	int leuArquivo, opcao, quantidade, opc, i, tamanho, contador = 0, modoAnalise, verificacao;
	char nomeArquivo[50];
	TipoPiramide piramide;
	TipoAnalise analise;

	do{			
		//menu para selecao das opcoes
        printf ("\n ****************************************************************************************");
	    printf ("\n *                                                                                      *");
	    printf ("\n *               Escolha uma das opcoes abaixo para calcular a maior soma               *");
	    printf ("\n *                           1 - Carregar um arquivo de dados                           *");
	    printf ("\n *                           2 - Criar piramides aleatorias                             *");
	    printf ("\n *                           3 - Fazer testes automaticos                               *");
	    printf ("\n *                           4 - Sair do programa                                       *");
	    printf ("\n *                                                                                      *");
	    printf ("\n ****************************************************************************************");
	    printf ("\n");
        do{
            printf (" Entre com a opcao valida: ");
            scanf ("%d", &opcao);
        }while (opcao < 0 || opcao > 4); //garante que a opcao de entrada sera valida
	        
        switch(opcao){
            case 1: //carregar novo arquivo de dados
            	printf(" Digite o nome do arquivo de texto (sem a extensao): ");
                scanf("%s", nomeArquivo);
                leuArquivo = lerArquivo(&piramide, nomeArquivo);
                if (leuArquivo){ //se o arquivo foi lido com sucesso
                	system("cls");
                	printf ("\n Arquivo lido com sucesso!\n\n");
                	
                	//menu para selecao das opcoes
	                printf ("\n ****************************************************************************************");
				    printf ("\n *                                                                                      *");
				    printf ("\n *                     Escolha qual dos algoritmos deseja executar                      *");
				    printf ("\n *                                 1 - Recursivo                                        *");
				    printf ("\n *                                 2 - Memoization                                      *");
				    printf ("\n *                                 3 - De tras pra frente                               *");
				    printf ("\n *                                 4 - Voltar                                           *");
				    printf ("\n *                                 5 - Sair do programa                                 *");
				    printf ("\n *                                                                                      *");
				    printf ("\n ****************************************************************************************");

				    printf ("\n");
			        do{
			            printf (" Entre com a opcao valida: ");
			            scanf ("%d", &opc);
			        }while (opc < 0 || opc > 5); //garante que a opcao de entrada sera valida
			        
			        switch(opc){
			            case 1: //recursivo
			            	system("cls");
			            	printf ("\n ****************************************************************************************");
						    printf ("\n *                                                                                      *");
						    printf ("\n *                           Voce deseja ativar o modo debug?                           *");
						    printf ("\n *                                      0 - Nao                                         *");
						    printf ("\n *                                      1 - Sim                                         *");								    
						    printf ("\n *                                                                                      *");
						    printf ("\n ****************************************************************************************");
						    printf ("\n");
					        do{
					            printf (" Entre com a opcao valida: ");
					            scanf ("%d", &modoAnalise);
					        }while (modoAnalise < 0 || modoAnalise > 1); //garante que a opcao de entrada sera valida
					        
		                    solucao(&piramide, &analise, opc, modoAnalise);
		            	break;
		            	case 2: //memoization
		            		system("cls");
			            	printf ("\n ****************************************************************************************");
						    printf ("\n *                                                                                      *");
						    printf ("\n *                           Voce deseja ativar o modo debug?                           *");
						    printf ("\n *                                      0 - Nao                                         *");
						    printf ("\n *                                      1 - Sim                                         *");								    
						    printf ("\n *                                                                                      *");
						    printf ("\n ****************************************************************************************");
						    printf ("\n");
					        do{
					            printf (" Entre com a opcao valida: ");
					            scanf ("%d", &modoAnalise);
					        }while (modoAnalise < 0 || modoAnalise > 1); //garante que a opcao de entrada sera valida
					        
		                    solucao(&piramide, &analise, opc, modoAnalise);
		            	break;
		            	case 3: //iterativa
		            		system("cls");
			            	printf ("\n ****************************************************************************************");
						    printf ("\n *                                                                                      *");
						    printf ("\n *                           Voce deseja ativar o modo debug?                           *");
						    printf ("\n *                                      0 - Nao                                         *");
						    printf ("\n *                                      1 - Sim                                         *");								    
						    printf ("\n *                                                                                      *");
						    printf ("\n ****************************************************************************************");
						    printf ("\n");
					        do{
					            printf (" Entre com a opcao valida: ");
					            scanf ("%d", &modoAnalise);
					        }while (modoAnalise < 0 || modoAnalise > 1); //garante que a opcao de entrada sera valida
					        
		                    solucao(&piramide, &analise, opc, modoAnalise);
		            	break;
		            		system ("cls");
		            	case 4: //voltar
		            	break;
		                case 5: //sair
		                	exit(0);	
						break;						
			        }
            	}
        	break;
        	case 2: //criar arquivos de teste
	        	printf(" Informe quantas piramides deseja criar: ");
                scanf("%d", &quantidade);
                if (quantidade == 1){
                	printf("\n Arquivo que tenha o nome 'piramide0' sera modificado\n");
                	printf(" Deseja continuar assim mesmo? (0 para nao e 1 para sim) ");
                	scanf ("%d", &verificacao);
				}else{
					printf("\n Arquivos que tenham o nome no padrao 'piramideNUM' com NUM variando de 0 a %d serao modificados\n", quantidade-1);
                	printf(" Deseja continuar assim mesmo? (0 para nao e 1 para sim) ");
                	scanf ("%d", &verificacao);
				}
                switch(verificacao){
			        case 1:
	                	for (i = 0; i<quantidade; i++){
		                	tamanho = 50 + rand() % 50; //gera numeros aleatorios de 1 a 100
		                	contador = geraPiramide(i, tamanho, contador); //conta quantas piramides foram criadas
						}
						if (contador == quantidade){
							printf ("\n Piramides criadas com sucesso.\n");
						}
					break;
					case 0: //volta
					break;
				}
	        break;
	        case 3:
	        	printf (" Informe quantas piramides deseja criar: ");
	        	scanf ("%d", &quantidade);
	        	if (quantidade == 1){
                	printf("\n Arquivo que tenha o nome 'piramide0' sera modificado\n");
                	printf(" Deseja continuar assim mesmo? (0 para nao e 1 para sim) ");
                	scanf ("%d", &verificacao);
				}else{
					printf("\n Arquivos que tenham o nome no padrao 'piramideNUM' com NUM variando de 0 a %d serao modificados\n", quantidade-1);
                	printf(" Deseja continuar assim mesmo? (0 para nao e 1 para sim) ");
                	scanf ("%d", &verificacao);
				}
                switch(verificacao){
			        case 1: //recursivo
	                	teste (&piramide, &analise, quantidade);
					break;
					case 0: //volta
					break;
				}			        	
	        break;	
	        system ("cls");	
            case 4: //sair
            	exit(0);	
			break;						
        }
	}while(opcao!=4);   
	 
    return 0;
}
