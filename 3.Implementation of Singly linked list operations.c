#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void insertAtBeginning(Node** head, int data);
void insertAtEnd(Node** head, int data);
void insertAfter(Node* prevNode, int data);
void deleteNode(Node** head, int key);
Node* search(Node* head, int key);
void display(Node* head);

int main() {
    Node* head = NULL; // Initialize an empty list
    int choice, data, key;

    while (1) {
        printf("\nSingly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Node\n");
        printf("4. Delete a Node\n");
        printf("5. Search for an Element\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter the key after which to insert: ");
                scanf("%d", &key);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                Node* temp = search(head, key);
                if (temp != NULL) {
                    insertAfter(temp, data);
                } else {
                    printf("Node with data %d not found.\n", key);
                }
                break;
            case 4:
                printf("Enter data of the node to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
            case 5:
                printf("Enter data to search for: ");
                scanf("%d", &key);
                Node* found = search(head, key);
                if (found != NULL) {
                    printf("Element %d found in the list.\n", key);
                } else {
                    printf("Element %d not found in the list.\n", key);
                }
                break;
            case 6:
                display(head);
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the beginning of the list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Node inserted at the beginning.\n");
}

// Insert a node at the end of the list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        printf("Node inserted at the end.\n");
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Node inserted at the end.\n");
}

// Insert a node after a given node
void insertAfter(Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    printf("Node inserted after %d.\n", prevNode->data);
}

// Delete a node with a given key
void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    // Check if the head node holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("Node with data %d deleted.\n", key);
        return;
    }

    // Search for the key in the list
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key is not found
    if (temp == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }

    // Unlink the node and free memory
    prev->next = temp->next;
    free(temp);
    printf("Node with data %d deleted.\n", key);
}

// Search for a node with a given key
Node* search(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Display the entire list
void display(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
