#include <stdio.h>

long long r[71] = {0};

long long rumus(int n, long long r[]) {
    if(r[n] != 0 || n == 0) return r[n];
    r[n] = rumus(n - 1, r) + rumus(n - 2, r) + rumus(n - 3, r);
    return r[n];
}

long long print(int n) {
    if(n < 0) return 0;
    printf("%lld", rumus(n, r));
    if(n > 0) printf(" ");
    print(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);

    r[0] = 0;
    r[1] = 1;
    r[2] = 2;

    print(n);
    printf("\n");
}