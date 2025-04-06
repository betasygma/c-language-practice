#include <stdio.h>
#include <string.h>

/*
void tambah (int x, int y, int *z) {
    *z = x + y;
}

int main(){
    int a = 1, b = 2, c;
    tambah(a, b, &c);
    printf("%d\n", c);
}
*/

struct UN {
    char nama[50];
    int mtk, ipa, bind, bing;
};

int main() {
    int n;
    scanf("%d", &n);

    struct UN un[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", un[i].nama, &un[i].mtk, &un[i].ipa, &un[i].bind, &un[i].bing);
    }
    
    int o;
    scanf("%d", &o);
    
    char cari[o][100];
    for (int i = 0; i < o; i++) {
        scanf("%s", cari[i]);
    }
    
    for (int i = 0; i < o; i++) {    
        int found = 0;
        for (int j = 0; j < n; j++) {
            if(strcmp(cari[i], un[j].nama) == 0) {
                printf("Nilai %s\n", cari[i]);
                printf("Matematika : %d\n", un[j].mtk);
                printf("IPA : %d\n", un[j].ipa);
                printf("Bahasa Indonesia : %d\n", un[j].bind);
                printf("Bahasa Inggris : %d\n", un[j].bing);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Nilai %s tidak ditemukan\n", cari[i]);
        }
    }
}
