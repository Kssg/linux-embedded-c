#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

bool isEmpty(Node *head) {
    return head == NULL;
}

void add_node(Node **head, int val) {
    Node *new_node = malloc(sizeof(Node));
    new_node->val = val, new_node->next = NULL;

    while (*head) {
        head = &((*head)->next);
    }
    *head = new_node;
}

void delete_node(Node **head, int val) {
    if (isEmpty(*head)) {
        printf("List is empty!\n");
        return;
    }
    while (*head && (*head)->val != val) {
        head = &((*head)->next);
    }

    if (*head == NULL) {
        printf("Value not found!\n");
        return;
    }
    Node *tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

void print_list(Node *head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void free_list(Node *head) {
    while (head) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
}
int main() {
    // 用 add 來建立 list
    Node *cur = NULL;
    add_node(&cur, 1);
    add_node(&cur, 2);
    add_node(&cur, 3);
    print_list(cur);
    delete_node(&cur, 2);
    print_list(cur);
    free_list(cur);
}
