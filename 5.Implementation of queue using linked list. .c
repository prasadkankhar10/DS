#include <stdio.h>
#include <stdlib.h>

// Node structure for queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
void enqueue(Node** front, Node** rear, int data);
int dequeue(Node** front, Node** rear);
int peek(Node* front);
int isEmpty(Node* front);
void displayQueue(Node* front);

int main() {
    Node* front = NULL; // Initialize front and rear
    Node* rear = NULL;
    int choice, data;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&front, &rear, data);
                break;
            case 2:
                if (!isEmpty(front)) {
                    printf("Dequeued element: %d\n", dequeue(&front, &rear));
                } else {
                    printf("Queue is empty!\n");
                }
                break;
            case 3:
                if (!isEmpty(front)) {
                    printf("Front element: %d\n", peek(front));
                } else {
                    printf("Queue is empty!\n");
                }
                break;
            case 4:
                displayQueue(front);
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

// Enqueue operation
void enqueue(Node** front, Node** rear, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("Enqueued %d to the queue.\n", data);
}

// Dequeue operation
int dequeue(Node** front, Node** rear) {
    if (*front == NULL) {
        printf("Queue underflow!\n");
        return -1;
    }
    Node* temp = *front;
    int dequeuedData = temp->data;
    *front = temp->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return dequeuedData;
}

// Peek operation
int peek(Node* front) {
    return front->data;
}

// Check if the queue is empty
int isEmpty(Node* front) {
    return front == NULL;
}

// Display queue
void displayQueue(Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    Node* temp = front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
