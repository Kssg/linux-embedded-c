#include <stdio.h>
#include <stdbool.h>

#define capacity 10

typedef struct {
    int data[capacity];
    int top;
} Stack;

void init(Stack *s) {
    s->top = 0;
}

bool isEmpty(Stack *s) {
    return s->top == 0;
}

bool isFull(Stack *s) {
    return s->top == capacity;
}

void push(Stack *s, int x) {
    if (isFull(s)) {
        printf("Stack is full!\n");
        return;
    }
    s->data[s->top++] = x;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->data[--s->top];
}

void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Nothing to print!\n");
        return;
    }
    for (int i = 0; i != s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

void check_parentheses(char *str) {
    Stack s;
    init(&s);
    for (char *t = str; *t != '\0'; t++) {
        if (*t == '(' || *t == '[' || *t == '{') {
            push(&s, *t);
        } else if (*t == ')') {
            char top = pop(&s);
            if (top != '(') {
                printf("Invalid\n");
                return;
            }
        } else if (*t == ']') {
            char top = pop(&s);
            if (top != '[') {
                printf("Invalid\n");
                return;
            }
        } else if (*t == '}') {
            char top = pop(&s);
            if (top != '{') {
                printf("Invalid\n");
                return;
            }
        }
    }
    if (!isEmpty(&s)) {
        printf("Invalid\n");
        return;
    }
    printf("Valid\n");
}


int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printf("Now stack have:\n");
    printStack(&s);

    printf("pop: %d\n", pop(&s));
    printf("pop: %d\n", pop(&s));
    printf("pop: %d\n", pop(&s));
    printf("is empty: %d\n", isEmpty(&s));

    check_parentheses("()[]{}");
    check_parentheses("([])");
    check_parentheses("([)]");
    check_parentheses(")(");
    check_parentheses("(((");
    check_parentheses("([]");
    return 0;
}
