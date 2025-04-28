#include <stdio.h>
#include <stdlib.h>

#define INIT_CAPACITY  10
#define SUCCESS         0
#define ERR_NOT_FOUND  -1
#define ERR_EMPTY      -2
#define ERR_FULL       -3
#define ERR_INVALID    -4

typedef struct {
    int *data, front, rear, size, capacity;
} Queue;

void initQueue(Queue *q);
void resizeQueue(Queue *q);
int isQueueEmpty(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void printQueue(Queue *q);
int searchValue(Queue *q, int target);
int editValue(Queue *q, int oldValue, int newValue);
int totalQueue(Queue *q);
int minQueue(Queue *q);
int maxQueue(Queue *q);
float avgQueue(Queue *q, int *status);
void freeQueue(Queue *q);
void printError(int code);

int main() {
    Queue q;
    initQueue(&q);

    int initData[] = {12, 7, 9, 15, 8, 5, 11, 13, 20, 6, 14, 17, 10, 4, 3};
    for (int i = 0; i < sizeof(initData)/sizeof(initData[0]); i++){
        enqueue(&q, initData[i]);
    }

    int choice, target, replacement, result;
    do {
        printf("\n===== QUEUE MENU =====\n");
        printf("1. Print queue\n");
        printf("2. Search value\n");
        printf("3. Edit value\n");
        printf("4. Total of all values\n");
        printf("5. Average of values\n");
        printf("6. Maximum value\n");
        printf("7. Minimum value\n");
        printf("8. Exit\n");
        printf("Choose [1-8]: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printQueue(&q);
            break;
        
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &target);
            result = searchValue(&q, target);
            if (result != SUCCESS) printError(result);
            break;
        
        case 3:
            printf("Enter value to edit: ");
            scanf("%d", &target);
            printf("Replace with: ");
            scanf("%d", &replacement);
            result = editValue(&q, target, replacement);
            if (result == SUCCESS)
                printf("Edit success!\n");
            else
                printError(result);
            break;

        case 4:
            result = totalQueue(&q);
            if (result == ERR_EMPTY) printError(result);
            else printf("Total: %d\n", result);
            break;

        case 5: {
            int status;
            float avg = avgQueue(&q, &status);
            if (status == ERR_EMPTY) printError(status);
            else printf("Average: %.2f\n", avg);
            break;
        }

        case 6:
            result = maxQueue(&q);
            if (result == ERR_EMPTY) printError(result);
            else printf("Max value: %d\n", result);
            break;

        case 7:
            result = minQueue(&q);
            if (result == ERR_EMPTY) printError(result);
            else printf("Min value: %d\n", result);
            break;

        case 8:
            printf("Exiting program. Goodbye!\n");
            break;

        default:
            printf("Invalid menu. Try again.\n");
        }

    } while (choice != 8);

    freeQueue(&q);
    return 0;
}

void initQueue(Queue *q) {
    q->capacity = INIT_CAPACITY;
    q->data = (int *)malloc(sizeof(int) * q->capacity);
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

void resizeQueue(Queue *q) {
    int *newData = (int *)malloc(sizeof(int) * q->capacity * 2);

    for (int i = 0; i < q->size; i++) {
        newData[i] = q->data[(q->front + i) % q->capacity];
    }

    free(q->data);
    q->data = newData;
    q->capacity *= 2;
    q->front = 0;
    q->rear = q->size;
}

int isQueueEmpty(Queue *q) {
    return (q->size == 0);
}

void enqueue(Queue *q, int value) {
    if (q->size == q->capacity) resizeQueue(q);

    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

int dequeue(Queue *q) {
    if (isQueueEmpty(q)) return ERR_EMPTY;
    
    int value = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return value;
}

void printQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printError(ERR_EMPTY);
        return;
    }

    printf("Queue contents (%d item(s)):\n", q->size);
    for (int i = 0; i < q->size; i++){
        int index = (q->front + i) % q->capacity;
        printf("%d ", q->data[index]);
    }
    printf("\n");
}

int searchValue(Queue *q, int target) {
    int found = 0;
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % q->capacity;
        if (q->data[index] == target) {
            printf("Found value \"%d\" at logical position %d (index %d in array)\n", target, i, index);
            found++;
        }
    }
    
    if (!found) return ERR_NOT_FOUND;
    printf("Found %d value(s) \"%d\"\n", found, target);
    return SUCCESS;
}

int editValue(Queue *q, int oldValue, int newValue) {
    int edited = 0;
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % q->capacity;
        if (q->data[index] == oldValue) {
            q->data[index] = newValue;
            printf("Edited value \"%d\" to \"%d\" at logical position %d (index %d in array)\n", oldValue, newValue, i, index);
            edited++;
        }
    }

    if (!edited) return ERR_NOT_FOUND;
    printf("Edited %d occurrence(s) of value \"%d\" to \"%d\"\n", edited, oldValue, newValue);
    return SUCCESS;
}

int totalQueue(Queue *q) {
    if (isQueueEmpty(q)) return ERR_EMPTY;

    int total = 0;
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % q->capacity;
        total += q->data[index];
    }

    return total;
}

int minQueue(Queue *q) {
    if (isQueueEmpty(q)) return ERR_EMPTY;

    int min = q->data[q->front];
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % q->capacity;
        if (q->data[index] < min) {
            min = q->data[index];
        }
    }

    return min;
}

int maxQueue(Queue *q) {
    if (isQueueEmpty(q)) return ERR_EMPTY;

    int max = q->data[q->front];
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % q->capacity;
        if (q->data[index] > max) {
            max = q->data[index];
        }
    }

    return max;
}

float avgQueue(Queue *q, int *status) {
    if (isQueueEmpty(q)) {
        *status = ERR_EMPTY;
        return 0.0f;
    }

    int total = totalQueue(q);
    *status = SUCCESS;
    return (float)total / q->size;
}

void freeQueue(Queue *q) {
    free(q->data);
}

void printError(int code) {
    switch (code) {
    case SUCCESS: printf("Operation successful.\n"); break;
    case ERR_EMPTY: printf("Queue is empty.\n"); break;
    case ERR_NOT_FOUND: printf("Value not found.\n"); break;
    case ERR_FULL: printf("Queue is full.\n"); break;
    case ERR_INVALID: printf("Invalid operation.\n"); break;
    default: printf("Unknown error code: %d\n", code);
    }
}