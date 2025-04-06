#include <stdio.h>

int main()
{
    // Deklarasi nilai dan jenis kartu
    int n1, n2, n3, n4, n5;
    char j1, j2, j3, j4, j5;

    // Mbaca input
    scanf("%d %c", &n1, &j1);
    scanf("%d %c", &n2, &j2);
    scanf("%d %c", &n3, &j3);
    scanf("%d %c", &n4, &j4);
    scanf("%d %c", &n5, &j5);

    // Cek Four of a Kind
    if (((n1 == n2) && (n1 == n3) && (n1 == n4)) || ((n1 == n2) && (n1 == n3) && (n1 == n5)) || ((n1 == n2) && (n1 == n5) && (n1 == n4)) || ((n1 == n5) && (n1 == n3) && (n1 == n4)) || ((n5 == n2) && (n5 == n3) && (n5 == n4))) {
        printf("Four of a Kind\n");
    }

    // Cek Full House
    else if (((n1 == n2) && (n1 == n3) && (n4 == n5)) || ((n1 == n2) && (n1 == n4) && (n3 == n5)) || ((n1 == n2) && (n1 == n5) && (n3 == n4)) || ((n1 == n3) && (n1 == n4) && (n2 == n5)) || ((n1 == n3) && (n1 == n5) && (n2 == n4)) || ((n1 == n4) && (n1 == n5) && (n2 == n3)) || ((n2 == n3) && (n2 == n4) && (n1 == n5)) || ((n2 == n3) && (n2 == n5) && (n1 == n4)) || ((n2 == n4) && (n2 == n5) && (n1 == n3)) || ((n3 == n4) && (n3 == n5) && (n1 == n2))) {
        printf("Full House\n");
    }

    // Cek Flush
    else if ((j1 == j2) && (j1 == j3) && (j1 == j4) && (j1 == j5)) {
        printf("Flush\n");
    }

    // Cek Three of a Kind
    else if (((n1 == n2) && (n1 == n3)) || ((n1 == n2) && (n1 == n4)) || ((n1 == n2) && (n1 == n5)) || ((n1 == n3) && (n1 == n4)) || ((n1 == n3) && (n1 == n5)) || ((n1 == n4) && (n1 == n5)) || ((n2 == n3) && (n2 == n4)) || ((n2 == n3) && (n2 == n5)) || ((n2 == n4) && (n2 == n5)) || ((n3 == n4) && (n3 == n5))) {
        printf("Three of a Kind\n");
    }

    // Cek Two Pair
    else if (((n1 == n2) && (n3 == n4)) || ((n1 == n2) && (n3 == n5)) || ((n1 == n2) && (n4 == n5)) || ((n1 == n3) && (n2 == n4)) || ((n1 == n3) && (n2 == n5)) || ((n1 == n3) && (n4 == n5)) || ((n1 == n4) && (n2 == n3)) || ((n1 == n4) && (n2 == n5)) || ((n1 == n4) && (n3 == n5)) || ((n1 == n5) && (n2 == n3)) || ((n1 == n5) && (n2 == n4)) || ((n1 == n5) && (n3 == n4)) || ((n2 == n3) && (n1 == n4)) || ((n2 == n3) && (n1 == n5)) || ((n2 == n3 && (n4 == n5)) || ((n2 == n4) && (n1 == n3)) || ((n2 == n4) && (n1 == n5)) || ((n2 == n4) && (n3 == n5)) || ((n2 == n5) && (n1 == n3)) || ((n2 == n5) && (n1 == n4)) || ((n2 == n5) && (n3 == n4)) || ((n3 == n4) && (n1 == n2)) || ((n3 == n4) && (n1 == n5)) || ((n3 == n4) && (n2 == n5)) || ((n3 == n5) && (n1 == n2)) || ((n3 == n5) && (n1 == n4)) || ((n3 == n5) && (n2 == n4)) || ((n4 == n5) && (n1 == n2)) || ((n4 == n5) && (n1 == n3)) || ((n4 == n5) && (n2 == n3)))) {
        printf("Two Pair\n");
    }

    // Cek One Pair
    else if ((n1 == n2) || (n1 == n3) || (n1 == n4) || (n1 == n5) || (n2 == n3) || (n2 == n4) || (n2 == n5) || (n3 == n4) || (n3 == n5) || (n4 == n5)) {
        printf("One Pair\n");
    }

    // Ga ada kombinasi
    else {
        printf("Tidak ada kombinasi khusus\n");
    }
    
    return 0;
}