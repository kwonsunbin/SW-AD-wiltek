#include <stdio.h>
#define MAXN ((int)1e2)
#define INF ((int)2e9)

typedef struct QUE{
    int x; int y;
}QUE;

int N ;
int map[MAXN+10][MAXN+10];
int visit[MAXN+10][MAXN+10];
QUE que[MAXN * MAXN *100];
int rp = 0; int wp=0;

void push(int x, int y, int t ){ 
    
    if (x >=N || y>=N || x<0 || y<0) return; // 범위 넘어가면 리턴
    if (t >= visit[x][y] ) return; // 이전 누적치보다 크거나 같으면 리턴함..
    visit[x][y] = t;
    que[wp].x= x;
    que[wp].y = y;
    wp++;
}

QUE pop(){return que[rp++];}
int empty() {return wp ==rp;}

void inputData(){
    scanf("%d", &N);
    char temp[MAXN+10];
    for(int i=0; i<N; i++){
        scanf("%s", &temp);
        for(int j =0; j<N; j++){
            map[i][j] = temp[j]-48;
        }
    }
}

void outputData(){
    for(int i=0; i<N; i++){
        for(int j =0; j<N; j++){
            printf("%d ", visit[i][j]);
        }
        printf("\n");
    }
}

int bfs(){
    // 초기화
    wp = rp = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            visit[i][j] = INF;
        }
    }
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int nx =0; int ny =0;
    // 시작값
    push(0,0, map[0][0]);

    while(!empty()){
        //outputData();
        QUE crnt = pop();
        for (int i =0; i<4; i++){
            nx = crnt.x + dx[i];
            ny = crnt.y + dy[i];
            push(nx,ny, visit[crnt.x][crnt.y] + map[nx][ny]);
        }
    }

    return visit[N-1][N-1];

}

int main(){
    inputData();
    //outputData();

    int ans= 0;
    ans = bfs();

    printf("%d", ans);

    return 0;
}