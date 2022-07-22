#include <stdio.h>

int C, R, K;
int map[1000][1000];
void inputData(){
    scanf("%d", &C);
    scanf("%d", &R);
    scanf("%d", &K);   
}


void solve(){
    int x = 0;
    int y = 0;
    int nx = 0;
    int ny = 0;
    int cnt = 1;
    int dir = 0;

    int dx[4] = {0,1,0,-1};
    int dy[4]= {1,0,-1,0};

    for (;;){
        
        x = nx;
        y = ny;
        map[x][y] = cnt;
        //printf("x=%d, y=%d, cnt=%d\n", x,y,cnt);
        if (cnt >= R*C+1 ){
            printf("0");
            break;
        }
        if (cnt == K){ printf("%d %d", x+1,y+1); break;} // 지도 기준 시계방향 90도 회전 한 것..

        cnt++;

        nx = x + dx[dir];
        ny = y + dy[dir];

        if (nx >= C || ny >= R || nx < 0 || ny <0 || map[nx][ny] != 0 ){
            nx = x - dx[dir];
            ny = y - dy[dir];
            dir = (dir+1)%4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }


        
    }
}

int main(void)
{
      // 여기서부터 작성
        inputData();
        solve();
      return 0;
}