#include <stdio.h>
#include <string.h>

void bacaKode(char *input, int t);

int main() {
    int t;
    scanf("%d", &t);
    char s[1001];
    scanf("%s", s);

    bacaKode(s, t);
}

void bacaKode(char *input, int baris){
    int len = strlen(input);
    int kolom = len / baris;
    int karSisa = len % baris;
    if (karSisa != 0) kolom++;

    for (int i = 0; i < len; i++)
        if (input[i] == '_') input[i] = ' ';

    char matriks[baris][kolom];

    int kar = 0;
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            if (karSisa != 0 && i >= karSisa && j == kolom - 1) matriks[i][j] = '_';
            else matriks[i][j] = input[kar++];
        }
    }
    for (int j = 0; j < kolom; j++) {
        for (int i = 0; i < baris; i++) {
            if (matriks[i][j] != '_') printf("%c", matriks[i][j]);
        }
    }
}