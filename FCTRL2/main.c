#include <stdio.h>
#include <stdlib.h>
#include "../dbg.h"

#define MAX_DEC_DIGIT 158

void print_array(int *array, int size) {
    int i = 0;
    for(i = size - 1; i >= 0; i--) {
        printf("%i", array[i]);
    }
    printf("\n");
}

void factorial(int N) {
    int i = 0;
    int j = 0;
    int array[MAX_DEC_DIGIT] = { 1 };
    int size = 1;

    for(i = 1; i <= N; i++) {
        int carry_flag = 0;
        int carry = 0;
        for(j = 0; j < size; j++) {
            int prod = array[j] * i + carry;
            array[j] = prod % 10;
            carry = (int)(prod / 10);
            if(carry) {
                carry_flag++;
            }
        }
        while(carry) {
            array[size] = carry % 10;
            carry = (int)(carry / 10);
            size++;
        }
    }
    print_array(array, size);
}

int main(int argc, char *argv[]) {
    int i = 0;
    int T = 0;
    int N = 0;

    scanf("%i", &T);
    if(T < 1 || T > 100) {
        return 1;
    }

    for(i = 0; i < T; i++) {
        scanf("%i", &N);
        if(N < 1 || N > 100) {
            return 1;
        }

        factorial(N);
    }

    return 0;
}
