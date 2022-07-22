#include <stdio.h>
typedef struct horse{
    int r; int c; int t;
}horse;

horse que[10000];
int map[100+10][100+10];
int rp; int wp;

horse pop(){return que[rp++];}
void push(int r, int c, int t) {
    if (map[r][c]==1){return;}
    map[r][c] = 1;
    que[wp].r = r; que[wp].c = c; que[wp].t = t; wp++;
}
int empty(){return rp == wp;}

int N; int M; int R; int C; int S; int K;


void inputData(){
    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%d", &R);
    scanf("%d", &C);
    scanf("%d", &S);
    scanf("%d", &K);
}



int bfs(){
    int dr[8] = {1,2,2,1, -1,-2,-2,-1};
    int dc[8] = {2,1,-1,-2, -2,-1,1,2};
    wp=rp=0;
    push(R-1,C-1,0);
    int nr = 0; int nc = 0; int nt =0;

    while(!empty()){
        horse crnt = pop();
        //printf("r=%d, c=%d,t=%d", crnt.r,crnt.c,crnt.t);
        if (crnt.r == S-1 && crnt.c == K-1){
            return crnt.t;
        }
        for (int i=0; i<8; i++){
            nr = crnt.r+ dr[i];
            nc = crnt.c+ dc[i];
            nt = crnt.t+1;

            if(nr <0 || nc <0||nr>N-1 || nc>M-1){continue;}
            push(nr,nc,nt);
        }
    }
    return -1;
}

int main(){
    int ans ;
    inputData();
    //outputData();
    ans =bfs();
    printf("%d", ans);
    return 0;
}