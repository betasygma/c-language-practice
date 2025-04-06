#include <stdio.h>

int fpb(int x, int y) {
    while(y != 0) {
        int z = y;
        y = x % y;
        x = z;
    }
    return x;
}

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d", fpb(x, y));
}