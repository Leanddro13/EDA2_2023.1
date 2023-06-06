#include<stdio.h>
#include<stdlib.h>

enum Cor{VERMELHO, PRETO};

typedef struct no{
    int dado;
    enum Cor cor;
    struct no *esq, *dir;
}No;

int ehVermelho(No *x){
    if(x == NULL) return 0;
    return x->cor == VERMELHO;
}

int ehPreto(No *x){
    if(x == NULL) return 1;
    return x->cor == PRETO;
}

No *rotacionaEsquerda(No *raiz){
    No *tmp = raiz->dir;
    raiz->dir = tmp->esq;
    tmp->esq = raiz;
    tmp->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return tmp;
}

No *rotacionaDireita(No *raiz){
    No *tmp = raiz->esq;
    raiz->esq = tmp->dir;
    tmp->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return tmp;
}

No *sobeCor(No *raiz){
    raiz->cor = VERMELHO;
    raiz->esq->cor = PRETO;
    raiz->dir->cor = PRETO;
}


No *inserir(No *raiz, int x){
    if(raiz == NULL){
        No *novo = calloc(1, sizeof(No));
        novo->dado = x;
        novo->cor = VERMELHO;
        return novo;
    }
    if(x < raiz->dado){
        raiz->esq = inserir(raiz->esq, x);
    }
    else{
        raiz->dir = inserir(raiz->dir, x);
    }

    // Corrige a raiz

    if(ehVermelho(raiz->dir) && ehPreto(raiz->esq)){
        raiz = rotacionaEsquerda(raiz);
    }
    if(ehVermelho(raiz->esq) && ehVermelho(raiz->esq->esq)){
        raiz = rotacionaDireita(raiz);
    }
    if(ehVermelho(raiz->esq) && ehVermelho(raiz->dir)){
        raiz = sobeCor(raiz);
    }
    return raiz;
}

/* Todas as operações com a árvore rubro-negra, tem a complexidade O(log n). */
