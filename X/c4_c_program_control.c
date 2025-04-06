// struct timespec start, end;
// clock_gettime(CLOCK_MONOTONIC, &start);

// clock_gettime(CLOCK_MONOTONIC, &end);
// long time = (end.tv_nsec - start.tv_nsec);
// printf("time: %ld nanoseconds\n", time);

#include <stdio.h>
#include <math.h>

int main() {
    // int counter = 0;

    // while (counter < 10) {
    //     printf ("%d\n", counter);
    //     ++counter;
    // }



    // int counter;

    // for (counter = 1; counter <= 10; counter++) {
    //     printf ("%d\n", counter);
    // }

    // for (int i = 0, j = 0; j + i <=10; i++, j++) {
    //     printf ("%d\n", j + i);
    // }



    // int sum = 0;
    // int number;

    // for (number = 2; number <= 100; number +=2) {
    //     sum += number;
    // }

    // printf ("Sum is %d\n", sum);



    // double amount, principal = 1000.0, rate = 1;
    // int year;

    // printf ("%4s%21s\n", "Year", "Amount on deposit");

    // for (year = 1; year <= 10; year++) {
    //     amount = principal * pow(1.0 + rate, year);

    // printf ("%4d%21.2f\n", year, amount);
    // }



    // int grade, aC = 0, bC = 0, cC = 0, dC = 0, fC = 0;

    // printf ("Enter the letter grades.\n");
    // printf ("Enter the EOF character to end input.\n");

    // while ( (grade = getchar()) != EOF) {
    //     switch (grade) {
    //         case 'A':
    //         case 'a':
    //             ++aC;
    //             break;
            
    //         case 'B':
    //         case 'b':
    //             ++bC;
    //             break;

    //         case 'C':
    //         case 'c':
    //             ++cC;
    //             break;

    //         case 'D':
    //         case 'd':
    //             ++dC;
    //             break;

    //         case 'F':
    //         case 'f':
    //             ++fC;
    //             break;

    //         case '\n':
    //         case '\t':
    //         case ' ':
    //             break;

    //         default:
    //             printf ("Incorrect letter grade entered. Enter a new grade.\n");
    //     }
    // }

    // printf ("\nTotals for each letter grade are:\n");
    // printf ("A: %d\n", aC);
    // printf ("B: %d\n", bC);
    // printf ("C: %d\n", cC);
    // printf ("D: %d\n", dC);
    // printf ("F: %d\n", fC);



    // int counter = 1;

    // do {
    //     printf ("%d ", counter);
    // } while (++counter <= 0);
    


    // int i;
    
    // for (i = 1; i <= 10; i++)
    // {
    //     if (i == 5) {
    //         break;
    //     }

    //     printf ("%d ", i);
    // }

    // printf("\nBroke out of loop at i == %d\n", i);
    


    // int i;

    // for (i = 1; i <= 10; i++)
    // {
    //     if (i == 5) {
    //         continue;
    //     }

    //     printf ("%d ", i);
    // }

    // printf("\nUsed continueto skip printing the value 5\n");
    
    return 0;
}