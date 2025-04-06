#include <stdio.h>
#define MAX 7

int n, m;
int matriks[MAX][MAX];
int udahLewat[MAX][MAX] = {0};
int banyakJalan = 0;

int xa[] = {0, 0, 1, -1};
int ya[] = {-1, 1, 0, 0};

int gaNyasar(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && matriks[x][y] % 2 == 1 && !udahLewat[x][y]);
}

void cariJalan(int x, int y) {
    if (matriks[x][y] == 1) {
        banyakJalan++;
        return;
    }
    udahLewat[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int xc = x + xa[i];
        int yc = y + ya[i];
        if (gaNyasar(xc, yc)) cariJalan(xc, yc);
    }
    udahLewat[x][y] = 0;
}

int main() {
    scanf("%d%d", &n, &m);
    int xmulai, ymulai;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matriks[i][j]);
            if (matriks[i][j] == 0) {
                xmulai = i;
                ymulai = j;
            }
        }
    }
    cariJalan(xmulai, ymulai);

    if (banyakJalan > 0) printf("Terdapat %d jalan untuk kucing oren pulang\n", banyakJalan);
    else printf("Kucing oren tidak bisa pulang ke rumah :(\n");

    
}