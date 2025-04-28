#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (rear == NULL) {
        rear = front = newNode;
    } else {
        front->next = newNode;
        rear = newNode;
    }
}

int printRear() {
    if (front != NULL) {
        Node *curr = front, *prev = NULL;

        while (curr->next) {
            prev = curr;
            curr = curr->next;
        }

        Node *temp = curr;
        printf("%d ", temp->data);
        free(temp);

        if (front == NULL) rear = NULL;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        enqueue(m);
    }

    for (int i = 0; i < n; i++) {
        printRear();
    }
}
