#include <stdio.h>

int arrangement(int x, int y) {
    int swap;
    int add = 0;
    if (x == 0 && y == 0) {
        return 0;
    } else if (x == y) {
        return 1;
    } else if (x < y) {
        swap = x;
        x = y;
        y = swap;
    }

    y++;
    if (x % y != 0) {
        add = 1;
    }
    return (x / y) + add;
}

int main(int argc, char const *argv[]) {
    int x = 0;
    int y = 0;

    scanf("%d %d", &x, &y);

    while (x != -1 && y != -1) {

        printf("%d\n", arrangement(x, y));

        scanf("%d %d", &x, &y);
    }

    return 0;
}
