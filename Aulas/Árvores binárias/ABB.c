#include <stdio.h>
#include <stdlib.h>
/*
Árvore Binária de Busca (ABB), tem as seguintes operações:
    inserção - O(N);
    remoção - O(N);
    busca - O(LOG N);
    minimo - O(1);
    máximo - O(1);
Obs: essa complexidade ocorre quando os elementos estão ordenados
*/

typedef struct no{
    int chave;
    struct no *esq, *dir;
}No;

// Busca

No *busca(No *raiz, int x){
    if(raiz == NULL || raiz->chave == x) 
        return raiz;
    if(x < raiz->chave)
        return busca(raiz->esq, x);
    else
        return busca(raiz->dir, x);
} // Complexidade: O(h), sendo h altura

// Inserçao

No *insere(No *raiz, int x){
    if(raiz == NULL){
        No *novo = malloc(sizeof(No));
        novo->chave = x;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    if(x < raiz->chave)
        raiz->esq = insere(raiz->esq, x);
    else
        raiz->dir = insere(raiz->dir, x);
    return raiz;
} // Complexidade: O(h), sendo h altura

// Minino

No *minimo(No *raiz){
    if(raiz->esq == NULL) return raiz;
    return minimo(raiz->esq);
} // Complexidade O(h)

// Máximo

No *maximo(No *raiz){
    if(raiz->dir == NULL) return raiz;
    return maximo(raiz->dir);
}

// Remoção

void removeSucessor(No *raiz){
    No* pai = raiz;
    No* min = raiz->dir;
    while(min->esq){
        pai = min;
        min = min->esq;
    }
    raiz->chave = min->chave;
    if(min == pai->dir){
        pai->dir = min->dir;
    }
    else{
        pai->esq = min->dir;
    }
    free(min);
} // Complexidade: 0(H)

No *remover(No *raiz, int x){
    if(raiz != NULL){
        if(x < raiz->chave){
            raiz->esq = remover(raiz->esq, x);
        }
        else if(x < raiz->chave){
            raiz->dir = remover(raiz->dir, x);
        }
        else if(raiz->dir == NULL){
            No *ret = raiz->esq;
            free(raiz);
        }
        else{
            removeSucessor(raiz);
        }
    }
    return raiz;
}

