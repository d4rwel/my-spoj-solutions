#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_MEMBERS 2000000LL
#define DISTANCE 3
#define START 1000000LL

int main(int argc, char *argv[]) {
    clock_t begin, finish;
    double time1, time2;

    long long n = NUM_MEMBERS;
    long long d = DISTANCE;
    long long start = START;
    long long end = START + ((NUM_MEMBERS - 1) * DISTANCE);

    begin = clock();
    for(long long i = 0; i < n; i++) {
        printf("%lld ", start + (i * d));
    }
    finish = clock();
    time1 = (double)(finish - begin) / CLOCKS_PER_SEC;

    begin = clock();
    for(long long i = start; i <= end; i += d) {
        printf("%lld ", i);
    }
    finish = clock();
    time2 = (double)(finish - begin) / CLOCKS_PER_SEC;

    printf("\ntime1: %g\ntime2: %g\n", time1, time2);

    return 0;
}
