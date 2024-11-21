#include <stdio.h>
#define MAX 100 // Maximum size of the stack

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Function prototypes
void initialize(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, int element);
int pop(Stack *s);
int peek(Stack *s);
void display(Stack *s);

int main() {
    Stack stack;
    int choice, element;

    initialize(&stack);

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(&stack, element);
                break;
            case 2:
                element = pop(&stack);
                if (element != -1) {
                    printf("Popped element: %d\n", element);
                }
                break;
            case 3:
                element = peek(&stack);
                if (element != -1) {
                    printf("Top element: %d\n", element);
                }
                break;
            case 4:
                display(&stack);
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

// Initialize the stack
void initialize(Stack *s) {
    s->top = -1;
}

// Check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(Stack *s, int element) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push element.\n");
    } else {
        s->arr[++(s->top)] = element;
        printf("Element pushed successfully.\n");
    }
}

// Pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop element.\n");
        return -1;
    } else {
        return s->arr[(s->top)--];
    }
}

// Peek at the top element of the stack
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! No top element.\n");
        return -1;
    } else {
        return s->arr[s->top];
    }
}

// Display the stack elements
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}
