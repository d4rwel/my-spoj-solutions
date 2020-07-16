#include <stdio.h>

int main(int argc, char *argv[]) {
    int N = 0;
    int x = 0;
    int y = 0;
    int i = 0;

    scanf("%d", &N);

    for(i = 1; i <= N; i++) {
        scanf("%d %d", &x, &y);
        if(x == y) {
            if(x % 2 == 0) {
                printf("%d\n", 2 * x);
            } else {
                printf("%d\n", 2 * x - 1);
            }
        } else if(x - y == 2) {
            if(x % 2 == 0) {
                printf("%d\n", x + y);
            } else {
                printf("%d\n", x + y - 1);
            }
        } else {
            printf("No Number\n");
        }
    }

    return 0;
}
