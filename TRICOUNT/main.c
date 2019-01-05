#include <stdio.h>

int main(int argc, char *argv[])
{
        int T;
        scanf("%i", &T);

        while(T > 0) {
                T--;
                int N;
                scanf("%i", &N);
                unsigned long long result; 
                result = N;
                result *= N + 2;
                result *= 2*N + 1;
                result /= 8;
                printf("%llu\n", result);
        }

        return 0;
}
