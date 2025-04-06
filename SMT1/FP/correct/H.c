#include <stdio.h>
#include <string.h>

int keluarPapan (char x, char y) {
    return (x < 'a' || x > 'h' || y < '1' || y > '8');
}

void chessChecker (char wk[], char wq[], char bk[], char bq[], char x) { 
    char k[3], q[3], k2[3], q2[3];
    strcpy(k, (x == 'w') ? bk : wk);
    strcpy(q, (x == 'w') ? wq : bq);
    strcpy(k2, (x == 'w') ? wk : bk);
    strcpy(q2, (x == 'w') ? bq : wq);

    int skak = 0;
    int xarah [] = {1, 1, -1, -1};
    int yarah [] = {1, -1, 1, -1};

    if (q[0] == k[0]) {
        char ycari = q[1] + ((q[1] < k[1]) ? 1 : - 1);
        while (ycari != k[1]) {
            if ((q[0] == k2[0] && ycari == k2[1]) || (q[0] == q2[0] && ycari == q2[1])) break;
            ycari += ((q[1] < k[1]) ? 1 : - 1);
        }
        if (ycari == k[1]) skak = 1;
    }
    else if (q[1] == k[1]) {
        char xcari = q[0] + ((q[0] < k[0]) ? 1 : - 1);
        while (xcari != k[0]) {
            if ((q[1] == k2[1] && xcari == k2[0]) || (q[1] == q2[1] && xcari == q2[0])) break;
            xcari += ((q[0] < k[0]) ? 1 : - 1);
        }
        if (xcari == k[0]) skak = 1;
    }
    else {
        for (int i = 0; i < 4; i++) {
            char xcari = q[0];
            char ycari = q[1];

            while(!keluarPapan(xcari, ycari)) {
                xcari += xarah[i];
                ycari += yarah[i];

                if ((xcari == k2[0] && ycari == k2[1]) || (xcari == q2[0] && ycari == q2[1])) break;
                if (xcari == k[0] && ycari == k[1]) {
                    skak = 1;
                    break;
                }
            }
            if (skak == 1) break;
        }
    }

    if (skak) printf("%s checked %s!\n", (x == 'w') ? "White" : "Black", (x == 'w') ? "Black" : "White");
    else printf("Game is still going!\n");
}

int main() { 
    char wk[3], wq[3], bk[3], bq[3], x; 
    
    scanf("%s %s ", wk, wq); 
    scanf("%s %s ", bk, bq); 
    scanf("%c", &x); 
    
    chessChecker(wk, wq, bk, bq, x); 
    
    return 0; 
}