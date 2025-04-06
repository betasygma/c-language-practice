#include <stdio.h>

int main() {
    int n, k, d, u = 300000, o = 50000, b;
    // kode, harga, diskon, uang Surip, ongkos, bayar
    scanf("%d %d", &n, &k);

    switch (n) {
    case 1:
        d = k * 0.35;
        break;
    case 2:
        d = k * 0.45;
        break;
    case 3:
        d = k * 0.5;
        break;
    case 4:
        d = k * 0.55;
        break;
    case 5:
        d = k * 0.4;
        break;
    default:
        break;
    }
    k -= d;
    if (k >= 250000) o -= o * 1;
    else if (k >= 150000) o -= o * 0.5;
    else if (k >= 50000) o -= o * 0.25;
    b = k + o;
    u -= b;

    if (u > 0) printf("WOHHHH uangku sisa %d\nMamaa Surip bisa kasi THR ke adek adek, tadi totalnya %d\n", u, b);
    else if (u < 0) printf("Mamaa minta uang, uangku kurang %d :((\nTotalnya tadi %d\n", u*-1, b);
    else printf("Yeyyy totalnya pas 300000\nMamaa, Surip udah gede ga jadi minta uang :)\n");

    return 0;
}