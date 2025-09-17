#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 在 linked list 最前端 插入一個節點。
// 新節點的 data 設成傳入的 value。
// 新節點的 next 指向舊的 head。
// 更新 head 讓它指向新節點。
// 複製過來的，怎麼改？
void insert_front(Node **head, int value) {
    Node *newHead = malloc(sizeof(Node));
    newHead->data = value;
    newHead->next = *head;
    *head = newHead; // 這裡直接改「外層的 head」
}

void free_list(Node *head) {
    Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    /* Node *head = malloc(sizeof(Node)); // value defaults to 0 */
    Node *head = NULL;

    // use insert_front to insert nodes

    /* Node *cur = head; */
    /* cur->next = malloc(sizeof(Node)); */
    /* cur = cur->next; */
    /* cur->data = 1; */
    
    insert_front(&head, 3);
    insert_front(&head, 2);
    insert_front(&head, 1);
    printf("Before insert: \n");
    Node *cur = head;
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");

    insert_front(&head, 99);
    printf("\nAfter insert: \n");
    
    cur = head;
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
    
    free_list(head);

    return 0;
}
