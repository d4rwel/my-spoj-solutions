#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NODES 10000

int getRandom(void) {
    return (rand() % NODES) + 1;
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    printf("%d %d\n", NODES, NODES - 1);

    for (int i = 1; i <= NODES - 1; i++) {
        printf("%d %d\n", getRandom(), getRandom());
    }

    return 0;
}
