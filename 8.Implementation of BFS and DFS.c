#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices in the graph

// Queue structure for BFS
typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function prototypes
void initQueue(Queue* q);
int isQueueEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);

void BFS(int graph[MAX][MAX], int vertices, int start);
void DFS(int graph[MAX][MAX], int vertices, int start, int visited[]);

int main() {
    int graph[MAX][MAX];
    int vertices, edges, u, v, start;
    int choice;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Initialize the graph adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;  // For undirected graph
    }

    while (1) {
        printf("\nGraph Traversals:\n");
        printf("1. BFS\n");
        printf("2. DFS\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter starting vertex for BFS: ");
                scanf("%d", &start);
                BFS(graph, vertices, start);
                break;
            case 2: {
                int visited[MAX] = {0};  // Initialize visited array
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &start);
                printf("DFS Traversal: ");
                DFS(graph, vertices, start, visited);
                printf("\n");
                break;
            }
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Queue functions for BFS
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue Underflow!\n");
        exit(1);
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;  // Reset queue
    } else {
        q->front++;
    }
    return item;
}

// BFS implementation
void BFS(int graph[MAX][MAX], int vertices, int start) {
    int visited[MAX] = {0};
    Queue q;
    initQueue(&q);

    printf("BFS Traversal: ");
    enqueue(&q, start);
    visited[start] = 1;

    while (!isQueueEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS implementation
void DFS(int graph[MAX][MAX], int vertices, int start, int visited[]) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < vertices; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            DFS(graph, vertices, i, visited);
        }
    }
}
