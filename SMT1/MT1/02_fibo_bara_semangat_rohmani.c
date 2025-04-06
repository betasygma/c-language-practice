#include <stdio.h>
#include <time.h>

int fibonacciIterative(int n);
int fibonacciRecursive(int n);
int fibonacciSum(int n);

int main() {
    int number;

    printf ("Enter a number: ");
    scanf ("%d", &number);

    // ngukur waktu metode iteratif 
    struct timespec start_ite, end_ite;
    clock_gettime(CLOCK_MONOTONIC, &start_ite);
    
    int iterativeResults = fibonacciIterative(number);

    clock_gettime(CLOCK_MONOTONIC, &end_ite);
    long iterativeTime = (end_ite.tv_nsec - start_ite.tv_nsec);
  
    // ngukur waktu metode rekursif
    struct timespec start_rec, end_rec;
    clock_gettime(CLOCK_MONOTONIC, &start_rec);

    int recursiveResult = fibonacciRecursive(number);

    clock_gettime(CLOCK_MONOTONIC, &end_rec);
    long recursiveTime = (end_rec.tv_nsec - start_rec.tv_nsec);

    // jumlah fibo sampe ke-(number)
    int sum = fibonacciSum(number);
    
    // output hasil
    printf ("\nIterative\n%dth Fibonacci = %d\nSum of Fibonacci until %dth term = %d\nIterative time: %ld nanoseconds\n", number, iterativeResults, number, sum, iterativeTime);
    printf ("\nRecursive\n%dth Fibonacci = %d\nSum of Fibonacci until %dth term = %d\nRecursive time: %ld nanoseconds\n", number, recursiveResult, number, sum, recursiveTime);
    
    // banding waktu
    long differenceTime = recursiveTime - iterativeTime;
    if (differenceTime < 0) printf ("\nRecursive method is faster than iterative method by %ld nanoseconds\n", differenceTime);
    else printf ("\nIterative method is faster than recursive method by %ld nanoseconds\n", differenceTime);

    return 0;
}

int fibonacciIterative(int n) {
    int a = 0, b = 1, c, i; // inisialisasi
    if (n == 0) return a;   // F(0)
    for (i = 2; i <= n; i++) {
        c = a + b;          // F(n) = F(n-2) + F(n-1)
        a = b;              // F(n-2) jadi F(n-1)
        b = c;              // F(n-1) jadi F(n)
    }
    return b;               // kembaliin F(n)
}

int fibonacciRecursive(int n) {
    static int f[47];   // fibonacci 47th == 2,971,215,073  >  int == 2,147,483,647
    static int z = 0;   // flag buat ngecek apa array udah diinisialsasi

    // inisialisasi array cuma sekali
    if (!z) {
        for (int i = 0; i < 47; i++) {
            f[i] = -1;
        }
        f[0] = 0;
        f[1] = 1;
        z = 1;  // tanda udah diinisialisasi
    }

    // kasus dasar
    if (n == 0) return 0;
    if (n == 1) return 1;

    // cek, kalo udah pernah keitung langsung kembaliin hasil
    if (f[n] != -1) return f[n];

    // ngitung fibo ke-n & nyimpen hasilnya
    f[n] = fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    return f[n];
}

int fibonacciSum(int n) {
    int s = 0;
    for (int i = 0; i <= n; i++)
        s += fibonacciIterative(i);
    return s;
}