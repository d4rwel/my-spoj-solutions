#include <stdio.h>
#include <stdlib.h>

int compare(const void *p1, const void *p2) {
    int x = *(int *)p1;
    int y = *(int *)p2;
    return x <= y ? (x < y ? 1 : 0) : -1;
}

int count_borrows(int *array, int minsum, int countfriends) {
    qsort(array, countfriends, sizeof(int), compare);
    int sum = 0;
    int i = 0;
    while(sum < minsum && i < countfriends) {
        sum = sum + array[i];
        i++;
    }
    if(sum >= minsum) {
        return i;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    int num_scenes;
    int scene = 1;
    scanf("%i", &num_scenes);

    while(num_scenes > 0) {
        num_scenes--;
        int minsum;
        int count_friends;
        scanf("%i %i", &minsum, &count_friends);

        int *array_stamps = malloc(count_friends * sizeof(int));
        int i;
        for(i = 0; i < count_friends; i++) {
            scanf("%i", &(array_stamps[i]));
        }

        printf("Scenario #%i:\n", scene++);

        int result;
        if((result = count_borrows(array_stamps, minsum, count_friends)) == 0) {
            printf("impossible");
        } else {
            printf("%i", result);
        }
        printf("\n\n");

        free(array_stamps);
    }

    return 0;
}
