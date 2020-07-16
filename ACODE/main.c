#include <stdio.h>

#define FIB_CAP 92

unsigned long long fib_seq[FIB_CAP];

void fibonacci(int x) {
    fib_seq[0] = 1;
    fib_seq[1] = 2;
    int i;
    for(i = 2; i < x; i++) {
        fib_seq[i] = fib_seq[i - 1] + fib_seq[i - 2];
    }
}

unsigned long long decode_cipher(char *cipher) {
    int i = 0;
    int len = 1;
    unsigned long long result = 1;
    while(cipher[i] != '\0') {
        int digit = cipher[i] - 48;
        if(digit < 3 && digit > 0) {
            if(cipher[i + 1] == '\0') {
                result *= fib_seq[len - 1];
            }
            len++;
        } else {
            if(digit == 0 && len > 2) {
                len -= 2;
            } else if(digit == 0 && len <= 2) {
                len = 1;
            }
            result *= fib_seq[len - 1];
            len = 1;
        }
        i++;
    }
    return result;
}

int main(int argc, char *argv[]) {
    fibonacci(FIB_CAP);

    char input[5010];
    while(scanf("%s", input) && input[0] != '0') {
        printf("%llu\n", decode_cipher(input));
    }


    return 0;
}
