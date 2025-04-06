#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 1000
#define MAX_NAME_LEN 50

// struct penyimpan statistik pemain
struct Player {
    char name[MAX_NAME_LEN];
    int goals;
    int assists;
    char assist_to[MAX_NAME_LEN];
    int key_passes;
    int dribbles;
    double motm_score;
};

// fungsi pencari indeks pemain berdasar nama
int findPlayerIndex(struct Player players[], int n, char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(players[i].name, name) == 0)
            return i;
    }
    return -1;
}

int main() {
    // input jumlah pemain
    int n;
    scanf("%d", &n);

    struct Player players[MAX_PLAYERS];

    // input nama pemain
    for (int i = 0; i < n; i++) {
        scanf("%s", players[i].name);
        players[i].goals = 0;
        players[i].assists = 0;
        players[i].key_passes = 0;
        players[i].dribbles = 0;
        players[i].motm_score = 0.0;
        strcpy(players[i].assist_to, "-");
    }

    // input hubungan assists-goals
    for (int i = 0; i < n; i++) {
        char assist_player[MAX_NAME_LEN], goal_player[MAX_NAME_LEN];
        int assists;
        scanf("%s %s %d", assist_player, goal_player, &assists);

        int assist_index = findPlayerIndex(players, n, assist_player);
        int goal_index = findPlayerIndex(players, n, goal_player);
        
        if (assist_index != -1 && goal_index != -1) {
            players[assist_index].assists += assists;
            players[goal_index].goals += assists;
            strcpy(players[assist_index].assist_to, players[goal_index].name);
        }
    }
    
    // input statistik tambahan
    for (int i = 0; i < n; i++) {
        char name[MAX_NAME_LEN];
        int key_passes, dribbles;
        scanf("%s %d %d", name, &key_passes, &dribbles);

        int index = findPlayerIndex(players, n, name);
        if (index != -1) {
            players[index].key_passes = key_passes;
            players[index].dribbles = dribbles;
        }
    }
    
    // hitung skor MOTM setiap pemain
    for (int i = 0; i < n; i++) {
        players[i].motm_score = (3.0 * players[i].goals) +
                                (2.0 * players[i].assists) +
                                (1.0 * players[i].key_passes) +
                                (0.2 * players[i].dribbles);
    }                       
    
    // input pertanyaan
    int t;
    scanf("%d", &t);

    char command[t][10];
    for (int i = 0; i < t; i++) {
        scanf("%s", command[i]);
    }

    // output
    for (int i = 0; i < t; i++) {
        if (strcmp(command[i], "TABLE") == 0) {
            for (int j = 0; j < n; j++)
                printf("%s | Goals: %d | Assists: %d | Assist To: %s \n", 
                    players[j].name, players[j].goals, players[j].assists, players[j].assist_to);
        } else if (strcmp(command[i], "MOTM") == 0) {
            int motm_index = 0;
            for (int j = 1; j < n; j++) {
                if (players[j].motm_score > players[motm_index].motm_score)
                    motm_index = j;
            }
            printf("Man of the Match: %s\n", players[motm_index].name);
        }
    }
    return 0;
}