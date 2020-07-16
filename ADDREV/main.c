#include <stdio.h>
#include <stdlib.h>

unsigned int Reverse_Number(unsigned int num) {
    unsigned int reversed = 0;

    while(num > 0) {
        reversed *= 10;
        reversed += num % 10;
        num = (unsigned int)(num / 10);
    }

    return reversed;
}

int main(int argc, char *argv[]) {
    int i = 0;

    short int N = 0;
    unsigned int *num1 = NULL;
    unsigned int *num2 = NULL;
    unsigned int *ptr1 = NULL;
    unsigned int *ptr2 = NULL;

    scanf("%hd", &N);
    if(N > 10000) {
        return 1;
    }

    num1 = malloc(N * sizeof(unsigned int));
    num2 = malloc(N * sizeof(unsigned int));
    if(num1 == NULL) {
        return -1;
    }
    if(num2 == NULL) {
        return -1;
    }
    ptr1 = num1;
    ptr2 = num2;

    for(i = 1; i <= N; i++, ptr1++, ptr2++) {
        scanf("%u %u", ptr1, ptr2);
    }

    ptr1 = num1;
    ptr2 = num2;

    for(i = 1; i <= N; i++, ptr1++, ptr2++) {

        printf("%u\n",
               Reverse_Number(Reverse_Number(*ptr1) + Reverse_Number(*ptr2)));
    }

    free(num1);
    free(num2);
    return 0;
}
