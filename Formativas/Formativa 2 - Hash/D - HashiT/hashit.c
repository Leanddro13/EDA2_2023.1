#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 101
// Código do prof. Bruno Ribas

char *hashtable[TAM];

int hash(char *key, int len){
    int r = 0;

    for(int i = 0; i < len; ++i){
        r += (key[i]*(i+1)) % TAM;
    }

    return (19*r) % TAM;
}


int main(){
    int t, n, pos, flag, len, count;
    char string[30], command, *key;
    scanf("%d", &t);

    while(t--){
        count = 0;
        for(int i = 0; i < n; i++){
            hashtable[i] = NULL;
        }
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            scanf("%s", string);
            key = &string[4];
            command = string[0];

            len = strlen(key);

            if(command == 'A'){
                flag = 1;
                for(int j = 0; j < 20; ++j){
                    pos = (hash(key, len) + j*j + 23*j) % TAM;

                    if(hashtable[pos] != NULL && strcmp(key, hashtable[pos]) == 0){
                        flag = 0;
                        break;
                    }
                }

                if(flag){
                    for(int j = 0; j < 20; ++j){
                        pos = (hash(key, len) + j*j + 23*j) % TAM;

                        if(hashtable[pos] == NULL){
                            hashtable[pos] = malloc(sizeof(char) * (len+1));
                            strcpy(hashtable[pos], key);
                            count++;
                            break;
                        }
                    }
                }

            }
            else if(command == 'D'){
                for(int j = 0; j < 20; ++j){
                    pos = (hash(key, len) + j*j + 23*j) % TAM;
                    if(hashtable[pos] != NULL && strcmp(hashtable[pos], key) == 0){
                        free(hashtable[pos]);
                        hashtable[pos] = NULL;
                        count--;
                        break;
                    }
                }
            }
        }
        printf("%d\n", count);
        for(int i = 0; i < TAM; ++i){
            if(hashtable[i] != NULL){
                printf("%d:%s\n", i, hashtable[i]);
            }
        }
    }

    return 0;
}