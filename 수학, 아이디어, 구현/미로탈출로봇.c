#include <stdio.h>
 
int N;
int map[10][10];
int visited[10][10];
int dir[4];
int ans;

void inputData(){
    char temp[10];
    scanf("%d", &N);

    for(int i=0; i<N;i++){
        scanf("%s", temp);
        for(int j=0; j<N; j++){
            map[i][j] = temp[j]-48;
        }
    }
    for (int i=0; i<4; i++){
        scanf("%d",&dir[i]);
    }
}

void outputData(){
    
    printf("%d", ans);
}


int solve(){
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    int nx = 0;
    int ny = 0;
    int x = 0; 
    int y = 0 ;
    int d = 0;
    int movedDist = -1;

    
    
    for(;;){
        x = nx;
        y = ny;

        if (visited[x][y]==1){
            //printf("what's wrong with %d, %d\n", nx, ny);
            //for (int i =0; i<5; i++){
            //     for (int j=0; j<5; j++){
            //         printf("%d", visited[i][j]);
            //     }
            //     printf("\n");
            // }
            break;
        }
        

        movedDist ++;
        visited[x][y]= 1;
        //printf("moved = %d, x=%d, y= %d\n",movedDist, x , y);
        nx = x +dx[dir[d]-1];
        ny = y +dy[dir[d]-1];

        for(int i=0; i<5; i++){
            if (i ==4) {
                nx = x;
                ny = y;        
                break;
            }
            if (map[nx][ny]== 1 || nx < 0 || ny <0 || nx > N-1 || ny > N-1 ){
                
                if (d == 3){
                    d = 0;
                }else {
                    d +=1;
                }
                // d = (d+1)%4;
                nx = x +dx[dir[d]-1];
                ny = y +dy[dir[d]-1];
                //printf("change direciton %d %d\n", nx,ny);
            }else {
                break;
            }
        }
    }
    return movedDist;

}

int main(void)
{
      // 여기서부터 작성
      inputData();
      ans = solve();
      outputData();

      return 0;
}
