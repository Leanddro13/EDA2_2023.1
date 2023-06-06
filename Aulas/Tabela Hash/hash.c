/*
Tabela Hash, metodo de colisão: 
    endereçamento aberto

*/

#include<stdio.h>
#include<stdlib.h>
#define TAM 31

void inicializaTabela(int t[]){
    for(int i = 0; i < TAM; i++)
        t[i] = 0;
}

int hash(int chave){
    return chave % TAM;
}

void inserir(int t[], int valor){
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

void imprimir(int t[]){
    for(int i = 0; i < TAM; i++){
        printf("%d = %d\n", i, t[i]);
    }
}

int main(void){
    int tabela[TAM];

    return 0;
}