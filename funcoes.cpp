#include <stdio.h>
#include <stdlib.h>

typedef struct Fila {
	
	int tamanho;
	int *dado;
	int primeiro;
	int ultimo;
	int itens;
	
}fila;

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
	
	if(temp1 <= temp2){
		inserir(temp1,merge);
		inserir(temp2,merge);
		
	}
	else{
		inserir(temp2,merge);
		inserir(temp1,merge);
		
	}
	
	while(vazia(f1) == 0){
		
		inserir(remove(f1), merge);
		
	}
	
	while(vazia(f2) == 0){
		
		inserir(remove(f2), merge);
		
	}
	
}



