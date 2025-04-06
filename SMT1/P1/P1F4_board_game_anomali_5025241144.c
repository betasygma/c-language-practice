#include <stdio.h>

int main()
{
    // deklarasi
    unsigned long long a, b, c, d, e, f, g, h, i;
    int arya = 0, andi = 0;

    // input angka
    scanf("%llu %llu %llu %llu %llu %llu %llu %llu %llu", &a, &b, &c, &d, &e, &f, &g, &h, &i);

    // kalkulasi sederhana (modulo)
    a %= 3;
    b %= 3;
    c %= 3;
    d %= 3;
    e %= 3;
    f %= 3;
    g %= 3;
    h %= 3;
    i %= 3;

    // bikin kotak tic-tac-toe
    printf("%llu | %llu | %llu\n", a, b, c);
    printf("%llu | %llu | %llu\n", d, e, f);
    printf("%llu | %llu | %llu\n", g, h, i);

    // kemenangan arya
    if (a == 1 && b == 1 && c == 1)
        arya++;
    if (d == 1 && e == 1 && f == 1)
        arya++;
    if (g == 1 && h == 1 && i == 1)
        arya++;
    if (a == 1 && d == 1 && g == 1)
        arya++;
    if (b == 1 && e == 1 && h == 1)
        arya++;
    if (c == 1 && f == 1 && i == 1)
        arya++;
    if (a == 1 && e == 1 && i == 1)
        arya++;
    if (g == 1 && e == 1 && c == 1)
        arya++;

    // kemenangan andi
    if (a == 2 && b == 2 && c == 2)
        andi++;
    if (d == 2 && e == 2 && f == 2)
        andi++;
    if (g == 2 && h == 2 && i == 2)
        andi++;
    if (a == 2 && d == 2 && g == 2)
        andi++;
    if (b == 2 && e == 2 && h == 2)
        andi++;
    if (c == 2 && f == 2 && i == 2)
        andi++;
    if (a == 2 && e == 2 && i == 2)
        andi++;
    if (g == 2 && e == 2 && c == 2)
        andi++;

    // output kemenangan
    if (arya == 1 && andi == 0) {
        printf("Keberuntungan ada di kamu, selamat Arya");
    }
    else if (arya == 0 && andi == 1) {
        printf("Keberuntungan ada di kamu, selamat Andi");
    }
    else if (arya == 1 && andi == 1) {
        printf("Terjadi anomali dua kemenangan!\n");
        printf("Lah dua duanya menang, selamat Arya dan Andi");
    }
    else if (arya == 2 && andi == 0) {
        printf("Terjadi anomali dua kemenangan!\n");
        printf("Lah menang dua kali kamu Arya");
    }
    else if (arya == 0 && andi == 2) {
        printf("Terjadi anomali dua kemenangan!\n");
        printf("Lah menang dua kali kamu Andi");
    }

    else if (arya == 0 && andi == 0) {
        printf("Yahh kurang beruntung nih, gaada kemenangan!");
    }

    return 0;
}