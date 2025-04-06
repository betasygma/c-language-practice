#include <stdio.h>
#include <string.h>

int main() {
    char S[128];
    int n;

    scanf("%s", S);
    scanf("%d", &n);

    for (int i = 0; i < strlen(S); i++) {
        if (S[i] >= 'A' && S[i] <= 'Z')
            S[i] =  'A' + (S[i] - 'A' + ((n % 26) + 26)) % 26;
        else if (S[i] >= 'a' && S[i] <= 'z')
            S[i] =  'a' + (S[i] - 'a' + ((n % 26) + 26)) % 26;
    }
    
    printf("%s\n", S);
    return 0;
}