//Universidade Federal de Vicosa - Campus Florestal
//Curso de Ciencia da Computacao
//Disciplina de Projeto e Analise de Algoritmos
//Professor Daniel Mendes
//Alunos: Camila C. Guimar√£es - 2256 e Samuel Silva - 2662
//Trabalho Pratico 02

#include "partea.c"
#include <stdio.h>

int main(){
	srand(time(NULL)); //usado para funcao rand gerar numeros diferentes em um pequeno tempo
	
	int op, leuArquivo, opcao, quantidade, opc, solucao, i, tamanho, contador = 0;
	char nomeArquivo[50];
	TipoPiramide piramide;

	do{
		//menu para selecao das opcoes
	    printf ("\n****************************************************************************************");
	    printf ("\n*                                                                                      *");
	    printf ("\n*                            Escolha uma das opcoes abaixo                             *");
	    printf ("\n*                               1 - Maior soma                                         *");
	    printf ("\n*                               2 - Distancia de edicao                                *");
		printf ("\n*                               3 - Sair                                               *");
	    printf ("\n*                                                                                      *");
	    printf ("\n****************************************************************************************");
	    printf ("\n");
        do{
            printf ("Entre com a opcao valida: ");
            scanf ("%d", &op);
        }while (op < 0 || op > 3); //garante que a opcao de entrada sera valida
        
        switch(op){
        	case 1:
        		system("cls");				
				//menu para selecao das opcoes
                printf ("\n****************************************************************************************");
			    printf ("\n*                                                                                      *");
			    printf ("\n*               Escolha uma das opcoes abaixo para calcular a maior soma               *");
			    printf ("\n*                           1 - Carregar um arquivo de dados                           *");
			    printf ("\n*                           2 - Criar piramides aleatorias                             *");
			    printf ("\n*                           3 - Voltar                                                 *");
			    printf ("\n*                           4 - Sair do programa                                       *");
			    printf ("\n*                                                                                      *");
			    printf ("\n****************************************************************************************");
			    printf ("\n");
		        do{
		            printf ("Entre com a opcao valida: ");
		            scanf ("%d", &opcao);
		        }while (opcao < 0 || opcao > 4); //garante que a opcao de entrada sera valida
			        
		        switch(opcao){
		            case 1:
		            	printf("Digite o nome do arquivo de texto (sem a extensao): ");
		                scanf("%s", nomeArquivo);
		                leuArquivo = lerArquivo(&piramide, nomeArquivo);
		                if (leuArquivo){ //se o arquivo foi lido com sucesso
		                	//system("cls");
		                	printf ("\nArquivo lido com sucesso!\n\n");
		                	
		                	//menu para selecao das opcoes
			                printf ("\n****************************************************************************************");
						    printf ("\n*                                                                                      *");
						    printf ("\n*                     Escolha qual dos algoritmos deseja executar                      *");
						    printf ("\n*                                 1 - Recursivo                                        *");
						    printf ("\n*                                 2 - Memoization                                      *");
						    printf ("\n*                                 3 - Iterativo                                        *");
						    printf ("\n*                                 4 - Voltar                                           *");
						    printf ("\n*                                 5 - Sair do programa                                 *");
						    printf ("\n*                                                                                      *");
						    printf ("\n****************************************************************************************");
		
						    printf ("\n");
					        do{
					            printf ("Entre com a opcao valida: ");
					            scanf ("%d", &opc);
					        }while (opc < 0 || opc > 5); //garante que a opcao de entrada sera valida
					        
					        switch(opc){
					            case 1:
					            	/*system("cls");
				                    solucao =  //chama a funcao que trata de forma recursiva
				                    if (modoAnalise){//contabilizar as analises
								    	printf ("\nModo analise ativo\n\n"); 
										//imprimir tempo de execucao e memoria utilizada
										//imprimir o valor da soma e o caminho										
									}else{
										printf ("\nModo analise nao ativo\n\n");
										//imprimir o valor da soma e o caminho
									}*/
				            	break;
				            	case 2:
				            		/*system("cls");
				                    solucao =  //chama a funcao que trata de forma memoization
				                    if (modoAnalise){//contabilizar as analises
								    	printf ("\nModo analise ativo\n\n"); 
										//imprimir tempo de execucao e memoria utilizada
										//imprimir o valor da soma e o caminho										
									}else{
										printf ("\nModo analise nao ativo\n\n");
										//imprimir o valor da soma e o caminho
									}*/
				            	break;
				            	case 3:
				            		/*system("cls");
				                    solucao =  //chama a funcao que trata de forma iterativa
				                    if (modoAnalise){//contabilizar as analises
								    	printf ("\nModo analise ativo\n\n"); 
										//imprimir tempo de execucao e memoria utilizada
										//imprimir o valor da soma e o caminho										
									}else{
										printf ("\nModo analise nao ativo\n\n");
										//imprimir o valor da soma e o caminho
									}*/
				            	break;
				            		system ("cls");
				            	case 4:
				            	break;
				                case 5:
				                	exit(0);	
								break;						
					        }
		            	}
	            	break;
	            	case 2:
			        	printf("\nInforme quantas piramides deseja criar: ");
		                scanf("%d", &quantidade);
		                for (i = 0; i<quantidade; i++){
		                	tamanho = rand()%10 + 1;
		                	contador = geraPiramide(i, tamanho, contador);
						}
						if (contador == quantidade){
							printf ("\nPiramides criadas com sucesso.\n");
						}
			        break;
			        system ("cls");
	            	case 3:
	            	break;
	                case 4:
	                	exit(0);	
					break;						
		        }
        	break;
        	case 2:
        		//verificar o que È o problema da distancia
        	break;
    	}        
    }while(op!=3);   
	 
    return 0;
}
