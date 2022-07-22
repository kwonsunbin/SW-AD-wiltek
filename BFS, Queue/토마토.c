#include <stdio.h>
typedef struct QUE{
    int r; int c; int t;
}QUE;

int N; int M;
int map[1000+10][1000+10];

QUE que[1000000];
int rp; int wp;

QUE pop(){return que[rp++];}
void push(int r, int c, int t) {
    if (map[r][c]==2){return;} // 2는 물들어 같이 썩어버린 토마토
    if (map[r][c]==-1){return;} // -1 은 비어있는 칸
    if ( r < 0 || c <0 || r>N-1 || c>M-1){return;} // r =3, c =4 / r=2, c=5
    map[r][c] = 2;
    que[wp].r = r; que[wp].c = c; que[wp].t = t; wp++;
    
}
int empty(){return rp == wp;}




void inputData(){
    scanf("%d",&M);
    scanf("%d",&N);
    for (int i =0;i<N;i++){
        for (int j =0;j<M;j++){
            scanf("%d", &map[i][j]);
        }
    }
}

void initQue(){
    for (int i =0;i<N;i++){
        for (int j =0;j<M;j++){
            if(map[i][j] == 1){
                push(i,j,0);
            }
        }
    }
}

int bfs(){
    initQue();
    int dr[4] = {0,0,1,-1};
    int dc[4] = {1,-1,0,0};
    int ans;
    while(!empty()){
        QUE crnt = pop();
        ans = crnt.t;
        
        for(int i =0; i<4; i++){
            push(crnt.r+dr[i], crnt.c+dc[i], crnt.t+1);
        }
    }
    return ans;
}

int check(){
    for (int i =0;i<N;i++){
        for (int j =0;j<M;j++){
            if(map[i][j] == 0){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    int ans;
    inputData();
    ans = bfs();
    if (check() == 0){
        ans = -1;
    }
    printf("%d", ans);
    return 0;
}