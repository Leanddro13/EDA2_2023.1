#include<stdio.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

celula *busca(celula *le, int x){
    celula *p = le->prox;
    while(p != NULL && p->dado != x){
        p = p->prox;
    }
    return p;
}

celula *busca_rec(celula *le, int x){
    celula *p = le->prox;
    if(p != NULL && p->dado != x){
        return busca_rec(p, x);
    }
    return p;
}