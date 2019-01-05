#include <stdio.h>

int main(int argc, char *argv[])
{    
        long long t = 0;
        long long k = 0;

        scanf("%lli", &t);
        long long i = 0;
        for(i = 0; i < t; i++) {
                scanf("%lli", &k);
                printf("%lli\n", 250 * k - 58);
        }

        return 0;
}
