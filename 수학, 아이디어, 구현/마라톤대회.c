#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN ((int)1e5)
int N;
int X[MAXN + 10];
int Y[MAXN + 10];
int minDistance = (int)2e9 ;

void inputData(void){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d %d", &X[i], &Y[i]);
    }
}


void solve(void){
    int distanceWihtoutPassing = 0;
    int distanceWithPassing = 0;
    for (int i = 0; i < N-1; i++){
        distanceWihtoutPassing += abs(X[i]-X[i+1]);
        distanceWihtoutPassing += abs(Y[i]-Y[i+1]);
    }

    for (int j = 0; j <N-2; j ++){ // (j + 2) 번째 체크포인트를 스킵 j =0일 때 -> 2번째 체크포인트 스킵
        distanceWithPassing = distanceWihtoutPassing - (abs(X[j]-X[j+1]) + abs(Y[j]-Y[j+1])) - (abs(X[j+1]-X[j+2]) + abs(Y[j+1]-Y[j+2])) + (abs(X[j]-X[j+2]) + abs(Y[j]-Y[j+2]));
        if (distanceWithPassing < minDistance) minDistance = distanceWithPassing ;
    }

}

int main(void){
    int ans = -1;

    inputData();
    solve();
    
    printf("%d\n", minDistance);
    return 0;
}