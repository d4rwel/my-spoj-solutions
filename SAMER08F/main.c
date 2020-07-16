#include <stdio.h>

int main(int argc, char *argv[]) {
    int i = 0;
    short int N = 0;
    unsigned int output = 0;

    while(scanf("%hd", &N) && N != 0) {
        output = 0;
        for(i = 1; i <= N; i++) {
            output += i * i;
        }
        printf("%u\n", output);
    }

    return 0;
}
