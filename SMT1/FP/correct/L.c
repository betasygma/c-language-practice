#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

int main() {
    long double v;
    scanf("%Lf", &v);
    
    long double r = cbrtl(v / (2 * PI));
    long double a = v * 3 / r;
    printf("Luas permukaan: %.2Lf\n", a);

    return 0;
}