#include <stdio.h>

int faktorial(int n) {
    int r = 1;
    for (int i = 2; i <= n; i++) r *= i;
    return r;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", faktorial(n));
}