#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

struct stack {
    int elements[1000];
    int count;
};

bool is_organizable (char *line, int n);
int first(struct stack *stack);
bool is_empty (struct stack *stack);
int push (struct stack *stack, int element);
int pop (struct stack *stack);


int main (int argc, const char *argv[]) {
    int n;
    size_t len = 0;
    char *line = NULL;


    getline(&line, &len, stdin);
    sscanf(line, "%d", &n);

    while (n != 0) {
        getline(&line, &len, stdin);

        if(is_organizable(line, n)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }

        getline(&line, &len, stdin);
        sscanf(line, "%d", &n);
    }

    free(line);

    return 0;
}

bool is_organizable (char *line, int n) {
    struct stack side_street;
    side_street.count = 0;

    int count = 1;
    int truck = 0;
    int offset = 0;

    for(int i = 0; i < n; i++) {
        sscanf(line, "%d%n", &truck, &offset);
        line += offset;
        if (truck != count) {
            while (!is_empty(&side_street)
                    && first(&side_street) < truck) {
                pop(&side_street);
                count++;
            }
            push(&side_street, truck);
        } else {
            count++;
        }
    }

    while (!is_empty(&side_street)) {
        if (pop(&side_street) == count) {
            count++;
        } else {
            return false;
        }
    }

    return true;
}

int first(struct stack *stack) {
    if (is_empty(stack)) {
        return -1;
    }

    return stack->elements[stack->count - 1];

}

bool is_empty (struct stack *stack) {
    if (stack->count == 0) {
        return true;
    } else {
        return false;
    }
}

int push (struct stack *stack, int element) {
    stack->elements[stack->count] = element;
    stack->count++;

    return 0;
}

int pop (struct stack *stack) {
    int ret;

    if (is_empty(stack)) {
        return -1;
    }

    ret = first(stack);
    stack->count--;
    return ret;
}
