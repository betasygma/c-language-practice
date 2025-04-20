#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 201

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
    // printf("Stack now: ");
    //     for (int i = 0; i <= s->top; i++) {
    //         printf("%c ", s->data[i]);
    //     }
    //     printf("\n");
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0';
}

int isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o');
}

int main() {
    char input[101];
    Stack s;
    init(&s);

    scanf("%100s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        if (isVowel(input[i])) {
            push(&s, input[i]);
            push(&s, input[i]);
        } else
            push(&s, input[i]);
    }

    while (!isEmpty(&s)) {
        printf("%c", pop(&s));
    }
    printf("\n");

    return 0;
}
