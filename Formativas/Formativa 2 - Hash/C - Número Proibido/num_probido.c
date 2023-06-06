#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    unsigned int N;
    struct celula *prox;
} num_proib;

num_proib *tab_hash;

void inicializar(){
    tab_hash = calloc(20161, sizeof(num_proib));
}

unsigned int hash(unsigned int chave){
    return chave%20161;
}

void inserir(unsigned int chave){
    num_proib *novo, *cabeca;
    cabeca = (tab_hash + hash(chave)); 
    novo = cabeca->prox;
    while(novo != NULL){
        if(novo->N == chave){
            return;
        }
        novo = novo->prox;
    }
    if(novo == NULL){
        novo = calloc(1, sizeof(num_proib));
        novo->N = chave;
        novo->prox = cabeca->prox;
        cabeca->prox = novo;
    }
}

void buscar(unsigned int chave){
    num_proib *alvo;
    alvo = (tab_hash + hash(chave))->prox;
    while(alvo != NULL){
        if(alvo->N == chave){
            printf("sim\n");
            return;
        }
        alvo = alvo->prox;
    }
    printf("nao\n");
}

int main(){
    unsigned int N, p;
    inicializar();
    scanf("%u", &N);
    while(N--){
        scanf("%u", &p);
        inserir(p);
    }
    while(scanf("%u", &N) != EOF){
        buscar(N);
    }
}