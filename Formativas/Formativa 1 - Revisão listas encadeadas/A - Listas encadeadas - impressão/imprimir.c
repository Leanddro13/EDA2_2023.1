#include<stdio.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le){
    celula *p = le->prox;
    //if(p == NULL)
    while (p != NULL){
        printf("%d -> ", p->dado);
        p = p->prox;
    }
    printf("NULL\n"); 
}

void imprime_rec(celula *le){
    if(le->prox == NULL){
        printf("NULL\n");
        return;
    } 
    else{
        celula *p = le->prox;
        printf("%d", p->dado);
        if(p->prox != NULL){
            printf(" -> ");
            imprime_rec(p);
        }
        else{
            printf(" -> NULL\n");
        }
    } 
}

