#define MAX_N 3037000499LL
#define MAX_TESTCASES 100
#define MAX_

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

typedef struct tripel {
    long long third;
    long long last_third;
    long long sum;
} tripel;

tripel *get_test_tripel(int start, int distance);

int main(int argc, char *argv[]) {

    tripel *result;
    srand(time(NULL));

    printf("%d\n", MAX_TESTCASES);
    for(int i = 1; i <= MAX_TESTCASES; i++) {

        int rand_start = rand() + 1;
        int rand_dist = rand() + 1;
        //printf("[INFO] %d %d\n", rand_start, rand_dist);
        result = get_test_tripel(rand_start, rand_dist);

        printf("%lld %lld %lld\n", result->third, result->last_third, result->sum);
        free(result);
    }

    return 0;
}

tripel *get_test_tripel(int start, int distance) {
    long long n = 0;
    long long offset = 0;
    tripel *test_tripel = malloc(sizeof(tripel));

    test_tripel->third = (long long)start + (long long)2 * distance;
    test_tripel->sum = offset = (long long)start;

    while (n < 10000) {
        offset += (long long)distance;
        test_tripel->sum += offset;
        n++;
    }

    test_tripel->last_third = offset - (long long)2 * distance;

    return test_tripel;
}
