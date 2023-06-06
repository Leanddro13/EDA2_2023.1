#include<stdio.h>
#include<stdlib.h>
#define TAM 262139 // primo proximo de 140000 

int tabela[TAM];

void inicializaTabela(int t[]){
    for(int i = 0; i < TAM; i++)
        t[i] = 0;
}

int hash(int chave){
    return chave % TAM;
}

void inserir(int t[], int valor){ //endereçamento aberto
    int id = hash(valor);

    while(t[id] != 0){
        id = hash(id + 1);
    }
    t[id] = valor;
}

int busca(int t[], int chave){
    int id = hash(chave);

    while(t[id] != 0){
        if(t[id] == chave)
            return t[id];
        else
            id = hash(id + 1);
    }
}

int main(void){ 
    unsigned int n, valor, t, proibido;
    scanf("%d", &n);
    inicializaTabela(tabela);
    for(int i = 0; i < n; i++){
        scanf("%d", &proibido);
        inserir(tabela, proibido);
    }

    while(scanf("%d", &valor) != EOF){
        int id = hash(valor);
        int aux = busca(tabela, valor);
        if(id == aux){
            printf("sim\n");
        }
        else{
            printf("nao\n");
        }
    }

    return 0;
}

/*
    while(scanf("%d", &valor) != EOF){
        t = hash(valor);
        if(tabela[t] == valor)
            printf("sim\n");
        else if(tabela[t] == 0)
            printf("nao\n");
    }

*/