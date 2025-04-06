#include <stdio.h>
// int isPrime(int a);

// int main() {
//     int n[] = {2, 1, 35, 41, 17, 18, 75, 7};
//     for (int i = 0; i < 8; i++) {
//         if(isPrime(n[i]))
//             printf("%d is a prime\n", n[i]);
//         else
//             printf("%d is not a prime\n", n[i]);
//     } 
//     return 0;
// }

// int isPrime(int a) {
//     if(a <= 1) return 0;
//     for (int i = 2; i*i <= a; i++)
//         if(a % i == 0) return 0;
//     return 1;
// }

int faktorial(int n) {
    if(n == 0) return 1;
    return (n * faktorial(n-1));
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d! is %d\n", n, faktorial(n));
}