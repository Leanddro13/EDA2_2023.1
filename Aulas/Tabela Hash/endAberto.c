/*
Tabela Hash, metodo de colisão: 
    Encadeamento separado

*/

#include<stdio.h>
#include<stdlib.h>
#define TAM 31

typedef struct no{
    int chave;
    struct no * prox;
}No; 

typedef struct{
    No *inicio;
    int tam;
}Lista;

void inicializarLista(Lista *l){
    l->inicio = NULL;
    l->tam = 0;
}

void inserir_na_lista(Lista *l, int valor){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->chave = valor;
        novo->prox = l->inicio;
        l->inicio = novo;
    }
}

int buscarLista(Lista *l, int valor){
    No *aux = l->inicio;
    while(aux && aux->chave != valor)
        aux = aux->prox;
    if(aux)
        return aux->chave;
    return 0;
}

void imprimirLista(Lista *l){
    No *aux = l->inicio;
    printf(" Tam: %d ", l->tam);
    while(aux)
        printf("%d ", aux->chave);
    aux = aux->prox;
}


void inicializaTabela(Lista t[]){
    for(int i = 0; i < TAM; i++)
        inicializarLista(&t[i]);
}


int hash(int chave){
    return chave % TAM;
}

void inserir(Lista t[], int valor){
    int id = hash(valor);

    inserir_na_lista(&t[id], valor);
}

int busca(Lista t[], int chave){
    int id = hash(chave);

    buscarLista(&t[id], chave);
}

void imprimir(Lista t[]){
    for(int i = 0; i < TAM; i++){
        printf("%2d = ", i);
        imprimirLista(&t[i]);
        printf("\n");
    }
}

int main(void){
    int tabela[TAM];

    return 0;
}