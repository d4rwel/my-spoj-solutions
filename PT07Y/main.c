#include <stdio.h>
#include <stdlib.h>

typedef struct LListNode LListNode;
typedef struct Queue Queue;
typedef struct QueueNode QueueNode;
typedef enum {false, true} bool;
typedef enum {WHITE, GREY, BLACK} Color;

struct Queue {
    QueueNode *head;
    QueueNode *tail;
};

struct QueueNode {
    int data;
    QueueNode *next;
};

struct LListNode {
    int data;
    LListNode *next;
};

void linkedListAppend(LListNode **head, int data) {
    LListNode *newNode = malloc(sizeof(LListNode));

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void linkedListDestroy(LListNode **head) {
    LListNode *next;

    for (LListNode *curr = *head; curr != NULL; curr = next) {
        next = curr->next;
        free(curr);
    }
}

bool isQueueEmpty(Queue *q) {
    return (q->head == NULL && q->tail == NULL);
}

void enqueue(Queue *q, int data) {
    QueueNode *newNode = malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (isQueueEmpty(q)) {
        q->head = q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

int dequeue(Queue *q) {
    QueueNode *current = q->head;
    int ret = current->data;

    if (q->head == q->tail) {
        q->head = q->tail = NULL;
    } else {
        q->head = q->head->next;
    }

    free(current);
    return ret;
}

void queueDestroy(Queue *q) {
    while (!isQueueEmpty(q)) {
        dequeue(q);
    }
}

bool isTree(LListNode ***list, int nKnoten, int nKanten);

int main(int argc, const char *argv[]) {
    int nKnoten = 0;
    int nKanten = 0;
    int u = 0;
    int v = 0;
    LListNode **array = NULL;

    scanf("%d %d", &nKnoten, &nKanten);

    array = malloc(sizeof(LListNode *) * nKnoten);

    for (int i = 0; i < nKnoten; i++) {
        array[i] = NULL;
    }

    for (int i = 1; i <= nKanten; i++) {
        scanf("%d %d", &u, &v);

        linkedListAppend(&array[u - 1], v - 1);
        linkedListAppend(&array[v - 1], u - 1);
    }

    if (isTree(&array, nKnoten, nKanten)) {
        printf("YES");
    } else {
        printf("NO");
    }

    for (int i = 0; i < nKnoten; i++) {
        linkedListDestroy(&array[i]);
    }

    free(array);
    return 0;
}

bool isTree(LListNode ***list, int nKnoten, int nKanten) {
    int nBlacks = 0;
    int u = 0;
    int v = 0;
    Color *farbe = malloc(nKnoten * sizeof(Color));
    LListNode *list_ptr = NULL;
    Queue queue = {
        .head = NULL,
        .tail = NULL
    };

    farbe[0] = GREY;
    for (int i = 1; i < nKnoten; i++) {
        farbe[i] = WHITE;
    }

    if (nKnoten - 1 != nKanten) {
        goto false;
    }

    enqueue(&queue, 0);
    while (!isQueueEmpty(&queue)) {
        u = dequeue(&queue);
        list_ptr = (*list)[u];
        while (list_ptr != NULL) {
            v = list_ptr->data;
            if (farbe[v] == WHITE) {
                farbe[v] = GREY;
                enqueue(&queue, v);
            } else if (farbe[v] == GREY) {
                goto false;
            }

            list_ptr = list_ptr->next;
        }
        farbe[u] = BLACK;
        nBlacks++;
    }

    if (nBlacks < nKnoten) {
        goto false;
    }

    free(farbe);
    queueDestroy(&queue);
    return true;

false:
    free(farbe);
    queueDestroy(&queue);
    return false;
}
