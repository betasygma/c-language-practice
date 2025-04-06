#include <stdio.h>
#include <string.h>

struct Data {
    char username[100];
    char ip_address[15];
    char uuid[100]; 
};

int main() {
    int i;
    scanf("%d", &i);

    struct Data data[i];

    for (int n = 0; n < i; n++) {
        scanf("%s %s %s", data[n].username, data[n].ip_address, data[n].uuid);
    }
    
    int j;
    scanf("%d", &j);

    char username[j][100];
    for (int n = 0; n < j; n++) {
        scanf("%s", username[n]);
    }
    
    for (int n = 0; n < j; n++) {
        for (int m = 0; m < i; m++) {
            if (strcmp(username[n], data[m].username) == 0) {
            printf("asyik %s-%s diperbolehkan bermain\n", data[m].uuid, data[m].username);
            break;
            }
            else if (m + 1 == i) {
                printf("hmm, kayaknya ada yang salah dengan datamu\n");
            }
        }  
    }
    return 0;
}