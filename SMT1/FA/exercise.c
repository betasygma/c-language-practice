/*
1. Faktorial
2. Jumlah Kuadrat
3. KPK
4. FPB
5. Palindrom (integer dan string)
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
// #define MOD 1000000007

// int main() {
//     int n;
//     scanf("%d", &n);
//     unsigned long long r = 1;
//     for (int i = 1; i <= n; i++) {
//         r *= i;
//     }
//     printf("%llu\n", r);
//     return 0;
// }

// unsigned long long faktorial(int n) {
//     if (n == 0 || n == 1) return 1;
//     return n * faktorial(n - 1);
// }

// unsigned long long faktorial(int n) {
//     unsigned long long r = 1;
//     for (int i = 2; i <= n; i++) {
//         r *= i;
//     }
//     return r;
// }

// int main() {
//     int n;
//     scanf("%d", &n);
//     printf("%llu\n", faktorial(n));
//     return 0;
// }

// unsigned long long kombinasi(int n, int k) {
//     if (k > n) return 0;
//     unsigned long long num = faktorial(n);
//     unsigned long long denom = faktorial(k) * faktorial(n - k);
//     return num / denom;
// }

// int main() {
//     int n, k;
//     scanf("%d%d", &n, &k);
//     printf("%llu\n", kombinasi(n, k));
//     return 0;
// }

// unsigned long long jumlahKuadrat(int n) {
//     unsigned long long r = 0;
//     for (int i = 1; i <= n; i++) r += i * i;
//     return r;
// }

// int main() {
//     int n;
//     scanf("%d", &n);
//     printf("%llu\n", jumlahKuadrat(n));
//     return 0;
// }

// int jumlahKuadrat(int n) {
//     unsigned long long r = 0;
//     for (int i = 1; i <= n; i++) r += (r + i * i) % MOD;
//     return (int)r;
// }

// int main() {
//     int n;
//     scanf("%d", &n);
//     printf("%d\n", jumlahKuadrat(n));
//     return 0;
// }

// int fpb(int a, int b) {
//     while (b != 0) {
//         int c = b;
//         b = a % b;
//         a = c;
//     }
//     return a;
// }

// int kpk(int a, int b) {
//     return a * b / fpb(a, b);
// }

// int kpkLipat(int arr[], int n) {
//     int r = arr[0];
//     for (int i = 1; i < n; i++) {
//         r = kpk(r, arr[i]);
//     }
//     return r;
// }

// int main() {
//     int a, b;
//     scanf("%d%d", &a, &b);
//     int n;
//     scanf("%d", &n);
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }
//     printf("%d\n", kpkLipat(arr, n));
// }

// int palindromGa(int x) {
//     if (x < 0 || (x % 10 == 0 && x != 0)) return 0;
//     int xBalik = 0, xOri = x;
//     while (x > xBalik) {
//         xBalik = xBalik * 10 + x % 10;
//         x /= 10;
//     }
//     return xOri == xBalik;
// }

// int palindromGa(int x) {
//     if (x < 0 || (x % 10 == 0 && x != 0)) return 0;
//     int xBalik = 0;
//     while (x > xBalik) {
//         xBalik = xBalik * 10 + x % 10;
//         x /= 10;
//     }
//     return x == xBalik || x == xBalik / 10;
// }

// int main() {
//     int angka;
//     scanf("%d", &angka);
//     if (palindromGa(angka)) printf("Palindrom!\n");
//     else printf("Ga palindrom!\n");
//     return 0;
// }

// int isPalindrome(char str[]) {
//     int left = 0;                 // Pointer kiri
//     int right = strlen(str) - 1;  // Pointer kanan
//     while (left < right) {
//         if (str[left] != str[right]) return 0;  // Bukan palindrom
//         left++;  // Menggerakkan pointer kiri ke kanan
//         right--; // Menggerakkan pointer kanan ke kiri
//     }
//     return 1;
// }

int isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right) {
        while (left < right && !isalnum(str[left])) left++; // Lewati karakter non-alfabet di kiri
        while (left < right && !isalnum(str[right])) right--; // Lewati karakter non-alfabet di kanan
        if (tolower(str[left]) != tolower(str[right])) return 0; // Bukan palindrom
        left++;
        right--;
    }
    return 1; // Palindrom jika tidak ditemukan ketidaksamaan
}

int main() {
    char str[100];
    // scanf("%s", str);
    fgets(str, sizeof(str), stdin);
    if (isPalindrome(str)) printf("Palindrome\n");
    else printf("Not palindrome\n");
    return 0;
}