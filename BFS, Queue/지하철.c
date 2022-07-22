#include <stdio.h>
#include <string.h>
#define INF ((int)2e9)
#define MAXN ((int)1e2)

int que[100*100];
int rp; int wp;
int N; int M;
int visited[MAXN+10] = {INF,};
int path[MAXN+10] = {0,};
int matrix[MAXN+10][MAXN+10];

int pop(){return que[rp++];}
void push(int n, int t, int pre) {
    visited[n] = t; // 누적 시간
    path[n] = pre; // 이전 역
    que[wp++] = n; // 현재 역
}
int empty(){return rp == wp;}

void inputData(){
    scanf("%d", &N);
    scanf("%d", &M);

    for (int i =1; i<=N; i++){
        for (int j =1; j<=N; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

int bfs(){
    // 초기화
    wp = rp =0;
    for (int i=1; i<=N; i++){
        visited[i] = INF;
        path[i] = 0;
    }
    // 시작 위치 큐 저장
    push(1,0,0);

    // 반복
    while(!empty()){
        int crnt = pop();
        for (int i =1; i <= N; i++){
            if (visited[crnt] + matrix[crnt][i]< visited[i] ){ // 같아도 안좋은 거다!
                push(i, visited[crnt]+matrix[crnt][i],crnt);
            }
        }
    }

    return visited[M];

}

void PRT(int m){
    if (m ==0) return;
    PRT(path[m]);
    printf("%d ", m);
}

int main(){
    int ans;
    inputData();
    ans = bfs();

    printf("%d\n", ans);
    PRT(M);


    return 0;
}