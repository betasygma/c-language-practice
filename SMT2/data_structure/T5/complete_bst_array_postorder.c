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
    if (left > right || index >= MAX_SIZE) return;

    int mid = (left + right) / 2;
    bst[index] = sorted[mid];

    buildCompleteBST(sorted, bst, 2 * index, left, mid - 1);      // left subtree
    buildCompleteBST(sorted, bst, 2 * index + 1, mid + 1, right); // right subtree
}

// Recursive function to print post-order traversal of BST stored in array (1-based index)
void postOrder(int bst[], int index, int size) {
    if (index >= size || bst[index] == -1) return;

    postOrder(bst, 2 * index, size);     // left subtree
    postOrder(bst, 2 * index + 1, size); // right subtree
    printf("%d ", bst[index]);           // root
}

int main() {
    int keys[] = {56, 30, 61, 39, 47, 35, 75, 13, 21, 64, 26, 73, 18};
    int n = sizeof(keys) / sizeof(keys[0]);

    // Step 1: Sort the keys
    quickSort(keys, 0, n - 1);

    // Step 2: Prepare BST array (1-based indexing), initialize with -1
    int bst[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
        bst[i] = -1;

    // Step 3: Build complete BST from the sorted keys
    buildCompleteBST(keys, bst, 1, 0, n - 1);

    // Step 4: Display post-order traversal
    printf("Post-order traversal of complete BST:\n");
    postOrder(bst, 1, MAX_SIZE);
    printf("\n");

    return 0;
}
