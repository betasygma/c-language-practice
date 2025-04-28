#include <stdio.h>
#include <stdlib.h>

typedef struct Customer {
    int index;
    int burgerRequest;
    struct Customer *next;
} Customer; // node

Customer *front = NULL, *rear = NULL;

void enqueue(int index, int burgerRequest) {
    Customer *newNode = (Customer *)malloc(sizeof(Customer));
    newNode->index = index;
    newNode->burgerRequest = burgerRequest;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front != NULL) {
        Customer *temp = front;
        front = front->next;
        free(temp);
        if (front == NULL) {
            rear = NULL;
        }
    }
}

int main() {
    int X, Y, Z; // people in queue, available burgers, multiple
    scanf("%d %d %d", &X, &Y, &Z);

    for (int i = 0; i < X; i++) {
        int burgerRequest;
        scanf("%d", &burgerRequest);
        enqueue(i + 1, burgerRequest);
    }

    int lastIndex = X, requeue = 0;

    while (Y > 0 && front != NULL) {
        Customer *person = front;

        if (person->burgerRequest > Y || Z == 1) break;

        if (person->index % Z == 0) {
            lastIndex++;
            enqueue(lastIndex, person->burgerRequest);
            requeue++;
        } else Y -= person->burgerRequest;

        dequeue();
    }

    printf("%d %s\n", requeue, front == NULL && Y >= 0 ? "Yes Dapat burger gratis!!!" : "NOO tidak Dapat :(");
    return 0;
}
