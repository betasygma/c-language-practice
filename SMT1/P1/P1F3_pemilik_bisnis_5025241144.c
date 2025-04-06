#include <stdio.h> 

int main() {

    // deklarasi
    unsigned long long x, y, z;

    // input stok dari tiga toko
    printf("Masukkan jumlah stok kue di toko X, Y, dan Z secara berurutan\nContoh masukan: \"80 250 100\"\n");
    scanf("%llu %llu %llu", &x, &y, &z);

    // nyari stok terbanyak
    if ((x >= y) && (x >= z)) {
        printf("Stok terbanyak : %llu\n", x);
    }
    else if (y >= z) {
        printf("Stok terbanyak : %llu\n", y);
    }
    else {
        printf("Stok terbanyak : %llu\n", z);
    }

    // nyari stok terendah
    if ((x <= y) && (x <= z)) {
        printf("Stok terendah : %llu\n", x);
    }
    else if (y <= z) {
        printf("Stok terendah : %llu\n", y);
    }
    else {
        printf("Stok terendah : %llu\n", z);
    }

    // ada yang stoknya sama ga?
    if ((x == y) || (x == z) || (y == z)) {
        printf("Terdapat toko dengan stok yang sama : %llu\n", x);
    }
    else {
        printf("Tidak ada stok yang sama\n");
    }

    return 0;
}