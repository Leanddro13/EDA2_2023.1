#include<stdio.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p){
    celula *remover;

    if(p && p->prox){
        remover = p->prox;
        p->prox = remover->prox;
        free(remover);
    }
}

void remove_elemento(celula *le, int x){
    celula *aux, *remover = NULL;

    if(le){
        if(le->dado == x){
            remover = le;
            le = remover->prox;
        }
        else{
            aux = le;
            while(aux->prox && aux->prox->dado != x){
                aux = aux->prox;
            }
            if(aux->prox){
                remover = aux->prox;
                aux->prox = remover->prox;
            }
        }
        if(remover){
            free(remover);
        }
    }
}

void remove_todos_elementos(celula *le, int x){
    celula *aux, *remover = NULL;

    
    while(le && le->dado == x){
        remover = le;
        le = remover->prox;
        free(remover);
    }
    if(le){
        aux = le;
        while(aux->prox){
            if(aux->prox->dado == x){
                remover = aux->prox;
                aux->prox = remover->prox;
                free(remover);
            }
            else {
                aux = aux->prox;
            }
        }
    }   
}
