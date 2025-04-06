#include <stdio.h>

int jumlahKuadrat(int a) {
    int r = 1;
    for (int i = 2; i <= a; i++) r = r + i * i;
    return r;
}

int main() {
    int a;
    scanf("%d", &a);
    printf("%d\n", jumlahKuadrat(a));
}