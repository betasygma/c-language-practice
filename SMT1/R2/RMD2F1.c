#include <stdio.h>
#include <string.h>

int main() {
    int a;
    char S[1000];
    
    printf("geser: ");
    scanf("%d\n", &a);
    printf("kalimat: ");
    gets(S);

    for(int i = 0; i<strlen(S); i++){
        if(S[i] != ' '){
            S[i] = 'a' + (S[i] - 'a' + a + 26) % 26;
        }
    }

    printf("%s\n", S);
    return 0;
}