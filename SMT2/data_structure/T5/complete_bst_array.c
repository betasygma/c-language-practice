#include <stdio.h>

#define MAX_SIZE 15

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Quick Sort algorithm to sort the array
void quickSort(int arr[], int low, int high) {
    if (low >= high) return;

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    int pi = i + 1;

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}

// Function to build a complete BST (stored as an array) from a sorted array
void buildCompleteBST(int sorted[], int bst[], int index, int left, int right) {
    if (left > right || index > MAX_SIZE) return;

    int mid = (left + right) / 2;
    bst[index] = sorted[mid];

    buildCompleteBST(sorted, bst, 2 * index, left, mid - 1);      // left subtree
    buildCompleteBST(sorted, bst, 2 * index + 1, mid + 1, right); // right subtree
}

int main() {
    int keys[] = {34, 23, 45, 46, 37, 78, 90, 2, 40, 20, 87, 53, 12, 15, 91};
    int n = sizeof(keys) / sizeof(keys[0]);

    // Step 1: Sort the keys
    quickSort(keys, 0, n - 1);

    printf("Sorted:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", keys[i]);
    }
    printf("\n\n");

    // Step 2: Prepare BST array (1-based indexing), initialize with valid values (no -1)
    int bst[MAX_SIZE + 1]; // Adjust size based on the actual number of keys
    for (int i = 0; i <= MAX_SIZE; i++)
        bst[i] = -1; // Initializing all positions with 0 (valid values)

    // Step 3: Build complete BST from the sorted keys
    buildCompleteBST(keys, bst, 1, 0, n - 1);

    // Step 4: Print array form of BST
    printf("Complete BST stored in array:\n");
    for (int i = 1; i <= MAX_SIZE; i++) { // Print only valid keys, not the uninitialized ones
        if (bst[i] != -1) {
            printf("bst[%d] = %d\n", i, bst[i]);
        } else
            printf("bst[%d] = NULL\n", i);
    }

    return 0;
}
