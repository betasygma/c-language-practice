#include <stdio.h>
#include <limits.h>
#include <math.h>

int max(int a[], unsigned int aSize);
int min(int a[], unsigned int aSize);
int sum(int a[], unsigned int aSize);
double average(int sum, unsigned int aSize);
double sDeviation(int a[], double mean, unsigned int aSize);

int main() {
    int i;
    int a[10] = {32, 27, 64, 18, 95, 14, 90, 70, 60, 37};

    printf ("%s%13s\n", "Element", "Value");
    for (i = 0; i < 10; i++) printf("%7d%13d\n", i, a[i]);
    
    unsigned aSize = sizeof(a) / sizeof(a[0]);
    printf ("Size of a = %u\n", aSize);

    printf ("max(): %d\n", max(a, aSize));
    printf ("min(): %d\n", min(a, aSize));

    int arraySum = sum(a, aSize);
    printf ("sum(): %d\n", arraySum);

    double avg = average(arraySum, aSize);
    printf("average(): %.3f\n", avg);

    printf("sDeviation(): %.3f\n", sDeviation(a, avg, aSize));

    return 0;
}

int max (int a[], unsigned int aSize) {
    int i;
    int max = INT_MIN;
    for (i = 0; i < aSize; i++) 
        if (a[i] > max)
            max = a[i];
    return max;
}

int min (int a[], unsigned int aSize) {
    int i;
    int min = INT_MAX;
    for (i = 0; i < aSize; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

int sum (int a[], unsigned int aSize) {
    int i;
    int s = 0;
    for (i = 0; i < aSize; i++)
        s += a[i];
    return s;
}

double average (int sum, unsigned int aSize) {
    return (double)sum / aSize;
}

double sDeviation (int a[], double mean, unsigned int aSize) {
    int i;
    double s = 0.0;
    for (i = 0; i < aSize; i++)
        s += pow(a[i] - mean, 2);
    return sqrt(s / aSize);
}