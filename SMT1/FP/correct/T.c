#include <stdio.h>
#include <string.h>
#define SIZE 5

char binerKeKar(const char *biner) {
    int nilai = 0;
    for (int i = 0; i < 8; i++) {
        nilai = nilai * 2 + (biner[i] - '0');
    }
    return (char)nilai;
}

int nyariKata(char (*dataKar)[SIZE], const char *kata) {
    int len = strlen(kata);
    int nemu = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j <= SIZE - len; j++) {
            nemu = 1;
            for (int k = 0; k < len; k++) {
                if (dataKar[i][j + k] != kata[k]) {
                    nemu = 0;
                    break;
                }
            }
            if (nemu) return 1;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j <= SIZE - len; j++) {
            nemu = 1;
            for (int k = 0; k < len; k++) {
                if (dataKar[j + k][i] != kata[k]) {
                    nemu = 0;
                    break;
                }
            }
            if (nemu) return 1;
        }
    }
    
    return 0;
}

int main () {
    char kata[6], dataBiner[SIZE][SIZE][9], dataKar[SIZE][SIZE];

    scanf("%s", kata);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%s", dataBiner[i][j]);
            dataKar[i][j] = binerKeKar(dataBiner[i][j]);
        }
    }
    
    if (nyariKata(dataKar, kata)) printf("%s found\n", kata);
    else printf("Failed to find the specified word: %s\n", kata);
}