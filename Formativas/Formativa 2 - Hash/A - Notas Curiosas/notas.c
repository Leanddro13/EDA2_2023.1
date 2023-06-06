#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1010

int main()
{
    int n;
    scanf("%d", &n);

    int freq[MAX_N] = {0}; // vetor de frequências

    // leitura dos valores e atualização das frequências
    int x, max_freq = 0, max_value = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        freq[x]++;
        if (freq[x] > max_freq || (freq[x] == max_freq && x > max_value))
        {
            max_freq = freq[x];
            max_value = x;
        }
    }

    printf("%d\n", max_value); // impressão do valor com maior frequência

    return 0;
}
