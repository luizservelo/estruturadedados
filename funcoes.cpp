#include "funcoes.h"


void criafila(fila *f, int tam) {
	
	f->tamanho = tam;
	f->dado = (int*) malloc (f->tamanho * sizeof(int));
	f->primeiro = 0;
	f->ultimo = -1;
	f->itens = 0;
	
}

void inserir(int v, fila *f){
	
	if(f->ultimo == f->tamanho-1){
		f->ultimo = -1;
	}
	
	f->ultimo++;
	f->dado[f->ultimo] = v;
	f->itens++;
	
}

int vazia(fila *f){
	
	int booleano;
	
	if (f->itens == 0){
		booleano = 1;
	}
	else {
		booleano = 0;
	}
	
	return (booleano);
	
}

int cheia (fila *f){
	
	int booleano;
	
	if (f->itens == f->tamanho){
		booleano = 1;
	}
	else {
		booleano = 0;
	}
	
	return (booleano);
	
	
}

int remove(fila *f){
	
	int removida = f->dado[f->primeiro++];
	
	if (f->primeiro == f->tamanho){
		
		f->primeiro = 0;
		
	}
	f->itens--;
	return removida;
	
}

void imprime(fila *f){
	printf("\n");
	for(int cont = 0, i = f->primeiro; cont < f->itens;cont++){
		printf("%d  ", f->dado[i++]);
		
		if(i == f->tamanho)
			i=0;
	}
	
	printf("\n");
	
}

void faz_merge(fila *f1, fila *f2, fila *merge){

	int temp1, temp2;
	
	temp1 = remove(f1);
	temp2 = remove(f2);
	
	//Coloca o primeiro nas temps e já remove da fila
	while(vazia(f1) == 0 && vazia(f2) == 0){
		
		if(temp1<=temp2){
			inserir(temp1,merge);
			temp1 = remove(f1);
		}
		else{
			inserir(temp2,merge);
			temp2 = remove(f2);
		}
	}
	
	// Insere no merge os dois ultimos removidos pelo while
	if(temp1 <= temp2){
		inserir(temp1,merge);
		temp1=0;
		
	}
	else{
		inserir(temp2,merge);
		temp2=0;
		
	}
	
	//insere o restante da fila se uma for maior que a outra
	
	while(vazia(f1) == 0){
		
		if(temp2 > f1->primeiro){		
			inserir(remove(f1), merge );
		}
		else {
			inserir(temp2, merge);
			temp2=0;  // Zera caso o ultimo elemento2 entre na condicao de ser menor que um elemento 1
			printf("AddResto");
		}		
	}
	
	while(vazia(f2) == 0){
		
		if(temp1 > f2->primeiro){		
			inserir(remove(f2), merge );
		}
		else{
		 	inserir(temp1, merge);
		 	temp1=0;  // Zera caso o ultimo elemento1 entre na condicao de ser menor que um elemento 2
			printf("AddResto");
		}	
	}
	
	// Caso o ultimo elemento 1 ou 2 for maior que o outro e nao entrar na condicao acima, ele garante que o ultimo seja colocado na ulotima posicao
	
	if (temp1 != 0)
		inserir(temp1,merge);
		
	if (temp2 != 0)
		inserir(temp2,merge);	
	
}



