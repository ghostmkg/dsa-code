#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure for BFS
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Initialize queue
void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(struct Queue *q) {
    return q->front == -1;
}

// Enqueue element
void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX - 1)
        printf("Queue is full!\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Dequeue element
int dequeue(struct Queue *q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
            q->front = q->rear = -1;
        return item;
    }
}

// BFS function
void bfs(int adj[MAX][MAX], int vertices, int start) {
    struct Queue q;
    initQueue(&q);

    int visited[MAX] = {0};
    visited[start] = 1;
    enqueue(&q, start);

    printf("BFS Traversal starting from vertex %d: ", start);

    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        // Visit all adjacent vertices
        for (int i = 0; i < vertices; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices, edges;
    int adj[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // comment this line for directed graph
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(adj, vertices, start);

    return 0;
}
