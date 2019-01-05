#include <stdio.h>

int main(int argc, char *argv[])
{
        float min_dist = 0.0;

        while(scanf("%f", &min_dist) && min_dist != 0.0) {
                float dist = 0.0;
                int i = 2;
                while(dist < min_dist){ 
                        dist += 1.0 / i++;
                }
                printf("%i card(s)\n", i - 2);
        }

        return 0;
}
