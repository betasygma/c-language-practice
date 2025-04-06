#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// int s(int y);

// int main() {

//     int x;

//     for (x = 1; x <= 10; x++) {
//         printf ("%d\n", s(x));
//     }
    
//     printf("\n");

//     return 0;
// }

// int s(int y) {
//     return pow(y, 2);
// }



// int palingbesar(int x, int y, int z);

// int main() {

//     int angka1, angka2, angka3;

//     printf ("Masukin tiga integer: ");
//     scanf ("%d%d%d", &angka1, &angka2, &angka3);

//     printf ("Angka paling besar itu %d\n", palingbesar(angka1, angka2, angka3));

//     return 0;
// }

// int palingbesar(int x, int y, int z) {

//     int maks = x;

//     if (y > maks) {
//         maks = y;
//     }

//     if (z > maks) {
//         maks = z;
//     }

//     return maks;
// }



// int main() {

//     for (int i = 1; i <= 20; i++) {
        
//         printf ("%10d", 1 + (rand() % 10));

//         if (i % 5 == 0) {
//             printf ("\n");
//         }
//     }

//     return 0;
// }



// int main() {

//     int f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0;
//     int roll, face;

//     for (roll = 1; roll <=6000; roll++) {
//         face = 1 + rand() % 6;
        
//         switch (face) {
//             case 1:
//                 ++f1;
//                 break;
            
//             case 2:
//                 ++f2;
//                 break;
            
//             case 3:
//                 ++f3;
//                 break;
            
//             case 4:
//                 ++f4;
//                 break;
            
//             case 5:
//                 ++f5;
//                 break;
            
//             case 6:
//                 ++f6;
//                 break;
//         }
//     }

//     printf("%s%13s\n", "Face", "Frequency");
//     printf ("   1%13d\n", f1);
//     printf ("   2%13d\n", f2);
//     printf ("   3%13d\n", f3);
//     printf ("   4%13d\n", f4);
//     printf ("   5%13d\n", f5);
//     printf ("   6%13d\n", f6);


//     return 0;
// }



// int main() {

//     int i;
//     unsigned biji;

//     printf ("Masukin biji: ");
//     scanf ("%u", &biji);

//     srand(biji);

//     for (i = 1; i <=10; i++) {
//         printf ("%10d", 1 + (rand() % 6));

//         if (i == 5) {
//             printf ("\n");
//         }
//     }

//     return 0;
}



enum Status {CONTINUE, WON, LOST};

int rollDice (void);

int main() {

    int sum, myPoint;

    enum Status gameStatus;

    srand (time (NULL));

    sum = rollDice();

    switch (sum) {
        case '7':
        case '12':
            gameStatus = WON;
            break;
        
        default:
            break;
    }
}
