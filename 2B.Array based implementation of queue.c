#include <stdio.h>
#define MAX 100 // Maximum size of the queue

// Queue structure
typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

// Function prototypes
void initialize(Queue *q);
int isFull(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int element);
int dequeue(Queue *q);
int peek(Queue *q);
void display(Queue *q);

int main() {
    Queue queue;
    int choice, element;

    initialize(&queue);

    while (1) {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(&queue, element);
                break;
            case 2:
                element = dequeue(&queue);
                if (element != -1) {
                    printf("Dequeued element: %d\n", element);
                }
                break;
            case 3:
                element = peek(&queue);
                if (element != -1) {
                    printf("Front element: %d\n", element);
                }
                break;
            case 4:
                display(&queue);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Initialize the queue
void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

// Enqueue an element into the queue
void enqueue(Queue *q, int element) {
    if (isFull(q)) {
        printf("Queue overflow! Cannot enqueue element.\n");
    } else {
        if (q->front == -1) { // If the queue is initially empty
            q->front = 0;
        }
        q->arr[++(q->rear)] = element;
        printf("Element enqueued successfully.\n");
    }
}

// Dequeue an element from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow! Cannot dequeue element.\n");
        return -1;
    } else {
        return q->arr[(q->front)++];
    }
}

// Peek at the front element of the queue
int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No front element.\n");
        return -1;
    } else {
        return q->arr[q->front];
    }
}

// Display the elements of the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}
