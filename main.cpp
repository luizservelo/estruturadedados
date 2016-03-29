#include "funcoes.h"

int main (){
	
	printf("Software de Fila Circular\n\n");
	printf("Para limpar a tela durante a execucao do programa, digite '9'\n\nPara alternar entre Fila Circular Simples e Merge, digite '0'\n\nPara limpar o Merge, digite '8'\n\n");
	printf("PRESSIONE ENTER");
	fflush(stdin);
	getchar();
	system("cls");
	
	//Decisão para Fila Circular simples ou Merge de 2 Filas Circulares
	
	int menu = 3;
	int tamanho;
	int decisao;
	int valor;
	int aux;
	
	while (menu != 1 && menu != 2){
		printf("1 - Fila Circular Simples\t 2 - Merge\tOpcao: ");
		scanf("%d", &menu);
		system("cls");
	}
	
	if (menu == 1){
		fila f;
		
		printf("Entre com o tamanho da fila: ");
		scanf("%d", &tamanho);
		
		criafila(&f, tamanho);
		system("cls");
		
		while (menu == 1){
			printf("\n");
			printf("1 - Inserir\t2 - Remover\t3 - Imprimir\n4 - Vazia\t5 - Cheia\tOpcao: ");
			scanf("%d", &decisao);
			
			//INICIO SWITCH
			switch(decisao){
				
				case 1:{
					
					if(cheia(&f) == 1){
						printf("\nFila Cheia\n");
					}
					else{
						printf("Inserir valor: ");
						scanf("%d", &valor);
						inserir(valor, &f);
					}
					break;
				}
				
				case 2:{
					
					
					if(vazia(&f) == 1)
						printf("\nFila Vazia\n");
					else{
						
						remove(&f);
						printf("\nRemovido\n");
					}
					break;
				}
				
				case 3:{
					
					if(vazia(&f) == 1)
						printf("\nFila Vazia\n");
					else{
						
						imprime(&f);
						
					}
					break;
				}
				
				case 4:{
					if(vazia(&f) == 1)
						printf("\nFila Vazia\n");
					else printf("\nFila Nao Vazia\n");
					break;
				}
				
				case 5:{
					if(cheia(&f) == 1)
						printf("\nFila Cheia\n");
					else printf("\nFila Nao Cheia\n");
					break;
				}
				
				case 0:{
					menu = 2;
					system("cls");
					break;
				}
				
				case 9:{
					system("cls");
					break;
				}
				
				
			}
			// FIM SWITCH
		}
		
		
	}
	int verifica = 0;
	while (menu == 2){
		
		fila f1, f2, merge;
		int tam1, tam2;
		int decfila = 3;
		
		if (verifica == 0){
			printf("Digite o tamanho da primeira fila: ");
			scanf("%d", &tam1);
			printf("Digite o tamanho da segunda fila: ");
			scanf("%d", &tam2);
		
			criafila(&f1, tam1);
			criafila(&f2, tam2);
			criafila(&merge, tam1 + tam2);
			verifica = 9;
		}
		
		while (decfila != 1 && decfila != 2){
			
			printf("Qual fila deseja modificar? ");
			scanf ("%d", &decfila);
		
		}
		
		while (decfila == 1){
			
			while(decfila == 1){
				
				printf("\n");
				printf("1 - Inserir\t2 - Remover\t3 - Imprimir\t4 - Vazia\n5 - Cheia\t6 - Mudar Fila\t7 - Merge\tOpcao: ");
				scanf("%d", &decisao);
			
				switch(decisao){
					
					case 1:{
						
						if(cheia(&f1) == 1){
							printf("\nFila Cheia\n");
						}
						else{
							printf("Inserir valor: ");
							scanf("%d", &valor);
							inserir(valor, &f1);
						}
						break;
					}
					
					case 2:{
						
						if(vazia(&f1) == 1)
							printf("\nFila Vazia\n");
						else{
							remove(&f1);
							printf("\nRemovido\n");
						}
						break;
					}
					
					case 3:{
						
						if(vazia(&f1) == 1)
							printf("\nFila Vazia\n");
						else{
							imprime(&f1);
						}
						break;
					}
					
					case 4:{
						
						if(vazia(&f1) == 1)
							printf("\nFila Vazia\n");
						else printf("\nFila Nao Vazia\n");
						break;
					}
					
					case 5:{
						
						if(cheia(&f1) == 1)
							printf("\nFila Cheia\n");
						else printf("\nFila Nao Cheia\n");
						break;
					}
					
					case 6:{
						decfila = 3;
						system("cls");
						while (decfila != 1 && decfila != 2){
							printf("Qual fila deseja modificar? ");
							scanf ("%d", &decfila);
						}
						system("cls");
						break;
					}
					
					case 7:{
						faz_merge(&f1, &f2, &merge);
						imprime(&merge);
						break;
					}
					
					case 8: {
						while(vazia(&merge) == 0){
							remove(&merge);
						}
						if(vazia(&merge)==1)
							printf("Merge Limpo");
						break;
					}
					case 9: {
						
						system("cls");
						break;
					}
					 
				}
		
		
				
			}
			
		}
		
		while(decfila == 2){
			
			while(decfila == 2){
				
				printf("\n");
				printf("1 - Inserir\t2 - Remover\t3 - Imprimir\t4 - Vazia\n5 - Cheia\t6 - Mudar Fila\t7 - Merge\tOpcao: ");
				scanf("%d", &decisao);
			
				switch(decisao){
					
					case 1:{
						
						if(cheia(&f2) == 1){
							printf("\nFila Cheia\n");
						}
						else{
							printf("Inserir valor: ");
							scanf("%d", &valor);
							inserir(valor, &f2);
						}
						break;
					}
					
					case 2:{
						
						if(vazia(&f2) == 1)
							printf("\nFila Vazia\n");
						else{
							remove(&f2);
							printf("\nRemovido\n");
						}
						break;
					}
					
					case 3:{
						
						if(vazia(&f2) == 1)
							printf("\nFila Vazia\n");
						else{
							imprime(&f2);
						}
						break;
					}
					
					case 4:{
						
						if(vazia(&f2) == 1)
							printf("\nFila Vazia\n");
						else printf("\nFila Nao Vazia\n");
						break;
					}
					
					case 5:{
						
						if(cheia(&f2) == 1)
							printf("\nFila Cheia\n");
						else printf("\nFila Nao Cheia\n");
						break;
					}
					
					case 6:{
						system("cls");
						decfila = 3;
						if (decfila != 1 && decfila != 2){
							printf("Qual fila deseja modificar? ");
							scanf ("%d", &decfila);
						}
						system("cls");
						break;
					}
					
					case 7:{
						faz_merge(&f1, &f2, &merge);
						imprime(&merge);
						break;
					}
					
					case 8:{
						while(vazia(&merge) == 0){
							remove(&merge);
						}
						if(vazia(&merge)==1)
							printf("Merge Limpo");
						break;
					}
					
					case 9: {
						
						system("cls");
						break;
					}
					 
				}
		
		
				
			}
			
		}
		
		
		
		
	}
	
	
	
	
	
	
	fflush(stdin);
	getchar();
	return 0;
}
