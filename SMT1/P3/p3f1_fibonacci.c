#include <stdio.h>

long long memo[50] = {0};

long long fibo(int n);  // fungsi fibo ke-n
int max(int x, int n);  // fungsi nyari n fibo max <= X
void print(int n);      // fungsi print dari fibo max sampe 0
long long sum(int n);   // fungsi ngitung jumlah deret fibo

int main() {
    int x;
    scanf("%d", &x);

    memo[0] = 0;
    memo[1] = 1;

    int n = max(x, 0);
    print(n);
    printf("\n%lld\n", sum(n));

    return 0;
}

long long fibo(int n) {
    if(memo[n] != 0 || n == 0) return memo[n];
    memo[n] = fibo(n - 1) + fibo(n - 2);
    return memo[n];
}

int max(int x, int n) {
    if(fibo(n) > x) return n - 1;
    return max(x, n + 1);
}

void print(int n) {
    if(n < 0) return;
    printf("%lld", fibo(n));
    if(n > 0) printf(" ");
    print(n - 1);
}

long long sum(int n) {
    if(n < 0) return 0;
    return fibo(n) + sum(n - 1);
}