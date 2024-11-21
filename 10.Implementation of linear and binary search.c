#include <stdio.h>

// Function to perform Binary Search
int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the target is at the middle
        if (arr[mid] == target) {
            return mid;  // Return the index of the found element
        }
        // If the target is smaller, search the left half
        else if (arr[mid] > target) {
            high = mid - 1;
        }
        // If the target is larger, search the right half
        else {
            low = mid + 1;
        }
    }

    return -1;  // Return -1 if element not found
}

int main() {
    int arr[] = {9, 12, 23, 34, 54, 67};  // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found.\n", target);
    }

    return 0;
}
