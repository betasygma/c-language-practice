#include <stdio.h>

int f(int x) {
    if(x%2 == 0) return x/2;
    else return x*2;
}

int g(int x) {
    if(x%2 == 0) return x+2;
    else return x-2;
}

int rec(int x, int n) {
    if(n == 1) return f(x);
    if(n%2 != 0) return f(x + rec(x, n-1));
    else return g(x + rec(x, n-1));
}

int main() {
    int x, n;
    scanf("%d %d", &x, &n);

    printf("%d\n", rec(x, n));
}