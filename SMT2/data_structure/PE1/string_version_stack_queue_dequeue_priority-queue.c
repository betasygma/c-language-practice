#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 101


// STACK
typedef struct {
    char** data;
    int size, capacity;
} Stack;

void initStack(Stack* s) {
    s->size = 0;
    s->capacity = 2;
    s->data = (char**)malloc(s->capacity * sizeof(char*));
}

void resizeStack(Stack* s) {
    s->capacity *= 2;
    s->data = (char**)realloc(s->data, s->capacity * sizeof(char*));
}

void push(Stack* s, const char* str) {
    if (s->size >= s->capacity) resizeStack(s);

    s->data[s->size] = (char*)malloc(STR_LEN * sizeof(char));
    strncpy(s->data[s->size], str, STR_LEN - 1);
    s->data[s->size][STR_LEN - 1] = '\0';
    s->size++;
}

void pop(Stack* s) {
    if (s->size == 0) {
        printf("Stack is empty!\n");
        return;
    }
    printf("POP: %s\n", s->data[s->size - 1]);
    free(s->data[s->size - 1]);
    s->size--;
}

void peek(Stack* s) {
    if (s->size == 0) {
        printf("Stack is empty!\n");
        return;
    }
    printf("PEEK: %s\n", s->data[s->size - 1]);
}

void destroy(Stack* s) {
    for (int i = 0; i < s->size; i++) {
        free(s->data[i]);
    }
    free(s->data);
}

int main() {
    Stack s;
    initStack(&s);

    int Q;
    scanf("%d", &Q);
    getchar();

    for (int i = 0; i < Q; i++) {
        char command[10];
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "PUSH") == 0) {
            char str[STR_LEN];
            fgets(str, STR_LEN, stdin);
            str[strcspn(str, "\n")] = 0;
            push(&s, str);
        } else if (strcmp(command, "POP") == 0) {
            pop(&s);
        } else if (strcmp(command, "PEEK") == 0) {
            peek(&s);
        }
    }
    
    destroy(&s);
    return 0;
}



// QUEUE
typedef struct {
    char** data;
    int front, rear, size, capacity; 
} Queue;

void initQueue(Queue *q) {
    q->capacity = 2;
    q->data = (char**)malloc(sizeof(char*) * q->capacity);
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

void resizeQueue(Queue* q) {
    int newCap = q->capacity * 2;
    char** newData = (char**)malloc(sizeof(char*) * newCap);

    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % q->capacity;
        newData[i] = q->data[index];
    }

    free(q->data);
    q->data = newData;
    q->front = 0;
    q->rear = q->size;
    q->capacity = newCap;
}

void enqueue(Queue* q, const char* str) {
    if (q->size == q->capacity) {
        resizeQueue(q);
    }

    q->data[q->rear] = (char*)malloc(STR_LEN);
    strncpy(q->data[q->rear], str, STR_LEN - 1);
    q->data[q->rear][STR_LEN - 1] = '\0';

    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

void dequeue(Queue* q) {
    if (q->size == 0) {
        printf("Queue is empty!\n");
        return;
    }

    printf("DEQUEUE: %s\n", q->data[q->front]);
    free(q->data[q->front]);

    q->front = (q->front + 1) % q->capacity;
    q->size--;
}

void peek(Queue* q) {
    if (q->size == 0) {
        printf("Queue is empty!\n");
        return;
    }

    printf("PEEK: %s\n", q->data[q->front]);
}

void destroyQueue(Queue* q) {
    for (int i = 0; i < q->size; i++) {
        int idx = (q->front + i) % q->capacity;
        free(q->data[idx]);
    }
    free(q->data);
}

int main() {
    Queue q;
    initQueue(&q);

    int Q;
    scanf("%d", &Q);
    getchar();

    for (int i = 0; i < Q; i++) {
        char command[10];
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "ENQUEUE") == 0) {
            char str[STR_LEN];
            fgets(str, STR_LEN, stdin);
            str[strcspn(str, "\n")] = 0;
            enqueue(&q, str);
        } else if (strcmp(command, "DEQUEUE") == 0) {
            dequeue(&q);
        } else if (strcmp(command, "PEEK") == 0) {
            peek(&q);
        }
    }

    destroyQueue(&q);
    return 0;
}



// DEQUE (DOUBLE-ENDED QUEUE)
typedef struct {
    char** data;
    int front, rear, size, capacity;
} Deque;

void initDeque(Deque* dq) {
    dq->capacity = 4;
    dq->data = (char**)malloc(sizeof(char*) * dq->capacity);
    dq->front = 0;
    dq->rear = 0;
    dq->size = 0;
}

int realIndex(Deque* dq, int i) {
    return (dq->front + i + dq->capacity) % dq->capacity;
}

void resizeDeque(Deque* dq) {
    int newCap = dq->capacity * 2;
    char** newData = (char**)malloc(sizeof(char*) * newCap);

    for (int i = 0; i < dq->size; i++) {
        newData[i] = dq->data[realIndex(dq, i)];
    }

    free(dq->data);
    dq->data = newData;
    dq->front = 0;
    dq->rear = dq->size;
    dq->capacity = newCap;
}

