#include <stdio.h>
#include <string.h>

int main(){
    char s[1001], al[26];
    int n = 0, freq[26] = {0};
    
    for(int i=0; i<26; i++){
        al[i]=i+97;
    }
    
    printf("%s", al[0]);
    scanf("%s", &s);

    for(int i=0;i<1000;i++) {
        if(96 < s[i] && s[i] < 123){
            n++;
        } else {
            break;
        }
    }

    char b;
    for(int i=0; i<n; i++){
        b = s[i];
            freq[b - 'a']++;
        
    }
    char most;
    int count=0;
    for (int j = 25; j >= 0; j --){
        
        if(freq[j]>most){
            count=freq[j];
            most=j;
        }
    }

    for(int i=0; i<26; i++){
        if(freq[i]>0){
            printf("%s: %d\n", al[i], freq[i]);
        }
    }

    printf("Most frequent character: %s with count: %d", most, count);

    return 0;
}