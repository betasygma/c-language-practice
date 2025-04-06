#include <stdio.h>

long long kpk(int x, int y) {
    int v = x, w = y; 
    while(y != 0) {
        int z = y;
        y = x % y;
        x = z;
    }
    return (long long)v * w / x;
} // long long biar input 99999 99998 aman

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%lld\n", kpk(x, y));
}