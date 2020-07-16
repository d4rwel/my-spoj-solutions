#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_ambi_perm(int *permutation, int len) {
    int i;
    for(i = 1; i <= len; i++) {
        if(i != permutation[i] && permutation[permutation[i]] != i) {
            return false;
        }
    }
    return true;
}


int main(int argc, char *argv[]) {
    int len;
    while(scanf("%i", &len) && len != 0) {
        int *permutation = malloc((len + 1) * sizeof(int));

        int i;
        for(i = 1; i <= len; i++) {
            scanf("%i", &permutation[i]);
        }

        if(is_ambi_perm(permutation, len)) {
            printf("ambiguous\n");
        } else {
            printf("not ambiguous\n");
        }

        free(permutation);
    }

    return 0;
}
