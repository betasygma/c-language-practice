#include <stdio.h>
#include <math.h>

struct Point {
    int x, y, z;
};

struct Distance {
    long long d;
};

long long minDistance(struct Point p1, struct Point p2) {
    long long dx = p2.x - p1.x;
    long long dy = p2.y - p1.y;
    long long dz = p2.z - p1.z;
    return (long long)sqrt(dx*dx + dy*dy + dz*dz);
}

int main() {
    struct Point point[3];
    for (int i = 0; i < 3; i++) {
        scanf("%d%d%d", &point[i].x, &point[i].y, &point[i].z);
    }

    int rA, rB, RD;
    scanf("%d%d%d", &rA, &rB, &RD);

    struct Distance distance[2];
    distance[0].d = minDistance(point[0], point[2]);
    distance[1].d = minDistance(point[0], point[1]) + minDistance(point[1], point[2]);

    if (rA * RD >= distance[0].d) printf("NAH ID WIN, NO NEED TO STOP\n");
    else if ((rA + rB) * RD >= distance[1].d) printf("HHM BETTER TAKE ROCKET, STILL CAN WIN\n");
    else printf("GIVE UP ALREADY, MINING BETTER\n");

    return 0;
}