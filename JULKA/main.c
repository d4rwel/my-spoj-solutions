#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEC 101

void string_to_arrnum(char *string, char *arrnum)
{
        int j = MAX_DEC - strlen(string);
        int i = 0;
        for(i = 0; i < strlen(string); i++) {
                arrnum[i + j] = string[i] - '0';
        }
}

void print_arrnum(char *arrnum)
{
        int i = 0;
        do { 
                i++;
                if((i == MAX_DEC-1) && arrnum[i] == 0)
                {
                        printf("0\n");
                        return;
                }
        }
        while(arrnum[i] == 0);

        
        while(i < MAX_DEC) {
                printf("%i", arrnum[i++]);
        }
        printf("\n");
}

void division(char *arrnum, int arrsize, int carry)
{
        if(arrsize < 0)
                return;
        else if(arrnum[MAX_DEC - arrsize] % 2 == 0)
                division(arrnum, arrsize-1, 0);
        else
                division(arrnum, arrsize-1, 1);

        if(carry)
                arrnum[MAX_DEC - arrsize] = (arrnum[MAX_DEC - arrsize] + 10) / 2;
        else
                arrnum[MAX_DEC - arrsize] = arrnum[MAX_DEC - arrsize] / 2;
}

void addition(char *arrnum1, char *arrnum2)
{
        int carry = 0;
        int i = 0;
        char *arrnum = calloc(MAX_DEC, sizeof(char));

        for(i = MAX_DEC-1; i >= 0; i--) {
                arrnum[i] = (arrnum1[i] + arrnum2[i] + carry) % 10;
                carry = (arrnum1[i] + arrnum2[i] + carry) / 10;
        }
        for(i = 0; i < MAX_DEC; i++) 
                arrnum1[i] = arrnum[i];

        free(arrnum);
}

void subtraction(char *arrnum1, char *arrnum2)
{
        int carry = 0;
        int i = 0;
        char *arrnum = calloc(MAX_DEC, sizeof(char));

        for(i = MAX_DEC-1; i >= 0; i--) {
                if(arrnum1[i] < (arrnum2[i] + carry)) {
                        arrnum[i] = ((10 + arrnum1[i]) - arrnum2[i] - carry);
                        carry = 1;
                } else {
                        arrnum[i] = arrnum1[i] - arrnum2[i] - carry;
                        carry = 0;
                }
        }
        for(i = 0; i < MAX_DEC; i++) 
                arrnum1[i] = arrnum[i];

        free(arrnum);
}


int main(int argc, char *argv[]) 
{
        int i = 0;
        for(i = 0; i < 10; i++) {
                char sum[103];
                char diff[103];
                scanf("%s", sum);
                scanf("%s", diff);
                char *sumnum = calloc(MAX_DEC, sizeof(char));
                char *diffnum = calloc(MAX_DEC, sizeof(char));
                char *K = calloc(MAX_DEC, sizeof(char));
                string_to_arrnum(sum, sumnum);
                string_to_arrnum(diff, diffnum);
                // Klaudia
                addition(diffnum, sumnum);
                division(diffnum, MAX_DEC, 0);
                int j = 0;
                for(j = 0; j < MAX_DEC; j++)
                        K[j] = diffnum[j];
                print_arrnum(K);
                // Natalia
                subtraction(sumnum, K);
                print_arrnum(sumnum);

                free(sumnum);
                free(diffnum);
                free(K);
        }
        return 0;
}
