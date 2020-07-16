#include <stdio.h>
#include <stdlib.h>

#define NUM_SIZE 1000001

void mirror(char *bignum, int length) {
    int left = length - 1;
    int right = 0;
    while(left > right) {
        bignum[right] = bignum[left];
        left -= 1;
        right += 1;
    }
}

void palindrom(char *bignum, int *length) {
    if(*length == 1) {
        bignum[0] = 1;
        bignum[1] = 1;
        *length = 2;
    } else {
        int mid = *length / 2;
        int left = 0;
        if(*length % 2 == 0) {
            left = mid;
        } else {
            left = mid + 1;
        }
        int right = mid - 1;
        while(right != -1 && bignum[left] == bignum[right]) {
            left = left + 1;
            right = right - 1;
        }
        if(right == -1) {
            right = right + 1;
        }
        if(bignum[left] > bignum[right]) {
            mirror(bignum, *length);
        } else if(bignum[left] < bignum[right]) {
            while((bignum[mid] = (bignum[mid] + 1) % 10) == 0 ) {
                mid++;
            }
            int i = NUM_SIZE;
            while(bignum[i] == 0) {
                if(i == 0) {
                    break;
                }
                i--;
            }
            *length = i + 1;
            mirror(bignum, *length);
        }
    }
}

void show(char *num, int length) {
    int i = 0;
    for(i = length - 1; i >= 0; i--) {
        printf("%i", num[i]);
    }
    printf("\n");
}


int main(int argc, char *argv[]) {
    int t = 0;
    scanf("%i\n", &t);

    int i = 0;
    for(i = 0; i < t; i++) {
        char bignum[NUM_SIZE + 1] = { 0 };
        char c;

        while((c = getchar()) == '0')
            ;
        int j = 0;
        bignum[j++] = c - 48;
        while((c = getchar()) != '\n' && c != EOF) {
            bignum[j++] = c - 48;
        }

        int len = j;
        int buf;
        int mid = len % 2 == 0 ? len / 2 - 1 : len / 2 ;
        for(j = 0; j <= mid;  j++) {
            buf = bignum[j];
            bignum[j] = bignum[len - j - 1];
            bignum[len - j - 1] = buf;
        }

        palindrom(bignum, &len);
        show(bignum, len);
    }

    return 0;
}
