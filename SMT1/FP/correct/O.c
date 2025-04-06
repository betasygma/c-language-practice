#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char oto[2001][11], aksi[2001][11];
    char otoTertinggi[11] = "", aksiTadi[11] = "", otoTadi[11] = "";

    for (int i = 0; i < n; i++) {
        scanf("%s %s", oto[i], aksi[i]);
    }

    if (strcmp(aksi[0], "istirahat") == 0) {
        printf("Oceanid Minion marah karena belum diperintah apa-apa, tetapi sudah disuruh istirahat!\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (strcmp(oto[i], "furina") == 0) {
            if (strcmp(aksi[i], aksiTadi) != 0) {
                printf("Oceanid Minion %s sesuai keinginan %s.\n", aksi[i], oto[i]);
                strcpy(aksiTadi, aksi[i]);
                strcpy(otoTadi, oto[i]);
            } else printf("Oceanid Minion sudah diperintah %s oleh %s.\n", aksiTadi, otoTadi);
            strcpy(otoTertinggi, "furina");
        }
        else if (strcmp(oto[i], "hutao") == 0) {
            if (strcmp(otoTertinggi, "furina") != 0) {
                if (strcmp(aksi[i], aksiTadi) != 0) {
                    printf("Oceanid Minion %s sesuai keinginan %s.\n", aksi[i], oto[i]);
                    strcpy(aksiTadi, aksi[i]);
                    strcpy(otoTadi, oto[i]);
                } else printf("Oceanid Minion sudah diperintah %s oleh %s.\n", aksiTadi, otoTadi);
                strcpy(otoTertinggi, "hutao");
            }
            else printf("Oceanid Minion tidak nurut karena wewenang %s lebih rendah dari %s.\n", oto[i], otoTertinggi);
        }
        else if (strcmp(oto[i], "lyney") == 0) {
            if (strcmp(otoTertinggi, "furina") != 0 && strcmp(otoTertinggi, "hutao") != 0) {
                printf("Oceanid Minion %s sesuai keinginan %s.\n", aksi[i], oto[i]);
                strcpy(aksiTadi, aksi[i]);
                strcpy(otoTadi, oto[i]);
                strcpy(otoTertinggi, "lyney");
            } else printf("Oceanid Minion tidak nurut karena wewenang %s lebih rendah dari %s.\n", oto[i], otoTertinggi);
        }
    }
    return 0;
}