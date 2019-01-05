#include <stdio.h>

int main(int argc, char *argv[])
{
    int num_cases = 0;
    long long min = 0;
    long long max = 0;
    long long sum = 0;

    scanf("%d", &num_cases);
    
    while(num_cases) {
        long long n = 0;
        long long d = 0;

        scanf("%lld %lld %lld", &min, &max, &sum);    

        n = sum*2/(min+max);
        d = (max-min)/(n-5);

        long long start = (min-2*d); 
        long long end = (max+2*d);

        printf("%lld\n", n);
    
        for(long long i = 0; i < n; i++)
            printf("%lld ", start+(i*d));
            /*
        for(long long i = start; i <= end; i+=d) 
            printf("%lld ", i);
*/
        printf("\n");

        num_cases--;
    }

    return 0;
}
