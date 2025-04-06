#include <stdio.h>

long long kombinasi(int n) {
    if (n == 1) return 2;
    return 3 * kombinasi(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("Ada %lld model, bebaskan aku!\n", kombinasi(n));
}