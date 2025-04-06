#include <stdio.h>
#include <math.h>

int main()
{
    int T, N[100001];
    int n_modus = 0;
    int modus = 1;
    int max = 0;
    int prima = 1;
    
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int harga;
        scanf("%d", &harga);
        if (harga > max)
            max = harga;
        N[harga]++;
    }

    n_modus = N[1];
    for (int i = 2; i <= max; i++) {
        if (N[i] >= n_modus) {
            // n_modus = N[i];
            modus = i;
        }
    }

    printf("Modus: %d\n", modus);
    for (int i = 2; i <= modus/2; i++) {
        if (modus % i == 0) {
            prima = 0;
            break;
        }
    }
    if (prima == 0 || modus == 1) {
        printf("Yah, modusnya gak prima.");
    } else if (prima == 1) {
        printf("Wah, modusnya prima nihh.");
    }

    return 0;
}