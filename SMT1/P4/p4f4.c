#include <stdio.h>
#include <string.h>

int getPrecedence(char key);
void nextPermutation(char *str);

int main() {
    char input[100005];
    scanf("%s", input);

    nextPermutation(input);

    printf("%s\n", input);
    return 0;
}

int getPrecedence(char key) {
    switch (key) {
        case 'q': return 1; case 'w': return 2; case 'e': return 3;
        case 'r': return 4; case 't': return 5; case 'y': return 6;
        case 'u': return 7; case 'i': return 8; case 'o': return 9;
        case 'p': return 10; case 'a': return 11; case 's': return 12;
        case 'd': return 13; case 'f': return 14; case 'g': return 15;
        case 'h': return 16; case 'j': return 17; case 'k': return 18;
        case 'l': return 19; case 'z': return 20; case 'x': return 21;
        case 'c': return 22; case 'v': return 23; case 'b': return 24;
        case 'n': return 25; case 'm': return 26;
    }
    return 0;
}

void nextPermutation(char *str) {
    int n = strlen(str);
    char *p = str + n - 1;

    char *mark = NULL;
    for (; p > str; p--) {
        if(getPrecedence(*(p - 1)) < getPrecedence(*p)) {
            mark = p - 1;
            break;
        }
    }

    if(!mark) {
        for (int i = 0; i < n/2; i++){
            char temp = str[i];
            str[i] = str[n - 1 - i];
            str[n - 1 - i] = temp;
        }
        return;
    }

    char *swapWith = NULL;
    for (p = str + n - 1; p > mark; p--) {
        if (getPrecedence(*p) > getPrecedence(*mark)) {
            swapWith = p;
            break;
        }
    }

    char temp = *mark;
    *mark = *swapWith;
    *swapWith = temp;

    char *left = mark + 1, *right = str + n - 1;
    while (left < right) {
        temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}