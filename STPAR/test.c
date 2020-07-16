#include <stdio.h>

int main(void) {
    char line[] = "100 185 400 11 1000";
    char *data = line;
    int offset;
    int n;
    int sum = 0;

    while (sscanf(data, " %d%n", &n, &offset) == 1) {
        sum += n;
        data += offset;
        printf("read: %5d; sum = %5d; offset = %5d\n", n, sum, offset);
    }

    printf("sum = %d\n", sum);
    return 0;
}
