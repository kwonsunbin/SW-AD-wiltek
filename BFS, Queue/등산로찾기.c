#include <stdio.h>
#define MAXN ((int) 1e2)
#define INF ((int) 2e9)

typedef struct QUE{
    int r; int c;
}QUE;

int N;
int topR; int topC;
int map[MAXN+10][MAXN+2];
int visit[MAXN+10][MAXN+10];
QUE que[MAXN*MAXN*100]; 
int rp = 0; int wp=0;

void push(int r, int c, int t ){ 
    if (r >=N || c>=N || r<0 || c<0) return; // 범위 넘어가면 리턴
    if (t >= visit[r][c] ) return; // 이전 누적치보다 크거나 같으면 리턴함..
    visit[r][c] = t;
    que[wp].r= r;
    que[wp].c = c;
    wp++;
}
QUE pop(){return que[rp++];}
int empty() {return wp ==rp;}

void inputData(){
    scanf("%d", &N);
    scanf("%d %d", &topR, &topC);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &map[i][j]);
        }
    }

}

int BFS(){

    //초기화
    wp = rp =0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            visit[i][j] = INF;
        }
    }
    //초깃값 큐에 넣기
    for(int i=0; i<N; i++){
        if(i ==0 || i==N-1){
            for(int j=0; j<N; j++){
                push(i,j, map[i][j]*map[i][j]);
            }
        }else {
            push(i, 0, map[i][0]*map[i][0]);
            push(i, N-1, map[i][N-1]*map[i][N-1]);
        }
    }

    int dr[4] = {0,0,1,-1};
    int dc[4] = {1,-1,0,0};
    int nr = 0; int nc =0;

    //반복

    while(!empty()){
        QUE crnt = pop();
        
        for (int i =0; i<4; i++){
            nr = crnt.r + dr[i]; 
            nc = crnt.c  +dc[i];
            if ( map[nr][nc] == map[crnt.r][crnt.c]){
                push(nr,nc, visit[crnt.r][crnt.c]);
            }else if ( map[nr][nc] > map[crnt.r][crnt.c]){
                push(nr,nc, visit[crnt.r][crnt.c]+ (map[nr][nc]-map[crnt.r][crnt.c])*(map[nr][nc]-map[crnt.r][crnt.c]) );
            }else {
                push(nr,nc, visit[crnt.r][crnt.c] + (map[crnt.r][crnt.c] -map[nr][nc]) );
            }
            
        }

    }

    return visit[topR-1][topC-1];


    
}
int main(){
    inputData();
    int ans;
    ans = BFS();

    printf("%d", ans);
    
}