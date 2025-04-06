#include <stdio.h>
#include <string.h>

int palindromGa(char arr[]) {
    int kiri = 0, kanan = strlen(arr) - 1;
    while (kiri < kanan) {
        if (arr[kiri] != arr[kanan]) return 0;
        kiri++;
        kanan--;
    }
    return 1;
}

int main() {
    char s[257];
    scanf("%s", s);
    if (palindromGa(s)) printf("PALINDROM\n");
    else printf("BUKAN PALINDROM\n");
}