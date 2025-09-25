#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} Queue;

bool isEmpty(Queue *q) {
    return q->head == NULL;
}

void initQueue(Queue *q) {
    q->head = q->tail = NULL;
}

void enqueue(Queue *q, int x) {
    Node *newNode = malloc(sizeof(Node));
    newNode->val = x;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->head = q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    Node *tmp = q->head;
    int res = tmp->val;

    q->head = tmp->next;
    if (q->head == NULL) {  // 如果移掉後空了，tail 也要設 NULL
        q->tail = NULL;
    }

    free(tmp);
    return res;
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Nothing to print!\n");
        return;
    }
    Node *cur = q->head;
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printQueue(&q);

    printf("dequeue: %d\n", dequeue(&q));
    printf("dequeue: %d\n", dequeue(&q));
    printf("dequeue: %d\n", dequeue(&q));
    printf("is empty: %d\n", isEmpty(&q));

    return 0;
}

