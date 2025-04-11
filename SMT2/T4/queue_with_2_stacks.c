/*
 * ==================
 * QUEUE USING STACKS
 * ------------------
 * Queue implemented using two stacks.
 * Stack and Queue are implemented dynamically using malloc & realloc.
 * Elements: integers only.
 * Enqueue: push to stack_in.
 * Dequeue: if stack_out empty, transfer all elements from stack_in to stack_out, then pop from stack_out.
 * ======================================
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data, size, capacity;
} Stack;

void initStacks(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int isEmpty(Stack *s);
void freeStack(Stack *s);

typedef struct {
    Stack stack_in, stack_out;
} Queue;

void initQueue(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int isQueueEmpty(Queue *q);
void freeQueue(Queue *q);
void debugPrintQueue(Queue *q);

int main() {
    Queue q;
    initQueue(&q);
    printf("Implementing a queue using two stacks\n");
    debugPrintQueue(&q);
    
    // Enqueue some integers
    printf("Enqueue: 11, 32, 89\n");
    enqueue(&q, 11);
    enqueue(&q, 32);
    enqueue(&q, 89);
    debugPrintQueue(&q);
    
    // Dequeue one
    printf("Dequeue: Expected FIFO (11 first)\n");
    printf("Dequeued: %d\n", dequeue(&q)); // 11
    debugPrintQueue(&q);
    
    // Enqueue more
    printf("Enqueue: 67, 93, 37\n");
    enqueue(&q, 67);
    enqueue(&q, 93);
    enqueue(&q, 37);
    debugPrintQueue(&q);
    
    // Dequeue 3 times
    printf("Dequeue 3 times: Continuing FIFO (32, 89, 67)\n");
    printf("Dequeued: %d\n", dequeue(&q)); // 32 
    printf("Dequeued: %d\n", dequeue(&q)); // 89
    printf("Dequeued: %d\n", dequeue(&q)); // 67
    debugPrintQueue(&q);
    
    // Dequeue remaining
    printf("Dequeue remaining:\n");
    while (!isQueueEmpty(&q)) {
        printf("Dequeued: %d\n", dequeue(&q)); // 93, 37
    }
    debugPrintQueue(&q);
    
    // Try dequeueing from empty queue
    printf("Try to dequeue from empty queue:\n");
    dequeue(&q);
    debugPrintQueue(&q);

    freeQueue(&q);
    return 0;
}


void initStacks(Stack *s) {
    s->capacity = 10;
    s->size = 0;
    s->data = (int*) malloc(sizeof(int) * s->capacity);
}

void push(Stack *s, int value) {
    if (s->size == s->capacity) {
        s->capacity *= 2;
        s->data = (int*) realloc(s->data, sizeof(int) * s->capacity);
    }
    s->data[s->size++] = value;
}

int pop(Stack *s) {
    if (s->size == 0) {
        printf("Stack is empty! Cannot pop.\n");
        return -1;
    }
    return s->data[--s->size];
}

int isEmpty(Stack *s) {
    return s->size == 0;
}

void freeStack(Stack *s) {
    free(s->data);
}


void initQueue(Queue *q) {
    initStacks(&q->stack_in);
    initStacks(&q->stack_out);
}

void enqueue(Queue *q, int value) {
    push(&q->stack_in, value);
}

int dequeue(Queue *q) {
    if (isEmpty(&q->stack_out)) {
        while (!isEmpty(&q->stack_in)) {
            int val = pop(&q->stack_in);
            push(&q->stack_out, val);
        }
    }
    if (isEmpty(&q->stack_out)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }

    return pop(&q->stack_out);
}

int isQueueEmpty(Queue *q) {
    return isEmpty(&q->stack_in) && isEmpty(&q->stack_out);
}

void freeQueue(Queue *q) {
    freeStack(&q->stack_in);
    freeStack(&q->stack_out);
}

void debugPrintQueue(Queue *q) {
    printf("  [stack_in]  : ");
    for (int i = 0; i < q->stack_in.size; i++) {
        printf("%d ", q->stack_in.data[i]);
    }
    printf("\n");

    printf("  [stack_out]  : ");
    for (int i = 0; i < q->stack_out.size; i++) {
        printf("%d ", q->stack_out.data[i]);
    }
    printf("\n");
}