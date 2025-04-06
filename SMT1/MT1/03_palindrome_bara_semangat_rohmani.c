#include <stdio.h>
#include <string.h>
#include <ctype.h>  // pakai tolower

int isPalindrome (char word[], int start, int end);

int main() {
    char word[1000000];

    printf ("Enter a word or sentence: ");
    fgets (word, sizeof(word), stdin);  // baca input
    word[strcspn(word, "\n")] = 0;  // ilangin newline (\n) dari input

    int len = strlen(word) - 1; // nyari panjang string tanpa newline (\n)

    // panggil fungsi & cek hasil
    if (isPalindrome(word, 0, len)) printf("It is a palindrome.\n");
    else printf("It is not a palindrome.\n");

    return 0;
}

int isPalindrome (char word[], int start, int end) {
    if (start >= end) return 1; // kalau word terdiri dari "1 karakter" atau pengecekan udah sampai/melewati "karakter tengah"

    // abaikan case dengan tolower, pake XOR buat mbandingin
    if((tolower(word[start]) ^ tolower(word[end])) != 0) return 0;

    // rekursif buat cek pasangan karakter selanjutnya
    return isPalindrome(word, start + 1, end - 1);
}