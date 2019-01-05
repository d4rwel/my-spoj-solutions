#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        int count;
        scanf("%i", &count);

        while(count--) {
                char input[3][20];
                scanf("\n%s + %s = %s", input[0], input[1], input[2]);
                
                int equation[3] = { -1, -1, -1 };
                int i;
                for(i = 0; i <= 2; i++) {
                        if(!strstr(input[i], "machula"))
                                equation[i] = atoi(input[i]);               
                }

                if(equation[0] == -1) 
                        equation[0] = equation[2] - equation[1];
                if(equation[1] == -1)
                        equation[1] = equation[2] - equation[0];
                if(equation[2] == -1)
                        equation[2] = equation[0] + equation[1];

                printf("%i + %i = %i\n", equation[0], equation[1], equation[2]);
        }

        return 0;
}
