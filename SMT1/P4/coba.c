#include <stdio.h>
#include <math.h>
int main() {
    int i = 2, j = 3, k = 1, l = 4;
    double jarak = (double) pow(((j - i)*(j - i) + (l - k)*(l - k)), 2);
    printf("%d", jarak);
}