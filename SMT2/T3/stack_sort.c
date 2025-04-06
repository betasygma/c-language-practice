#include <stdio.h>
#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

void initStack(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, int val);
int pop(Stack *s);
int peek(Stack *s);
void printStack(Stack *s);

void sortStack(Stack *S1) {
    Stack S2;
    initStack(&S2);

    printf("Initial Stack (S1): ");
    printStack(S1);

    while (!isEmpty(S1)) {
        int temp = pop(S1);

        while (!isEmpty(&S2) && peek(&S2) > temp) {
            push(S1, pop(&S2));
        }

        push(&S2, temp);

        printf("S1: ");
        printStack(S1);
        printf("S2: ");
        printStack(&S2);
        printf("-----------------------------\n");
    }

    while (!isEmpty(&S2)) {
        push(S1, pop(&S2));
    }

    printf("Sorted Stack (S1): ");
    printStack(S1);
}

int main() {
    Stack S1;
    initStack(&S1);

    int values[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++) {
        push(&S1, values[i]);
    }
    sortStack(&S1);
    
    return 0;
}


void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int val) {
    if (s->top < MAX-1) s->items[++s->top] = val;
}

int pop(Stack *s) {
    return isEmpty(s) ? -1 : s->items[s->top--];
}

int peek(Stack *s) {
    return isEmpty(s) ? -1 : s->items[s->top];
}

void printStack(Stack *s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}