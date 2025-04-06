#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
void display(Stack *s);

void search(Stack *s, int value) {
    int found = 0;
    printf("Element %d found at index: ", value);
    for (int i = 0; i <= s->top; i++) {
        if (s->items[i] == value) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("not found");
    }
    printf("\n");
}

void editByValue(Stack *s, int oldValue, int newValue) {
    int found = 0;
    for (int i = 0; i <= s->top; i++) {
        if (s->items[i] == oldValue) {
            s->items[i] = newValue;
            found = 1;
        }
    }
    if (found) {
        printf("All occurrences of %d changed to %d\n", oldValue, newValue);
    } else {
        printf("Element %d not found\n", oldValue);
    }
}

void editByIndex(Stack *s, int index, int newValue) {
    if (index < 0 || index > s->top) {
        printf("Invalid index!\n");
        return;
    }
    s->items[index] = newValue;
    printf("Element at index %d changed to %d\n", index, newValue);
}

int main() {
    Stack s;
    initStack(&s);
    srand(time(NULL));
    
    for (int i = 0; i < 10; i++) {
        push(&s, rand() % 50 + 1);
    }
    
    display(&s);

    int valueToSearch, valueToEdit, newValue, indexToEdit;
    
    printf("Enter value to search: ");
    scanf("%d", &valueToSearch);
    search(&s, valueToSearch);
    
    printf("Enter value to replace: ");
    scanf("%d", &valueToEdit);
    printf("Enter new value: ");
    scanf("%d", &newValue);
    editByValue(&s, valueToEdit, newValue);
    display(&s);
    
    printf("Enter index to edit: ");
    scanf("%d", &indexToEdit);
    printf("Enter new value: ");
    scanf("%d", &newValue);
    editByIndex(&s, indexToEdit, newValue);
    display(&s);

    return 0;
}



void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full!\n");
        return;
    }
    s->items[++s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->items[s->top--];
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}