#include <stdio.h>

int N;
int map[500+10][500+10];

void inputData(){
    scanf("%d", &N);
}

void outputData(){
    for(int i=0 ; i<N; i++){
        for(int j =0; j<N; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void solve(){
    int num = 1;
    int x = N/2, y = N/2;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int direction = 0;

    int leftBorder = N/2-2;
    int rightBorder = N/2+2;
    int topBorder= N/2-2;
    int bottomBorder = N/2+2;

    for (;;){
        if (num == N*N+1) break;

        map[x][y] = num;
        num++;
        
        x += dx[direction];
        y += dy[direction];

        if (x == bottomBorder | y== rightBorder | x== topBorder | y== leftBorder ){
            x -= dx[direction];
            y -= dy[direction];

            if (direction==0){
                topBorder-=1;
                direction=1;
                x += dx[direction];
                y += dy[direction];
            }else if(direction == 1){
                rightBorder+=1;
                direction=2;
                x += dx[direction];
                y += dy[direction];
            }else if(direction == 2){
                bottomBorder+=1;
                direction=3;
                x += dx[direction];
                y += dy[direction];
            }
            else {
                leftBorder-=1;
                direction=0;
                x += dx[direction];
                y += dy[direction];
            }
        }
        
    }    
}

int main(void)
{
      // 여기서부터 작성
      inputData();
      solve();
      outputData();
 
      return 0;
}