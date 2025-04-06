#include <stdio.h>

long long pola(int a) {
    if (a == 0) return 0;
    int polatengah = (a * (a + 1)) / 2;
    return polatengah + 2 * pola(a - 1);
}

int main () {
    int n;
    scanf("%d", &n);
    printf("%lld\n", pola(n));
}