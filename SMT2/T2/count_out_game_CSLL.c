#include <stdio.h>
#include <stdlib.h>

// node struct CLL
typedef struct Node {
    int number;
    struct Node* next;
} Node;

// new node
Node* createNode(int number) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->number = number;
    newNode->next = NULL;
    return newNode;
}

// create cingular linked-list with n-clildren
Node* createCLL(int n) {
    Node* head = createNode(1);
    Node* prev = head;
    for (int i = 2; i <= n; i++) {
        Node* newNode = createNode(i);
        prev->next = newNode;
        prev = newNode;
    }
    prev->next = head;
    return head;
}

// find the last child using the Josephus problem logic
int findLastChild(int n, int m) {
    Node* head = createCLL(n);
    Node* prev = NULL;
    while (head->next != head) // until only one node remains
    {
        for (int i = 0; i < m; i++) {
            prev = head;
            head = head->next;
        }
        prev->next = head->next; // remove m-th child
        free(head);
        head = prev->next; // move to the next child
    }

    int lastChild = head->number;
    free(head);
    return lastChild;
}

int main() {
    int n, m;
    printf("Enter number of children (n): "); scanf("%d", &n);
    printf("Enter number of words in the count-out (m): "); scanf("%d", &m);

    printf("The last remaining child is \"%d\"\n", findLastChild(n, m));
    return 0;
}