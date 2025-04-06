#include <stdio.h>

int main() {
    long long x1, y1, x2, y2;
    scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);

    double m, y;
    if (x1 == x2) printf("-_-\n");
    else {
        m = (double)(y2 - y1) / (x2 - x1);
        y = -1 * m * x1 + y1;
        printf("%.2lf %.2lf\n", m, y);
    }
    return 0;
}