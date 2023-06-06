/*
Tabela Hash
*/

#include<stdio.h>
#include<stdlib.h>
 
int v[262139]; // primo proximo de 140000 

int hashn(int chave){ // indice do vetor
    return chave % 262139;
}

int main(void){ 
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        v[hashn(t)] = t;
    }
    int c;
    while(scanf("%d", &c) == 1){
        int t = hashn(c); // t recebe indice de c
        if(v[t] == c)
            printf("sim\n");
        else if(v[t] == 0)
            printf("nao\n");
        else if(v[t] != c)
            printf("Colisão socorro\n");
    }

    return 0;
}