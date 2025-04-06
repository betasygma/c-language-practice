#include <stdio.h>
#include <math.h>

struct Bunga {
    int x, y;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Bunga bunga[n];
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &bunga[i].x, &bunga[i].y);
    }

    float jarakmin = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dx = bunga[j].x - bunga[i].x;
            int dy = bunga[j].y - bunga[i].y;
            float jarak = sqrt(dx * dx + dy * dy);
            if (jarak < jarakmin) {
                jarakmin = jarak;
            }
        }
    }

    printf("%.2f\n", jarakmin);
    return 0;
}