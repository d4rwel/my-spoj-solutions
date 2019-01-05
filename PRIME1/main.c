/*
 * PRIME1
 *
 * algorithm: sieve of eratosthenes, brute-force
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

unsigned int *primeTable = NULL;
int lenPrimeTable = 0;

// Sieb des Erathostenes
void doPrimeTable()
{
        int i = 0;
        int j = 0;
        unsigned int *help = NULL;

        typedef struct {
                int value;
                bool marked;
                bool isPrime;
        } Numbers;

        int array_len = (int)(sqrt(1000000000.0));
        assert(array_len = 31622);

        Numbers *numbers = malloc(array_len * sizeof(Numbers));
        Numbers *number = numbers;
        assert(numbers);
        // Array of pointers to numbers
        // last element : ptr[31621]
        // guard element : ptr[31622]
        Numbers *ptr[array_len+1];

        // Initialize ptr and number
        for(i = 0; i < array_len; i++, number++) {
         
                ptr[i] = number;
                (*number).value = i + 2;
                assert((i + 2) <=  31623);
                (*number).marked = false;
                (*number).isPrime = false;
        }
        ptr[array_len] = NULL;

        // Find primes
        number = numbers;
        for(i = 0; i < array_len; i++, number++) {

                if(!(*number).marked) {
                
                        (*number).isPrime = true;
                        j = i;
                        while(ptr[j]) {

                                if(((*ptr[j]).value % (*number).value) == 0)
                                        (*ptr[j]).marked = true;
                                j++;
                        }
                }
        }

        i = 0;
        while(ptr[i]) {

                if((*ptr[i]).isPrime) {
                        lenPrimeTable++;
                        assert((*ptr[i]).value != 0);
                }
                i++;
        }
        primeTable = malloc(lenPrimeTable * sizeof(unsigned int));
        help = primeTable;
        i = 0;
        while(ptr[i]) {

                if((*ptr[i]).isPrime) {
                        *help = (*ptr[i]).value;               
                        assert(*help != 0);
                        help++;
                }
                i++;
        }

        free(numbers);
}

bool isPrime(unsigned int number)
{
        if(number == 1) return false;

        unsigned int max = (int)(sqrt(number)); 
        unsigned int *ptr = primeTable;

        while(*ptr <= max) {
                if(number % *ptr == 0) return false;
                ptr++;
        }

        return true;
}

int main(int argc, char *argv[]) 
{
        int i = 0;
        // Number of test cases
        unsigned short t = 0;         
        // List of test cases * (Number 1 and 2)
        unsigned int m[10];
        unsigned int n[10];
        unsigned int j;

        // Read number of test cases from stdin 
        scanf("%hu", &t);
        // Check t <= 10
        if(t > 10) {
               return 1;
        }
        
        // Read list of Numbers
        for(i = 0; i < t; i++) {

                scanf("%u %u", &m[i], &n[i]);
                // Check Numbers for m <= n <= 1000000000
                // and n - m <= 100000
                if(((m[i] > n[i]) && (n[i] > 1000000000))
                                || ((n[i] - m[i]) > 100000)) {
                        return 1;
                }
        }

        // Algorithm for finding primes - simplest method
        doPrimeTable();
        for(i = 0; i < t; i++) {

                for(j = m[i]; j <= n[i]; j++) {
                        if(isPrime(j)) printf("%u\n", j);
                }
                printf("\n");
        }

        free(primeTable);
        return 0;
}
