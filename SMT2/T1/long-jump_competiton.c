#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_ATLET 100

typedef struct {
    char name[MAX_NAME];
    float best_jump;
} Athlete;

// fungsi bandingin atlet berdasar lompatan terbaik
int compare(const void *a, const void *b) {
    Athlete *athleteA = (Athlete *)a;
    Athlete *athleteB = (Athlete *)b;
    
    if (athleteB->best_jump > athleteA->best_jump) return 1;
    if (athleteB->best_jump < athleteA->best_jump) return -1;
    return 0;
}

int main() {
    FILE *file = fopen("data.txt", "r");
    if (!file) {
        printf("Failed to open file!\n");
        return 1;
    }

    Athlete athletes[MAX_ATLET];
    int count = 0;

    while (count < MAX_ATLET && fscanf(file, "%s", athletes[count].name) == 1) {
        float jump1, jump2, jump3;
        if (fscanf(file, "%f %f %f", &jump1, &jump2, &jump3) != 3) {
            printf("Data format is incorrect!\n");
            fclose(file);
            return 1;
        }

        // lompatan terbaik dari 3 percobaan
        athletes[count].best_jump = (jump1 > jump2) ? ((jump1 > jump3) ? jump1 : jump3) : ((jump2 > jump3) ? jump2 : jump3);
        count++;
    }
    
    fclose(file);

    // urutkan atlet berdasar lompatan terbaik
    qsort(athletes, count, sizeof(Athlete), compare);

    // tampilkan hasil
    printf("\nAthletes Ranked Based on Best Jumps\n");
    printf("--------------------------------------------\n");
    int rank = 1;
    for (int i = 0; i < count; i++) {
        // kalo bukan atlet pertama dan punya lompatan yang sama dengan atlet sebelumnya, peringkat tetap
        if (i > 0 && athletes[i].best_jump == athletes[i - 1].best_jump) {
            printf("%d. %s - %.2f meter\n", rank, athletes[i].name, athletes[i].best_jump);
        } else {
            // kalo beda, peringkat naik sesuai posisi saat ini
            rank = i + 1;
            printf("%d. %s - %.2f meter\n", rank, athletes[i].name, athletes[i].best_jump);
        }
    }
    return 0;
}
