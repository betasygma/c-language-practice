#include <stdio.h>
#include <string.h>

int main() {
    int n;

    // printf("input jumlah perintah\n");
    scanf("%d", &n);

    char cmd[n][10], strA[n][100000], strB[n][100000];

    // printf("input: \"cmd strA strB\"\t\tcmd : [ANAGRAM, FLIP]\n");
    for(int i = 0; i < n; i++) {

        scanf("%s", cmd[i]);                            // ngebaca cmd, strA, strB
        scanf("%s", strA[i]);
        scanf("%s", strB[i]);

        // if(lenA != lenB) {                           // ngecek kesamaan jumlah karakter strA & strB
        //     strcpy(output[z], "This cannot lah bro");
        //     z++;
        //     continue;
        // }

        // if (lenA == lenB) {
            if(strcmp(cmd[i], "FLIP") == 0) {           // cmd == FLIP
                
                int isFlip = 1;                         // ngecek FLIP
                for(int j = 0; j < strlen(strA[i]); j++) {
                    if(strA[i][j] != strB[i][strlen(strA[i]) - j - 1]) {
                        isFlip = 0;
                        break;
                    }
                }
                if(isFlip) {                            // kalo benet FLIP
                    printf("Flip %s to get %s", strA[i], strB[i]);
                } else {                                // kalo bukan FLIP
                    printf("This cannot lah bro");
                }
            } 
            else if(strcmp(cmd[i], "ANAGRAM") == 0) {   // cmd == ANAGRAM
                
                int freqA[26] = {0}, freqB[26] = {0};   // bikin array buat ngitung frekuensi karakter tiap strA & strB
                for(int j = 0; j < strlen(strA[i]); j++) {         // ngitung frekuensi karakter tiap strA & strB
                    freqA[strA[i][j] - 'a']++;
                    freqB[strB[i][j] - 'a']++;
                }
                
                int isAnagram = 1;                      // ngecek ANAGRAM
                for(int j = 0; j < 26; j++) {
                    if(freqA[j] != freqB[j]) {
                        isAnagram = 0;
                        break;
                    }
                }
                if(isAnagram) {                         // kalo bener ANAGRAM
                    printf("Hhm %s can be arranged into %s", strA[i], strB[i]);
                }
                else {                                  // kalo bukan ANAGRAM
                    printf("This cannot lah bro");
                }

            }
        // }
    
        printf("\n");
    }
    
    return 0;
}