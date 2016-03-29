#include "funcoes.cpp"

struct Fila;

void criafila (fila *f, int tam);

void inserir(int v, fila *f);

int vazia(fila *f);

int cheia (fila *f);

int remove(fila *f);

void imprime (fila *f);

void faz_merge(fila *f1, fila *f2, fila *merge);
