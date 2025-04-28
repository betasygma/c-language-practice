#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

typedef struct {
    char data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char c) {
    if (!isFull(s)) s->data[++(s->top)] = c;
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0';
}

void print(Stack *s) {
    while (!isEmpty(s)) {
        printf("%s", pop(s));
    }
}

int main() {
    Stack s;
    init(&s);

    char cmd[10];
    do {
        scanf("%s", cmd);

        if (strcmp(cmd, "WRITE") == 0) {
            char c[2];
            scanf("%s", c);
            push(&s, c[0]);
        } else if (strcmp(cmd, "BACKSPACE") == 0) {
            pop(&s);
        } else if (strcmp(cmd, "PRINT") == 0) {
            print(&s);
        } else
            continue;
        printf("\n");
    } while (strcmp(cmd, "PRINT") != 0);
    return 0;
}
