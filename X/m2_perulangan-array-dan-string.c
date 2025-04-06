#include <stdio.h>
#include <string.h>


int main() {

    // Soal 1

    // int bilangan;
    // printf ("masukin sebuah bilangan\n");
    // scanf ("%d", &bilangan);

    // if ((bilangan % 2) == 1) {
    //     printf ("Ganjil\n");
    // } else {
    //     printf ("Genap\n");
    // }



    // Soal 2
    // unsigned n;
    
    // printf ("input bilangan bulat positif: ");
    // scanf ("%u", &n);
    
    // if (n >= 1) {
    //     printf ("1");
    // }

    // for (int i = 2; i <= n; i++) {
    //     if (i % 2 == 1) {
    //         printf (" %d", i);
    //     } else {
    //         printf (" *");
    //     }
    // }



    // Soal 3
    unsigned n = 11;
    int isPrime = 1;
    
    // printf ("input bilangan bulat positif: ");
    // scanf ("%u", &n);
    
    if (n < 2) {
        printf ("Nilai n harus lebih besar atau sama dengan 2\n");
        return 0;
    } else {
        printf ("1");
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime) {
            printf (" *");
        } else {
            printf (" %d", i);
        } 
    }

    printf ("\n");
    return 0;
}