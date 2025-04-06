#include <stdio.h>
#include <string.h>

int main() {
    int T, N, E;

    scanf("%d", &T);
    
    int Etb[T];
    int Eh[T] = {0};
    int Nt = 0;

    for(int i=0; i<T; i++){
        scanf("%d", &N);
        Nt += N;
        
        int S[N];
        for(int j=0; j<N; j++){
            scanf("%d", &S[i]);
        }
        
        scanf("%d", &E);
        
        int count = 0;
        int defeat[N];
        memset(defeat, 0, sizeof(defeat));
        for (int i=0; i<N;i++) {
            int emin=10000;
            int idxmin;
            for (int j=0; j<N; j++){
                if(S[j] < emin && defeat[j] == 0) {
                    emin = S[j];
                    idxmin = j;
                }
            }

            if(E >= S[idxmin]) {
                E -= S[idxmin];
                defeat[idxmin] = 1;
                count++;
            } else {
                break;
            }
        }
            
        
    }
    
    return 0;
}