void pushFront(Deque* dq, const char* str) {
    if (dq->size == dq->capacity) resizeDeque(dq);

    dq->front = (dq->front - 1 + dq->capacity) % dq->capacity;
    dq->data[dq->front] = (char*)malloc(STR_LEN);
    strncpy(dq->data[dq->front], str, STR_LEN - 1);
    dq->data[dq->front][STR_LEN - 1] = '\0';
    dq->size++;
}

void pushBack(Deque* dq, const char* str) {
    if (dq->size == dq->capacity) resizeDeque(dq);

    dq->data[dq->rear] = (char*)malloc(STR_LEN);
    strncpy(dq->data[dq->rear], str, STR_LEN - 1);
    dq->data[dq->rear][STR_LEN - 1] = '\0';
    dq->rear = (dq->rear + 1) % dq->capacity;
    dq->size++;
}

void popFront(Deque* dq) {
    if (dq->size == 0) {
        printf("Deque is empty!\n");
        return;
    }

    printf("POP FRONT: %s\n", dq->data[dq->front]);
    free(dq->data[dq->front]);
    dq->front = (dq->front + 1) % dq->capacity;
    dq->size--;
}

void popBack(Deque* dq) {
    if (dq->size == 0) {
        printf("Deque is empty!\n");
        return;
    }

    dq->rear = (dq->rear - 1 + dq->capacity) % dq->capacity;
    printf("POP BACK: %s\n", dq->data[dq->rear]);
    free(dq->data[dq->rear]);
    dq->size--;
}

void peekFront(Deque* dq) {
    if (dq->size == 0) {
        printf("Deque is empty!\n");
        return;
    }
    printf("PEEK FRONT: %s\n", dq->data[dq->front]);
}

void peekBack(Deque* dq) {
    if (dq->size == 0) {
        printf("Deque is empty!\n");
        return;
    }
    int backIdx = (dq->rear - 1 + dq->capacity) % dq->capacity;
    printf("PEEK BACK: %s\n", dq->data[backIdx]);
}

void destroyDeque(Deque* dq) {
    for (int i = 0; i < dq->size; i++) {
        int idx = realIndex(dq, i);
        free(dq->data[idx]);
    }
    free(dq->data);
}

int main() {
    Deque dq;
    initDeque(&dq);

    int Q;
    scanf("%d", &Q);
    getchar();

    for (int i = 0; i < Q; i++) {
        char command[20];
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "PUSHFRONT") == 0) {
            char str[STR_LEN];
            fgets(str, STR_LEN, stdin);
            str[strcspn(str, "\n")] = 0;
            pushFront(&dq, str);
        } else if (strcmp(command, "PUSHBACK") == 0) {
            char str[STR_LEN];
            fgets(str, STR_LEN, stdin);
            str[strcspn(str, "\n")] = 0;
            pushBack(&dq, str);
        } else if (strcmp(command, "POPFRONT") == 0) {
            popFront(&dq);
        } else if (strcmp(command, "POPBACK") == 0) {
            popBack(&dq);
        } else if (strcmp(command, "PEEKFRONT") == 0) {
            peekFront(&dq);
        } else if (strcmp(command, "PEEKBACK") == 0) {
            peekBack(&dq);
        }
    }

    destroyDeque(&dq);
    return 0;
}



// PRIORITY QUEUE
typedef struct Node {
    char data[STR_LEN];
    int priority;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} PriorityQueue;

void initPQ(PriorityQueue* pq) {
    pq->head = NULL;
}

void insert(PriorityQueue* pq, const char* str, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->data, str, STR_LEN - 1);
    newNode->data[STR_LEN - 1] = '\0';
    newNode->priority = priority;
    newNode->next = NULL;

    if (pq->head == NULL || pq->head->priority < priority) {
        newNode->next = pq->head;
        pq->head = newNode;
        return;
    }

    Node* curr = pq->head;
    while (curr->next != NULL && curr->next->priority >= priority) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

void serve(PriorityQueue* pq) {
    if (pq->head == NULL) {
        printf("Priority Queue is empty!\n");
        return;
    }

    Node* temp = pq->head;
    printf("%s\n", temp->data);
    pq->head = pq->head->next;
    free(temp);
}

void peek(PriorityQueue* pq) {
    if (pq->head == NULL) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("PEEK: %s (priority %d)\n", pq->head->data, pq->head->priority);
}

void clear(PriorityQueue* pq) {
    while (pq->head != NULL) {
        Node* temp = pq->head;
        pq->head = pq->head->next;
        free(temp);
    }
}

int main() {
    PriorityQueue pq;
    initPQ(&pq);

    int Q;
    scanf("%d", &Q);
    getchar();

    for (int i = 0; i < Q; i++) {
        char command[20];
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "INSERT") == 0) {
            char str[STR_LEN];
            int p;
            fgets(str, STR_LEN, stdin);
            str[strcspn(str, "\n")] = '\0';
            scanf("%d", &p);
            getchar(); // newline
            insert(&pq, str, p);
        } else if (strcmp(command, "SERVE") == 0) {
            serve(&pq);
        } else if (strcmp(command, "PEEK") == 0) {
            peek(&pq);
        }
    }

    clear(&pq);
    return 0;
}
