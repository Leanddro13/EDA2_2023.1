/*
Codigo feito pelo professor e Bruno Ribas

*/
#include<stdio.h>
#define SIZE ((1<<20) + 10)
char strcontainer[SIZE * 2 + 100];

int main(void){
    char *str = &strcontainer[SIZE];
    int S, C, min = 0, max = 0, offset;
    scanf("%d %c", &S, &C);

    offset = S;
    str[0] = C;

    while(scanf("%d %c", &S, &C) != EOF){
        S -= offset;
        str[S] = C;
        if(S<min) min = S;
        if(S>max) max = S;
    }
    str[max+1] = '\0';
    printf("%s\n", &str[min]);

    return 0;
}