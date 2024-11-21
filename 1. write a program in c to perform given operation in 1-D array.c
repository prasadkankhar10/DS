#include <stdio.h>

// Function prototypes
void traverseArray(int arr[], int n);
void insertElement(int arr[], int *n, int pos, int element);
void deleteElement(int arr[], int *n, int pos);
int searchElement(int arr[], int n, int element);

int main() {
    int arr[100]; // Array with a maximum size of 100
    int n, choice, pos, element, result;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Traverse the array\n");
        printf("2. Insert an element\n");
        printf("3. Delete an element\n");
        printf("4. Search an element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverseArray(arr, n);
                break;
            case 2:
                printf("Enter the position to insert (1 to %d): ", n + 1);
                scanf("%d", &pos);
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertElement(arr, &n, pos, element);
                break;
            case 3:
                printf("Enter the position to delete (1 to %d): ", n);
                scanf("%d", &pos);
                deleteElement(arr, &n, pos);
                break;
            case 4:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                result = searchElement(arr, n, element);
                if (result != -1) {
                    printf("Element found at position: %d\n", result + 1);
                } else {
                    printf("Element not found.\n");
                }
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

// Function to traverse and display the array
void traverseArray(int arr[], int n) {
    printf("Array elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element into the array
void insertElement(int arr[], int *n, int pos, int element) {
    if (pos < 1 || pos > *n + 1) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = element;
    (*n)++;
    printf("Element inserted successfully.\n");
}

// Function to delete an element from the array
void deleteElement(int arr[], int *n, int pos) {
    if (pos < 1 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Element deleted successfully.\n");
}

// Function to search for an element in the array
int searchElement(int arr[], int n, int element) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}
