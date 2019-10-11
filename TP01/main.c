//Universidade Federal de Viçosa - Campus Florestal
//Curso de Ciência da Computação
//Disciplina de Projeto e Analise de Algoritmos
//Professor Daniel Mendes
//Alunos: Camila C. Guimarães - 2256 e Samuel Silva
//Trabalho Prático 01

#include "labirinto.c"
#include <stdio.h>

int main(){
	int op, leuArquivo, solucao;
	char nomeArquivo[50];
	TipoAnalise analise;
	TipoLabirinto labirinto;
	TipoEstudante estudante;

	do{
		//menu para selecao das opcoes
	    printf ("\n************************************************************************************");
	    printf ("\n*                                                                                  *");
	    printf ("\n*                          Escolha uma das opcoes abaixo                           *");
	    printf ("\n*                        1 - Carregar novo arquivo de dados                        *");
	    printf ("\n*                        2 - Processar e exibir reposta                            *");
	    printf ("\n*                        3 - Sair do programa                                      *");
	    printf ("\n*                                                                                  *");
	    printf ("\n************************************************************************************");
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
            	system("cls");
            	printf ("\n");
                if (leuArquivo){
                    solucao = inicializacoes(&labirinto, &estudante, &analise);
                    if (modoAnalise){//contabilizar as analises
                    	printf ("\nModo analise ativo\n\n"); 
                    	if(solucao){
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
						if(solucao){
							printf("O estudante se movimentou %d vezes e chegou na coluna %d da primeira linha\n", analise.qtdMovimento, estudante.pFinal.y, estudante.pFinal.x);
						}else{
							printf("O estudante se movimentou %d vezes e percebeu que o labirinto nao tem saida\n", analise.qtdMovimento);
						}
					}
                }else{
                    printf("\nCarregue antes um arquivo de dados\n");
                }
                break;
        }
    }while(op!=3);

    
    return 0;
}
