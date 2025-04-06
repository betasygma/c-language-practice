#include <stdio.h>
#define MOD 1000000007

void multiply(long long mat1[2][2], long long mat2[2][2]) {
    long long a = (mat1[0][0] * mat2[0][0] % MOD + mat1[0][1] * mat2[1][0] % MOD) % MOD;
    long long b = (mat1[0][0] * mat2[0][1] % MOD + mat1[0][1] * mat2[1][1] % MOD) % MOD;
    long long c = (mat1[1][0] * mat2[0][0] % MOD + mat1[1][1] * mat2[1][0] % MOD) % MOD;
    long long d = (mat1[1][0] * mat2[0][1] % MOD + mat1[1][1] * mat2[1][1] % MOD) % MOD;
    
    mat1[0][0] = a;
    mat1[0][1] = b;
    mat1[1][0] = c;
    mat1[1][1] = d;
}

void power(long long mat[2][2  ], long long n) {
    if (n <= 1) return;

    long long base[2][2] = {{mat[0][0], mat[0][1]}, {mat[1][0], mat[1][1]}};

    power(mat, n / 2);
    multiply(mat, mat);

    if (n % 2 != 0) multiply(mat, base);
}

long long fibonacci(long long x, long long y, long long a, long long b, long long n) {
    if (n == 0) return x % MOD;
    if (n == 1) return y % MOD;
    
    long long mat[2][2] = {{a, b}, {1, 0}};
    power(mat, n - 1);

    return (mat[0][0] * y % MOD + mat[0][1] * x % MOD) % MOD;
}

int main() {
    long long x, y, a, b, n;
    scanf("%lld %lld %lld %lld %lld", &x, &y, &a, &b, &n);

    printf("%lld\n", fibonacci(x, y, a, b, n));
    return 0;
}
