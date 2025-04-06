#include <stdio.h>

int main() {
    int N, id_buah;
    int buah[11];
    for (int i = 1; i <= 10; i++) {
        buah[i] = 0;
    }

    // printf("input jumlah siswa (N)\n");
    scanf("%d", &N);

    // if(N < 0 || N > 10000) {
    //     printf("jumlah siswa ga valid\n");
    //     return 0;
    // }

    // printf("input ID buah sesuai jumlah siswa\n");
    for(int i = 0; i < N; i++) {
        scanf("%d", &id_buah);
        // if(id_buah >=1 && id_buah <= 10) {
            buah[id_buah]++;
        // }
    }

    int jumlah_mayor = buah[1], id_mayor = 1, sama_mayor = 0;

    for(int i = 2; i <= 10; i++) {
        if(buah[i] > jumlah_mayor) {
            jumlah_mayor = buah[i];
            id_mayor = i;
            sama_mayor = 0;
        } else if(buah[i] == jumlah_mayor) {
            sama_mayor = 1;
        }
    }

    int jumlah_minor = N - jumlah_mayor;

    if(sama_mayor == 1) {
        printf("-1");
    } else if (sama_mayor == 0) {
        printf("%d\n", id_mayor);
        printf("%d", jumlah_minor);
    }

    return 0;
}