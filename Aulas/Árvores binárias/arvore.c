#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *esq, *dir;
} No;

// Métodos de percorrer uma árvore binária

void preOrdem(No *raiz){
    if(raiz == NULL) return;
    printf("%d", raiz->dado);
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
}

void posOrdem(No *raiz){
    if(raiz == NULL) return;
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
    printf("%d", raiz->dado);
}

void emOrdem(No *raiz){
    if(raiz == NULL) return;
    preOrdem(raiz->esq);
    printf("%d", raiz->dado);
    preOrdem(raiz->dir);
}

// Determinar a altura

int altura(No *raiz){
    if(raiz == NULL) return -1;
    else{
        int he = altura(raiz->esq);
        int hd = altura(raiz->dir);
        if(he > hd) return he + 1;
        else return hd + 1;
    }
}

int main(){

    return 0;
}