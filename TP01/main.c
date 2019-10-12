//Universidade Federal de Viçosa - Campus Florestal
//Curso de Ciência da Computação
//Disciplina de Projeto e Analise de Algoritmos
//Professor Daniel Mendes
//Alunos: Camila C. Guimarães - 2256 e Samuel Silva
//Trabalho Prático 01

#include "labirinto.c"
#include <stdio.h>

int main(){
	srand(time(NULL)); //usado para funcao rand gerar numeros diferentes em um pequeno tempo
	
	int op, leuArquivo, solucao, opcao, linhas, colunas, qtdChaves, qtdParedes, qtdPortas, tamanho;
	char nomeArquivo[50];
	TipoAnalise analise;
	TipoLabirinto labirinto;
	TipoEstudante estudante;

	do{
		//menu para selecao das opcoes
	    printf ("\n******************************************************************************************************");
	    printf ("\n*                                                                                                    *");
	    printf ("\n*                                   Escolha uma das opcoes abaixo                                    *");
	    printf ("\n*                                 1 - Carregar novo arquivo de dados                                 *");
	    printf ("\n*                                 2 - Criar labirinto                                                *");
	    printf ("\n*                                 3 - Processar e exibir reposta                                     *");
	    printf ("\n*                                 4 - Sair do programa                                               *");
	    printf ("\n*                                                                                                    *");
	    printf ("\n******************************************************************************************************");
	    printf ("\n");
        do{
            printf ("Entre com a opcao valida: ");
            scanf ("%d", &op);
        }while (op < 0 || op > 3); //garante que a opcao de entrada sera valida
        
        switch(op){
            case 1:
                printf("Digite o nome do arquivo de texto (sem a extensao): ");
                scanf("%s", nomeArquivo);
                leuArquivo = lerArquivo(&labirinto, nomeArquivo);
                if (leuArquivo){
                	system("cls");
                	printf ("\nArquivo lido com sucesso!\n\n");
            	}
            break;
            case 2:
            	system ("cls");
            	printf("\n**************************************Monte seu labirinto**************************************\n");
	        	printf("\n Informe a quantidade de linhas desejada: ");
                scanf("%d", &linhas);
                printf(" Informe a quantidade de colunas desejada: ");
                scanf("%d", &colunas);
                tamanho = linhas * colunas;
                printf(" Informe a quantidade de chaves inicial: ");
                scanf("%d", &qtdChaves);
                printf(" Informe a quantidade de portas desejada: ");
                scanf("%d", &qtdPortas);                
            	while (tamanho < qtdPortas){
                	printf ("\n A quantidade de portas precisa ser menor que o tamanho do labirinto. Entre com outro valor: ");
                	scanf("%d", &qtdPortas);
				}
                printf(" Informe a quantidade de paredes desejada: ");
                scanf("%d", &qtdParedes);
                while (tamanho < qtdParedes){
                	printf ("\n A quantidade de paredes precisa ser menor que o tamanho do labirinto. Entre com outro valor: ");
                	scanf("%d", &qtdParedes);
				}	
				while (tamanho < qtdParedes + qtdPortas){
					printf(" \nO numero total de portas e paredes tem que ser menor que o tamanho do labirinto.\n");
					printf (" Informe a quantidade de portas desejada: ");
	                scanf("%d", &qtdPortas);                
	            	while (tamanho < qtdPortas){
	                	printf ("\n A quantidade de portas precisa ser menor que o tamanho do labirinto. Entre com outro valor: ");
	                	scanf("%d", &qtdPortas);
					}
					printf(" \nO numero total de portas e paredes tem que ser menor que o tamanho do labirinto.\n");
	                printf(" Informe a quantidade de paredes desejada: ");
	                scanf("%d", &qtdParedes);
	                while (tamanho < qtdParedes){
	                	printf (" \nA quantidade de paredes precisa ser menor que o tamanho do labirinto. Entre com outro valor: ");
	                	scanf("%d", &qtdParedes);
					}	
				}
                if(geraLabirinto(linhas, colunas, qtdChaves, qtdPortas, qtdParedes))
                	printf ("\nArquivo criado com sucesso. Nome do arquivo: Arquivo-Teste\n");
	        break;
            case 3:            	
            	system("cls");
            	if (leuArquivo){				
					//menu para selecao das opcoes
	                printf ("\n******************************************************************************************************");
				    printf ("\n*                                                                                                    *");
				    printf ("\n*                   Escolha uma das opcoes abaixo de acordo com os dados do arquivo                  *");
				    printf ("\n*                        1 - Nao permiti que o estudante pegue chaves no chao                        *");
				    printf ("\n*                        2 - Permiti que o estudante pegue chaves no chao                            *");
				    printf ("\n*                        3 - Voltar                                                                  *");
				    printf ("\n*                        4 - Sair do programa                                                        *");
				    printf ("\n*                                                                                                    *");
				    printf ("\n******************************************************************************************************");

				    printf ("\n");
			        do{
			            printf ("Entre com a opcao valida: ");
			            scanf ("%d", &opcao);
			        }while (opcao < 0 || opcao > 4); //garante que a opcao de entrada sera valida
			        
			        switch(opcao){
			            case 1:
			            	system("cls");
		                    solucao = inicializacoes(&labirinto, &estudante, &analise, 1);
		                    if (modoAnalise){//contabilizar as analises
						    	printf ("\nModo analise ativo\n\n"); 
						    	if(solucao){// Verifica se o problema tem solucao
									printf("O estudante se movimentou %d vezes e chegou na coluna %d da primeira linha\n", analise.qtdMovimento, estudante.pFinal.y, estudante.pFinal.x);
									printf("Numero total de chamadas recursivas: %d\n", analise.qtdChamadaRecursiva);
									printf("Nivel maximo de recursao: %d\n", analise.nivelMaximo);
								}else{
									printf("O estudante se movimentou %d vezes e percebeu que o labirinto nao tem saida\n", analise.qtdMovimento);
									printf("Numero total de chamadas recursivas: %d\n", analise.qtdChamadaRecursiva);
									printf("Nivel maximo de recursao: %d\n", analise.nivelMaximo);
								}
							}else{
								printf ("\nModo analise nao ativo\n\n");
								if(solucao){// Verifica se o problema tem solucao
									printf("O estudante se movimentou %d vezes e chegou na coluna %d da primeira linha\n", analise.qtdMovimento, estudante.pFinal.y, estudante.pFinal.x);
								}else{
									printf("O estudante se movimentou %d vezes e percebeu que o labirinto nao tem saida\n", analise.qtdMovimento);
								}
							}
		            	break;
		            	case 2:
		            		system("cls");
		                    solucao = inicializacoes(&labirinto, &estudante, &analise, 2);
		                    if (modoAnalise){//contabilizar as analises
						    	printf ("\nModo analise ativo\n\n"); 
						    	if(solucao){// Verifica se o problema tem solucao
									printf("O estudante se movimentou %d vezes e chegou na coluna %d da primeira linha\n", analise.qtdMovimento, estudante.pFinal.y, estudante.pFinal.x);
									printf("Numero total de chamadas recursivas: %d\n", analise.qtdChamadaRecursiva);
									printf("Nivel maximo de recursao: %d\n", analise.nivelMaximo);
								}else{
									printf("O estudante se movimentou %d vezes e percebeu que o labirinto nao tem saida\n", analise.qtdMovimento);
									printf("Numero total de chamadas recursivas: %d\n", analise.qtdChamadaRecursiva);
									printf("Nivel maximo de recursao: %d\n", analise.nivelMaximo);
								}
							}else{
								printf ("\nModo analise nao ativo\n\n");
								if(solucao){// Verifica se o problema tem solucao
									printf("O estudante se movimentou %d vezes e chegou na coluna %d da primeira linha\n", analise.qtdMovimento, estudante.pFinal.y, estudante.pFinal.x);
								}else{
									printf("O estudante se movimentou %d vezes e percebeu que o labirinto nao tem saida\n", analise.qtdMovimento);
								}
							}
		            	break;
		            		system ("cls");
		            	case 3:
		            	break;
		                case 4:
		                	exit(0);	
						break;						
			        }
        		}else{
                    printf("\nCarregue antes um arquivo de dados\n");
            	}
	        break;
        }
    }while(op!=4);   
	 
    return 0;
}
