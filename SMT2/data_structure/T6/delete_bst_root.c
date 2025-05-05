#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int data) {
    if (root == NULL) return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// Delete root and replace with in-order successor
Node *deleteRootWithSuccessor(Node *root) {
    if (root == NULL) return NULL;

    // Case 1: no children
    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }

    // Case 2: only one child
    if (root->left == NULL) {
        Node *temp = root->right;
        free(root);
        return temp;
    }

    if (root->right == NULL) {
        Node *temp = root->left;
        free(root);
        return temp;
    }

    // Case 3: two children
    Node *successorParent = root;
    Node *successor = root->right;

    // Find the leftmost node of right subtree
    while (successor->left != NULL) {
        successorParent = successor;
        successor = successor->left;
    }

    // Replace root's data with successor's data
    root->data = successor->data;

    // Remove successor node
    if (successorParent != root) successorParent->left = successor->right;
    else successorParent->right = successor->right;

    free(successor);
    return root;
}

// Delete root and replace with in-order predecessor
Node *deleteRootWithPredecessor(Node *root) {
    if (root == NULL) return NULL;

    // Case 1: no children
    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }

    // Case 2: only one child
    if (root->left == NULL) {
        Node *temp = root->right;
        free(root);
        return temp;
    }

    if (root->right == NULL) {
        Node *temp = root->left;
        free(root);
        return temp;
    }

    // Case 3: two children
    Node *predecessorParent = root;
    Node *predecessor = root->left;

    // Find the rightmost node of left subtree
    while (predecessor->right != NULL) {
        predecessorParent = predecessor;
        predecessor = predecessor->right;
    }

    // Replace root's data with predecessor's data
    root->data = predecessor->data;

    // Remove predecessor node
    if (predecessorParent != root) predecessorParent->right = predecessor->left;
    else predecessorParent->left = predecessor->left;

    free(predecessor);
    return root;
}

// In-order traversal (for checking)
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Free entire tree
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node* root = NULL;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(keys) / sizeof(keys[0]);

    // Build the tree
    for (int i = 0; i < n; i++) {
        root = insert(root, keys[i]);
    }

    printf("Original BST (in-order):\n");
    inorderTraversal(root);
    printf("\n");

    // Delete root using successor
    printf("\nDeleting root using in-order successor...\n");
    root = deleteRootWithSuccessor(root);
    printf("BST after deleting root (in-order):\n");
    inorderTraversal(root);
    printf("\n");

    // Delete root using successor
    printf("\nDeleting root using in-order successor...\n");
    root = deleteRootWithSuccessor(root);
    printf("BST after deleting root (in-order):\n");
    inorderTraversal(root);
    printf("\n");

    // Delete new root using predecessor
    printf("\nDeleting root using in-order predecessor...\n");
    root = deleteRootWithPredecessor(root);
    printf("BST after deleting root (in-order):\n");
    inorderTraversal(root);
    printf("\n");

    // Delete new root using predecessor
    printf("\nDeleting root using in-order predecessor...\n");
    root = deleteRootWithPredecessor(root);
    printf("BST after deleting root (in-order):\n");
    inorderTraversal(root);
    printf("\n");

    // Clean up
    freeTree(root);
    return 0;
}
