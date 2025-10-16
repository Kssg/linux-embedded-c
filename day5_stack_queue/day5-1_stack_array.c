#include <stdio.h>
#include <stdbool.h>

#define capacity 10
int top = 0;
int stack[capacity];

bool isEmpty() {
    return top == 0;
}

bool isFull() {
    return top == capacity;
}
void push(int x) {
    if (isFull()) {
        printf("Stack is Full!\n");
        return;
    }
    stack[top++] = x;
}

int pop() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
        return -1;
    }
    return stack[--top];
}


int main() {
    push(1);
    push(2);
    push(3);
    printf("stack is empty: %d\n", isEmpty());
    printf("stack is full: %d\n", isFull());
    printf("val of top: %d\n", pop());
    printf("val of top: %d\n", pop());
    printf("val of top: %d\n", pop());
    printf("stack is empty: %d\n", isEmpty());
    return 0;
}
