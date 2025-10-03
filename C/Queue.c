//circular queue implementation in C using array

#include <stdio.h>
#define MAX 100

typedef struct Queue {
    int arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) { q->front = q->rear = -1; }

int isEmpty(Queue* q) { return q->front == -1; }
int isFull(Queue* q) { return (q->rear + 1) % MAX == q->front; }

void enqueue(Queue* q, int val) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(q)) q->front = q->rear = 0;
    else q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = val;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front = (q->front + 1) % MAX;
    return val;
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    return 0;
}
