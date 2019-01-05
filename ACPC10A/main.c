#include <stdio.h>

int main(int argc, char *argv[])
{
        int x1, x2, x3;

        while(scanf("%i %i %i", &x1, &x2, &x3)) {
                if(x1 == 0 && x2 == 0 && x3 == 0) return 0;
                if(x2 - x1 == x3 - x2)
                        printf("AP %i\n", (x2 - x1) + x3);
                else
                        printf("GP %i\n", (x2 / x1) * x3);
        }

        return 0;
}
