/*SOAL 1
Buatlah program yang mengimplementasikan
fungsi rekursif untuk menentukan nilai
dari N! (N faktorial).*/
/*
#include <stdio.h>
#include <time.h>

int faktorial(int N) {
    if(N == 0) return 1;
    return (N * faktorial(N-1));
}

int main() {
    int N, Nf;
    printf("nilai N: ");
    scanf("%d", &N);

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    Nf = faktorial(N);

    clock_gettime(CLOCK_MONOTONIC, &end);
    long time = (end.tv_nsec - start.tv_nsec);

    printf("%d\n", Nf);
    printf("time: %ld nanoseconds\n", time);
}
*/

/* SOAL 2
Diberikan sebuah baris bilangan 1, 5, 14, 30, ... dst.
Buatlah sebuah program yang mengimplementasikan
fungsi rekursif untuk menentukan bilangan ke-n
dari pola tersebut.*/

#include <stdio.h>
#include <math.h>

int sumpow(int a) {
    if(a == 1) return 1;
    return (pow(a, 2) + sumpow(a-1));
}

int main() {
    int n;
    printf("nilai n: ");
    scanf("%d", &n);
    printf("%d\n", sumpow(n));
}

/*SOAL 3
Buatlah program yang mengimplementasikan fungsi
untuk menentukan bilangan terbesar dan terkecil
dari array A dengan N bilangan.*/
/*
#include <stdio.h>
#include <limits.h>

int mx(int a[], int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) if(a[i] > max) max = a[i];
    return max;
}

int mn(int a[], int n) {
    int min = INT_MAX;
    for (int i = 0; i < n; i++) if(a[i] < min) min = a[i];
    return min;
}


int main() {
    int n;
    printf("n: ");
    scanf("%d", &n);

    int A[100];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);

    int max = mx(A, n), min = mn(A, n);
    printf("max: %d\nmin: %d\n", max, min);
}*/



