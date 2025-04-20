/*
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initStack(Stack* s);
int isEmpty(Stack* s);
Node* createNode(int data);
void push(Stack* s, int data);
int pop(Stack* s);
int peek(Stack* s);
void clearStack(Stack* s);

int main() {
    Stack myStack;
    initStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Top: %d\n", peek(&myStack));  // Harusnya 30

    printf("Pop: %d\n", pop(&myStack));   // 30
    printf("Pop: %d\n", pop(&myStack));   // 20

    printf("Is Empty: %s\n", isEmpty(&myStack) ? "Yes" : "No");

    clearStack(&myStack);

    return 0;
}



void initStack(Stack* s) {
    s->top = NULL;
}

int isEmpty(Stack* s) {
    return s->top == NULL;
}

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Error!");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Stack* s, int data) {
    Node* newNode = createNode(data);
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s){
    if (s->top == NULL) {
        printf("Error: stack is empty!");
        return -1;
    }
    Node* temp = s->top;
    int poppedData = temp->data;
    s->top = temp->next;
    free(temp);
    return poppedData;
}

int peek(Stack* s) {
    if (s->top == NULL) {
        printf("Error: stack is empty!");
        return -1;
    }
    return s->top->data;
}


void clearStack(Stack* s) {
    while (!isEmpty (s)) {
        pop(s);
    }
}
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next; 
} Node;

typedef struct {
    Node* top;
} Stack;

void initStack(Stack *s) {
    s->top = NULL;
}

int isEmpty(Stack *s) {
    return s->top == NULL;
}

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Error!");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Stack *s, int data) {
    Node* newNode = createNode(data);
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Error: Stack is empty!");
        return -1;
    }
    Node* temp = s->top;
    int popped = temp->data;
    s->top = temp->next;
    free(temp);
    return popped;
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Error: Stack is empty!");
        return -1;
    }
    return s->top->data;
}

typedef struct MinStatck {
    Stack mainStack, minStack;
} MinStack;

void initMinStack(MinStack* ms) {
    initStack(&ms->mainStack);
    initStack(&ms->minStack);
}

void pushMin(MinStack* ms, int data) {
    push(&ms->mainStack, data);
    if (isEmpty(&ms->minStack) || data <= peek(&ms->minStack)) {
        push(&ms->minStack, data);
    }
    
}

int popMin(MinStack* ms) {
    if (isEmpty(&ms->mainStack)) {
        printf("Error: Stack is empty!");
        return -1;
    }
    int popped = pop(&ms->mainStack);
    if (popped == peek(&ms->minStack)) {
        pop(&ms->minStack);
    }
    return popped;
}

int getMin(MinStack *ms) {
    if (isEmpty(&ms->minStack)) {
        printf("Error: Stack is empty!");
        return -1;
    }
    return peek(&ms->minStack);
}

int main() {
    MinStack ms;
    initMinStack(&ms);

    pushMin(&ms, 20);
    pushMin(&ms, 10);
    pushMin(&ms, 30);
    pushMin(&ms, 5);

    printf("Min sekarang: %d\n", getMin(&ms));  // 5
    popMin(&ms);  // 5 keluar
    printf("Min sekarang: %d\n", getMin(&ms));  // 10

    popMin(&ms);  // 30 keluar
    printf("Min sekarang: %d\n", getMin(&ms));  // 10

    return 0;
}