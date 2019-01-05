#define PI_2 6.2831852
#include <stdio.h>

int main(int argc, char *argv[])
{
    int length = 0;
    double area = 0.0;

    scanf("%d", &length);

    while(length != 0) {

        area = (length * length) / PI_2;
        printf("%.2f\n", area);

        scanf("%d", &length);
    }
}
