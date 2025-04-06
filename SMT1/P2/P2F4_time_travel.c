#include <stdio.h>
#include <math.h>

int isPalindrome (char word[], int start, int end);

int main() {
    long long N, M, F, K = 0;   // tahun, waktu butuh, BB punya, BB butuh 
    scanf ("%lld %lld %lld", &N, &M, &F);
    
    // waktu punya max (N XOR K) > M
    // 0 <= K && K <= F

    int digit;
    digit = log2(F) + 1;

    int x = 0;

    for (int i = 1; i <= digit; i++) {
        int sN = (N >> (digit - i)) & 1;
        int sF = (F >> (digit - i)) & 1;

        if (sN == 1 && sF == 1) {
            K = K << 1;
            x = 1;
        } else if (sN == 1 && sF == 0) {
            K = K << 1;
        } else if (sN == 0 && sF == 1) {
            K = K << 1;
            K++;
        } else if (sN == 0 && sF == 0) {
            if (x == 1) {
                K = K << 1;
                K++;
            } else {
                K = K << 1;
            }
        }
    }

    if ((N ^ K) >= M) {
        printf ("HAHAHA, I CAN SAVE THE WORLD");
    } else {
        printf ("OH NOOO, I FAILED");
    }

    return 0;
}