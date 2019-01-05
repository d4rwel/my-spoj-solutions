#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        int i = 0;
        int j = 0;
        int k = 1;
        int T = 0;
        unsigned int* N = NULL;
        unsigned int* ptr = NULL;
        unsigned int Z = 0;

        scanf("%d", &T);
        if(T > 100000) return 1;

        N = malloc(T * sizeof(unsigned int));
        if(N == NULL) return -1;

        ptr = N;

        for(i = 1; i <= T; i++, ptr++) 
        {
                scanf("%u", ptr);
                if(*ptr < 1 || *ptr > 1000000000) return 1;
        }

        ptr = N;

        for(i = 1; i <= T; i++, ptr++)
        {
                k = 1;
                Z = 0;
                while(*ptr % (int)(pow((double)(5), k)) != *ptr) 
                        k++;
                for(j = 1; j < k; j++) {
                        
                        Z += (unsigned int)(*ptr / (unsigned int)(pow((double)(5), (double)j)));
                }
                printf("%u\n", Z);
        }

        free(N);

        return 0;
}
