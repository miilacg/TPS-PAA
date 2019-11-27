//Universidade Federal de Vicosa - Campus Florestal
//Curso de Ciencia da Computacao
//Disciplina de Projeto e Analise de Algoritmos
//Professor Daniel Mendes
//Alunos: Camila C. Guimaraees - 2256 e Samuel Silva - 2662
//Trabalho Pratico 03

#include <stdio.h>
#include "casamentoExato.c"

int main(){	
	int leuArquivo, opcao, quantidade, opc, i, tamanho, contador = 0, modoAnalise, verificacao;
	char nomeArquivo[50];
	TipoTexto texto;

	do{			
		//menu para selecao das opcoes
        printf ("\n ****************************************************************************************");
	    printf ("\n *                                                                                      *");
	    printf ("\n *                            Escolha uma das opcoes abaixo                             *");
	    printf ("\n *                           1 - Carregar um arquivo de dados                           *");
	    printf ("\n *                           2 - Imprimir arquivo                                       *");
	    printf ("\n *                           3 - Sair do programa                                       *");
	    printf ("\n *                                                                                      *");
	    printf ("\n ****************************************************************************************");
	    printf ("\n");
        do{
            printf (" Entre com a opcao valida: ");
            scanf ("%d", &opcao);
        }while (opcao < 0 || opcao > 3); //garante que a opcao de entrada sera valida
	        
        switch(opcao){
            case 1: //carregar novo arquivo de dados
            	printf(" Digite o nome do arquivo de texto (sem a extensao): ");
                scanf("%s", nomeArquivo);
                leuArquivo = lerArquivo(&texto, nomeArquivo);/*
                if (leuArquivo){ //se o arquivo foi lido com sucesso
                	system("cls");
                	printf ("\n Arquivo lido com sucesso!\n\n");
                	
                	//menu para selecao das opcoes
	                printf ("\n ****************************************************************************************");
				    printf ("\n *                                                                                      *");
				    printf ("\n *                     Escolha qual dos algoritmos deseja executar                      *");
				    printf ("\n *                                 1 - Algoritmo 1                                      *");
				    printf ("\n *                                 2 - Algoritmo 2                                      *");
				    printf ("\n *                                 3 - Voltar                                           *");
				    printf ("\n *                                 4 - Sair do programa                                 *");
				    printf ("\n *                                                                                      *");
				    printf ("\n ****************************************************************************************");

				    printf ("\n");
			        do{
			            printf (" Entre com a opcao valida: ");
			            scanf ("%d", &opc);
			        }while (opc < 0 || opc > 5); //garante que a opcao de entrada sera valida
			        
			        switch(opc){
			            case 1: //Algoritmo 1
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
		            	case 2: //algoritmo 2
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
					        
					        //inicializacao das variaveis de analise
							analise.tempoSoma = 0;
							analise.tempoCaminho = 0;
							analise.memoriaSoma = 0;
							analise.memoriaCaminho = 0;
							analise.qtdChamadaRecursiva = 0;
		                    solucao(&piramide, &analise, opc, modoAnalise);
		            	break;
		            	case 3: //voltar
		            	break;
		                case 4: //sair
		                	exit(0);	
						break;						
			        }
            	}
        	break;*/
        	case 2: //Imprimir arquivo
	        	printf(" Digite o nome do arquivo de texto (sem a extensao): ");
                scanf("%s", nomeArquivo);
                imprimeTexto(texto, nomeArquivo);
	        break;
            case 3: //sair
            	exit(0);	
			break;						
        }
	}while(opcao!=3);   
	 
    return 0;
}
