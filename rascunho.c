#include<stdio.h>
#include<stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void insere_ordenado(celula *le, int x){
    celula *p = (celula*)malloc(sizeof(celula));
    celula *aux = NULL;

    if(p){
        p->dado = x;
        p->prox = NULL; 
        if(le == NULL || p->dado < le->dado){
            p->prox = le;
            le = p;
        }
        else {
            aux = le;
            while(aux->prox && p->dado > aux->prox->dado)
                aux = aux->prox;
            p->prox = aux->prox;
            aux->prox = p;
        }
    }
}

void mescla_listas(celula *l1, celula *l2, celula *l3) {
    l1 = l1->prox;
    l2 = l2->prox;
    if(l1 == NULL){
        l3->prox = l2;
        return;
    }
    else if(l2 == NULL){
        l3->prox = l1;
        return;
    }

    while (l1 != NULL && l2 != NULL) {
        if (l1->dado <= l2->dado) {
            l3->prox = l1;
            l1 = l1->prox;
        } else {
            l3->prox = l2;
            l2 = l2->prox;
        }
        l3 = l3->prox;
    }
    l3->prox = (l1 != NULL) ? l1 : l2;
}

void imprime(celula *le){
    celula *p = le->prox;
    //if(p == NULL)
    while (p != NULL){
        printf("%d -> ", p->dado);
        p = p->prox;
    }
    printf("NULL\n"); 
}

int main() {
    celula *le1 = (celula*)malloc(sizeof(celula));
    celula *le2 = (celula*)malloc(sizeof(celula));
    celula *le3 = (celula*)malloc(sizeof(celula));
    le1->prox = NULL;
    le2->prox = NULL;
    //le3->prox = NULL;

    insere_ordenado(le1, 3);
    insere_ordenado(le1, 7);
    insere_ordenado(le1, 12);
    insere_ordenado(le1, 45);
    insere_ordenado(le1, 9);

    insere_ordenado(le2, 4);
    insere_ordenado(le2, 8);
    insere_ordenado(le2, 13);
    insere_ordenado(le2, 46);
    insere_ordenado(le2, 10);

    imprime(le1);
    imprime(le2);

    mescla_listas(le1, le2, le3);

    imprime(le3);

    return 0;
}