#include <stdio.h>
#include <stdlib.h>

int compare(const void *p, const void *q) {
    unsigned char x = *(const unsigned char *)p;
    unsigned char y = *(const unsigned char *)q;
    int ret;

    if(x == y) {
        ret = 0;
    } else {
        ret = (x < y) ? -1 : 1;
    }

    return ret;
}

int sum_hotness(unsigned char *ArrMen, unsigned char *ArrWomen, int ArrLen) {
    qsort(ArrMen, ArrLen, sizeof(ArrMen[0]), compare);
    qsort(ArrWomen, ArrLen, sizeof(ArrWomen[0]), compare);

    int sum = 0;
    int i = 0;
    for(i = 0; i < ArrLen; i++) {
        sum += ArrMen[i] * ArrWomen[i];
    }

    return sum;
}

int main(int argc, char *argv[]) {
    int t = 0;

    scanf("%i", &t);
    if(t == 0) {
        return 0;
    }

    int i = 0;
    for(i = 1; i <= t; i++) {
        int ArrLen = 0;
        scanf("%i", &ArrLen);
        if(ArrLen == 0) {
            continue;
        }

        unsigned char *ArrMen = malloc(ArrLen * sizeof(unsigned char));
        unsigned char *ArrWomen = malloc(ArrLen * sizeof(unsigned char));

        int j = 0;
        for(j = 0; j < ArrLen; j++) {
            scanf("%hhu", &ArrMen[j]);
        }
        for(j = 0; j < ArrLen; j++) {
            scanf("%hhu", &ArrWomen[j]);
        }

        printf("%i\n", sum_hotness(ArrMen, ArrWomen, ArrLen));

        free(ArrMen);
        free(ArrWomen);
    }

    return 0;
}
