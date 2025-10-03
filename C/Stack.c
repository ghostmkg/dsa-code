//stack implementation using array in C
#include <stdio.h>
#define MAX 100

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

void init(Stack* s) { s->top = -1; }

int isEmpty(Stack* s) { return s->top == -1; }
int isFull(Stack* s) { return s->top == MAX - 1; }

void push(Stack* s, int val) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = val;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

int peek(Stack* s) {
    if (!isEmpty(s)) return s->arr[s->top];
    return -1;
}

int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", peek(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));

    return 0;
}
