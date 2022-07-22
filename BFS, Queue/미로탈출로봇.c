#include <stdio.h>

typedef struct coord{
    int x; int y; int s;
}coord;

int X; int Y;
int sx; int sy;
int ex; int ey;
char map[100+10][100+10];
int visited[100+10][100+10];
coord queue[10000];
int rp; int wp;

void push(coord a ){queue[wp++]= a;}
coord pop(){return queue[rp++];}
int empty(){return rp == wp;}


void inputData(){
    scanf("%d %d", &X, &Y);
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);

    for (int i =0; i<Y; i++){
        scanf("%s", map[i]);
    }
}

int solve(){
    coord s ;
    s.x = sx-1;
    s.y = sy-1;// 0,0과 0 초부터 부터 시작 하도록 초기값 설정
    s.s = 0;

    int ans=0;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int nx = 0;
    int ny = 0;
    int ns = 0;
    wp = rp = 0;
    memset(visited, 0, sizeof(visited));


    push(s);

    while (!empty()){
        coord crnt;
        crnt = pop();
        //printf("x=%d y=%d ans=%d\n", crnt.x,crnt.y,ans);
        if(crnt.x == ex-1 && crnt.y == ey-1){
            return crnt.s;
        }
        
        for (int i =0; i<4; i++){
            nx = crnt.x+dx[i];
            ny = crnt.y +dy[i];
            ns = crnt.s+1;

            //printf("nx=%d, ny=%d\n", nx,ny);
            

            if (nx < 0 || ny <0 || nx  > X-1 || ny > Y-1 || map[ny][nx] == '1'){
                continue;
            }
            if (visited[ny][nx] == 1){
                continue;
            }
            //printf("i=%d\n",i);

            coord next;
            next.x = nx;
            next.y = ny;
            next.s = ns;
            visited[next.y][next.x]=1;
            push(next);

            // push 할 때, 방문 처리 해야한다! 그러지 않으면, 다음 번 돌 때 문제 발생..
        }
    }
    


}

int main(){
    int ans;
    inputData();
    ans = solve();

    printf("%d", ans);

    return 0;
}