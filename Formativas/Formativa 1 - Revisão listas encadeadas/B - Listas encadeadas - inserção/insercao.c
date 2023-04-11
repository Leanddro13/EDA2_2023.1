#include<stdio.h>
#include<stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x){
    celula *p = (celula*)malloc(sizeof(celula));

    p->dado = x;
    p->prox = le->prox;

    le->prox = p;
}

void insere_antes(celula *le, int x, int y) {
    // Aloca uma nova célula
    celula *nova = (celula*) malloc(sizeof(celula));
    nova->dado = x;
    
    // Procura a primeira ocorrência de y na lista
    celula *atual = le;
    celula *anterior = NULL;
    while (atual != NULL && atual->dado != y) {
        anterior = atual;
        atual = atual->prox;
    }
    
    // Insere a nova célula antes da primeira ocorrência de y, ou no final da lista se y não estiver na lista
    if (atual != NULL) {
        nova->prox = atual;
        if (anterior == NULL) {
            le = nova;
        } else {
            anterior->prox = nova;
        }
    } else {
        nova->prox = NULL;
        if (anterior == NULL) {
            le = nova;
        } else {
            anterior->prox = nova;
        }
    }
}


