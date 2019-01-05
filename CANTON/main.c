#include <stdio.h>
#include <stdbool.h>

typedef struct {
        int dividend;
        int divisor;
} Frac;

Frac get_cantor_count(int number)
{
        int dividend = 1;
        int divisor = 1;
        int direction = -1;

        while(number > 1) {
                if(dividend == 1 && direction == -1) {
                        divisor++;
                        direction = 1;
                } else if(divisor == 1 && direction == 1) {
                        dividend++;
                        direction = -1;
                } else {
                        dividend += direction;
                        divisor -= direction;
                }
                number--;
        }

        Frac result;
        result.dividend = dividend;
        result.divisor = divisor;
        return result;
}


int main(int argc, char *argv[])
{
        int t;
        scanf("%i", &t);

        while(t--) {
                int number;
                Frac result;
                scanf("%i", &number);
                result = get_cantor_count(number);
                printf("TERM %i IS %i/%i\n", number, result.dividend, result.divisor);                
        }

        return 0;
}
