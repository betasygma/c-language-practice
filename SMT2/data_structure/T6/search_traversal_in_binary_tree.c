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

// Build a sample binary tree
// Tree structure:
//         1
//       /   \
//      2     3
//     / \   /
//    4   5 6
Node* buildSampleTree() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    return root;
}

// Pre-order search (root, left, right)
Node* searchPreOrder(Node* root, int key) {
    if (root == NULL) return NULL;

    printf("Visiting (pre-order): %d\n", root->data);
    if (root->data == key) return root;

    Node* leftResult = searchPreOrder(root->left, key);
    if (leftResult) return leftResult;

    return searchPreOrder(root->right, key);
}

// In-order search (left, root, right)
Node* searchInOrder(Node* root, int key) {
    if (root == NULL) return NULL;

    Node* leftResult = searchInOrder(root->left, key);
    if (leftResult) return leftResult;

    printf("Visiting (in-order): %d\n", root->data);
    if (root->data == key) return root;

    return searchInOrder(root->right, key);
}

// Post-order search (left, right, root)
Node* searchPostOrder(Node* root, int key) {
    if (root == NULL) return NULL;

    Node* leftResult = searchPostOrder(root->left, key);
    if (leftResult) return leftResult;

    Node* rightResult = searchPostOrder(root->right, key);
    if (rightResult) return rightResult;

    printf("Visiting (post-order): %d\n", root->data);
    if (root->data == key) return root;

    return NULL;
}

int main() {
    Node* root = buildSampleTree();
    int key;

    printf("Enter key to search: ");
    scanf("%d", &key);

    printf("\n--- Pre-Order Search ---\n");
    Node* foundPre = searchPreOrder(root, key);
    if (foundPre) printf("Key %d found at node address %p\n", key, (void*)foundPre);
    else printf("Key %d not found (Pre-Order)\n", key);


    printf("\n--- In-Order Search ---\n");
    Node* foundIn = searchInOrder(root, key);
    if (foundIn) printf("Key %d found at node address %p\n", key, (void*)foundIn);
    else printf("Key %d not found (In-Order)\n", key);

    printf("\n--- Post-Order Search ---\n");
    Node* foundPost = searchPostOrder(root, key);
    if (foundPost) printf("Key %d found at node address %p\n", key, (void*)foundPost);
    else printf("Key %d not found (Post-Order)\n", key);

    return 0;
}
