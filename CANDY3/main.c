#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_candy_dividable(unsigned long long numChild, unsigned long long *arrayCandy)
{
        unsigned long long i = 0;
        unsigned long long sum = 0;
        
        for(i = 0; i < numChild; i++) {
                sum = (sum % numChild) + (arrayCandy[i] % numChild);
        }

        if(sum % numChild != 0)
                return false;
        else
                return true;
}

int main(int argc, char *argv[])
{
        unsigned long long T = 0;
        scanf("%lli", &T);

        unsigned long long i = 0;
        for(i = 0; i < T; i++) {
                printf("\n");
                unsigned long long N = 0;
                scanf("%lli", &N);

                unsigned long long *array = malloc(N * sizeof(unsigned long long));

                unsigned long long j = 0;
                for(j = 0; j < N; j++)
                        scanf("%lli", &array[j]);
                if(is_candy_dividable(N, array))
                        printf("YES\n");
                else
                        printf("NO\n");
        }

        return 0;
}
