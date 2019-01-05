#include <stdio.h>
#include <stdbool.h>

bool does_loop_stop(unsigned long long number)
{
        bool result = true;
        while(number != 2 && number > 1) {
                if(number % 2 != 0) {
                        result = false;
                        break;
                } else 
                        number /= 2;
        }
        return result;
}


int main(int argc, char *argv[])
{
        unsigned long long number;
        scanf("%llu", &number);

        if(does_loop_stop(number))
                printf("TAK\n");
        else
                printf("NIE\n");

        return 0;
}
