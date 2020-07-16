#include <stdio.h>

int count_comp_rect(int numRect) {
    int count = numRect;
    int tempRect = 0;
    int i = 2;

    for(i = 2; i * i <= numRect; i++) {
        tempRect = i * i;
        while(tempRect <= numRect) {
            count++;
            tempRect += i;
        }
    }

    return count;
}

int main(int argc, char *argv[]) {
    int N = 0;

    scanf("%i", &N);
    if(N < 1 || N > 10000) {
        return 1;
    }

    printf("%i\n", count_comp_rect(N));

    return 0;
}
