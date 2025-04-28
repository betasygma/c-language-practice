#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, char c);
char pop(Stack *s);
char peek(Stack *s);
void printStack(Stack *s);

int precendence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' );
}

void infixToPostfix(char *infix) {
    Stack s;
    initStack(&s);
    char postfix[MAX_SIZE] = "";
    int j = 0;

    printf("%-10s %-15s %-20s\n", "Token", "Stack", "Output");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        if (isspace(c)) continue;

        printf("%-10c ", c);

        if (isdigit(c)) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i];
                i++;
            }
            postfix[j++] = ' ';
            i--;
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            if (!isEmpty(&s) && peek(&s) == '(') {
                pop(&s);
            }
        } else if (isOperator(c)) {
            while (!isEmpty(&s) && precendence(peek(&s)) >= precendence(c)) {
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            push(&s, c);
        }
        
        printStack(&s);
        printf("%-20s\n", postfix);
    }

    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';

    printf("---------------------------------------------------\n");
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX_SIZE] = "(2 + 3) * (8 / 4) - 6";

    printf("Enter infix expression: %s\n", infix);
    // fgets(infix, MAX_SIZE, stdin);
    // infix[strcspn(infix, "\n")] = 0;
    infixToPostfix(infix);

    return 0;
}


void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char c) {
    if (s->top < MAX_SIZE-1)
        s->items[++s->top] = c;
}

char pop(Stack *s) {
    return isEmpty(s) ? '\0' : s->items[s->top--];
}

char peek(Stack *s) {
    return isEmpty(s) ? '\0' : s->items[s->top];
}

void printStack(Stack *s) {
    char stackStr[MAX_SIZE] = "";
    for (int i = 0; i <= s->top; i++) {
        sprintf(stackStr + strlen(stackStr), "%c", s->items[i]);
    }   
    printf("%-15s", stackStr);
}