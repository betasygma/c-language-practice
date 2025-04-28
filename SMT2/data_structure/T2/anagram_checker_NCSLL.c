#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node {
    char letter;
    struct Node* next;
} Node;

// push-back function
void pushBack(Node** head, char letter) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->letter = letter;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

// split function
void split(Node* head, Node** left, Node** right) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

// merge function 
Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* result = NULL;
    if (left->letter <= right->letter) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

// Merge Sort function
void mergeSort(Node** head) {
    if (*head == NULL || (*head)->next == NULL) return;

    Node* left;
    Node* right;
    split(*head, &left, &right);

    mergeSort(&left);
    mergeSort(&right);

    *head = merge(left, right);
}

// anagram-checker function
int areAnagrams(Node* w1, Node* w2) {
    // if lengths are different, return 0
    int len1 = 0, len2 = 0;
    Node* temp1 = w1;
    Node* temp2 = w2;

    while (temp1) { len1++; temp1 = temp1->next; }
    while (temp2) { len2++; temp2 = temp2->next; }

    if (len1 != len2) return 0;

    // sort both linked-lists
    mergeSort(&w1);
    mergeSort(&w2);

    // compare sorted linked-lists
    while (w1 && w2) {
        if (w1->letter != w2->letter) return 0;
        w1 = w1->next;
        w2 = w2->next;
    }
    return 1;
}

// free memory function
void freeList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// print function
void printList(Node* head) {
    while (head) {
        printf("%c -> ", head->letter);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* w1 = NULL;
    Node* w2 = NULL;

    char word1[MAX], word2[MAX];
    printf("Enter first word: "); scanf("%99s", word1);
    printf("Enter second word: "); scanf("%99s", word2);

    // insert letters into linked lists
    for (int i = 0; word1[i] != '\0'; i++) pushBack(&w1, word1[i]);
    for (int i = 0; word2[i] != '\0'; i++) pushBack(&w2, word2[i]);

    // print the original lists
    printf("Original Word 1: ");
    printList(w1);
    printf("Original Word 2: ");
    printList(w2);

    // Check if they are anagrams
    if (areAnagrams(w1, w2))
        printf("1\n");
    else
        printf("0\n");

    // Free memory
    freeList(w1);
    freeList(w2);

    return 0;
}