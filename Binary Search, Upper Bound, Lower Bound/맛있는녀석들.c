#include <stdio.h>
#define MAXN ((int)1e6)

int N; long long M;
int F[MAXN+10];
int S[MAXN+10];


void inputData(){
    scanf("%d %lld", &N, &M);

    for (int i =0; i<N; i++){
        scanf("%d", &F[i]);
        scanf("%d", &S[i]);
    }
}

int isPossible(int n){
    long long accum =0;

    for (int i=0; i<N; i++){
        if (S[i] <= n){
            accum+=F[i];
        }else {
            accum=0;
        };

        if (M-accum <= 0){
            return 1;
        }
    }
    return 0;
}

int solve(){
    int maxS = -1;
    for(int i =0; i<N; i++){
        if (S[i] > maxS){
            maxS =S[i];
        }
    }

    int s = 0; int e = maxS;
    int ans = -1;

    while(s<=e){
        int m = (s+e)/2;
        if (isPossible(m)){
            ans = m;
            e = m-1;
        }else {
            s = m+1;
        }
    }

    return ans;
}


int main(){
    int ans;
    inputData();
    ans = solve();

    printf("%d", ans);
    return 0;
}