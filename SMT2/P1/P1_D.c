#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int weight, count;
    struct Node *next;
} Node;

int symbolToDigit(char ch) {
    switch (ch) {
        case '!': return 1;
        case '@': return 2;
        case '#': return 3;
        case '$': return 4;
        case '%': return 5;
        case '^': return 6;
        case '&': return 7;
        case '*': return 8;
        case '(': return 9;
        case ')': return 0;
        default: return -1;
    }
}

int convertToInt(char *s) {
    int res = 0;
    for (int i = 0; s[i]; i++) {
        res = res * 10 + symbolToDigit(s[i]);
    }
    return res;
}

void insert(Node **head, int weight) {
    Node *curr = *head, *prev = NULL;

    while (curr && curr->weight > weight) {
        prev = curr;
        curr = curr->next;
    }

    if (curr && curr->weight == weight) {
        curr->count++;
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->count = 1;
    newNode->weight = weight;
    newNode->next = curr;

    if (prev) {
        prev->next = newNode;
    } else {
        *head = newNode;
    }
}

void trySell(Node **head, int *currentExpectation) {
    Node *curr = *head, *prev = NULL;

    while (curr && *currentExpectation > 0) {
        if (curr->weight == *currentExpectation) {
            printf("%d ", *currentExpectation);
            curr->count--;
            (*currentExpectation)--;

            if (curr->count == 0) {
                if (prev)
                    prev->next = curr->next;
                else
                    *head = curr->next;
                free(curr);
                curr = (prev ? prev->next : *head);
            } else {
                curr = curr->next;
            }
        } else {
            curr = curr->next;
        }
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Node *head = NULL;

    for (int i = 0; i < n; i++) {
        char fishWeightCode[6];
        scanf("%s", fishWeightCode);
        int weight = convertToInt(fishWeightCode);
        insert(&head, weight);
        trySell(&head, &m);
    }
    return 0;
}
