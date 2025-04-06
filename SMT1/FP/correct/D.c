#include <stdio.h>
#include <string.h>

int genap(int n) {
    if (n < 2) return 0;
    if (n % 2 == 0) return n + genap(n - 2);
    else return n - 1 + genap(n - 3);
}

int ganjil(int n) {
    if (n < 1) return 0;
    if (n % 2 == 0) return n - 1 + ganjil(n - 3);
    else return n + ganjil(n - 2);
}

int main() {
    char c[101];
    int n;
    scanf("%s %d", c, &n);

    if (strcmp(c, "Ellie") == 0) printf("%d\n", genap(n));
    else if (strcmp(c, "Oddie") == 0) printf("%d\n", ganjil(n));
    else printf("Who is that?\n");
    
    return 0;
}