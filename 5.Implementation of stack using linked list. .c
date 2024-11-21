#include <stdio.h>
#include <stdlib.h>

// Node structure for stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
void push(Node** top, int data);
int pop(Node** top);
int peek(Node* top);
int isEmpty(Node* top);
void displayStack(Node* top);

int main() {
    Node* stack = NULL; // Initialize stack as empty
    int choice, data;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                if (!isEmpty(stack)) {
                    printf("Popped element: %d\n", pop(&stack));
                } else {
                    printf("Stack is empty!\n");
                }
                break;
            case 3:
                if (!isEmpty(stack)) {
                    printf("Top element: %d\n", peek(stack));
                } else {
                    printf("Stack is empty!\n");
                }
                break;
            case 4:
                displayStack(stack);
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

// Push operation
void push(Node** top, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d onto the stack.\n", data);
}

// Pop operation
int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack underflow!\n");
        return -1;
    }
    Node* temp = *top;
    int poppedData = temp->data;
    *top = temp->next;
    free(temp);
    return poppedData;
}

// Peek operation
int peek(Node* top) {
    return top->data;
}

// Check if the stack is empty
int isEmpty(Node* top) {
    return top == NULL;
}

// Display stack
void displayStack(Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    Node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
