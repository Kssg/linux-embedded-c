#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>

typedef struct Queue {
    int val;
    struct Queue *next;
} Queue;

bool isEmpty(Queue *q) {
    return q == NULL;
}

void enqueue(Queue **q, int x) {
    Queue **indirect = q;

    Queue *new = malloc(sizeof(Queue));
    new->val = x, new->next = NULL;

    while (*indirect)
        indirect = &((*indirect)->next);
    *indirect = new;
}

int dequeue(Queue **q) {
    if (isEmpty(*q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    Queue *tmp = *q;
    Queue **indirect = q;
    int res = tmp->val;
    
    *indirect = tmp->next;
    free(tmp);
    return res;
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Nothing to print!\n");
        return;
    }
    while (q != NULL) {
        printf("%d ", q->val);
        q = q->next;
    }
    printf("\n");
}

int main() {
    Queue *head = NULL;

    enqueue(&head, 10);
    enqueue(&head, 20);
    enqueue(&head, 30);

    printQueue(head);

    printf("dequeue: %d\n", dequeue(&head));
    printf("dequeue: %d\n", dequeue(&head));
    printf("dequeue: %d\n", dequeue(&head));
    printf("is empty: %d\n", isEmpty(head));
    return 0;
}
