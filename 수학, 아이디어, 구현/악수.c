#include <stdio.h>

int R, C;
char map[50][50];
int simulRes [50*50];
int simulResPtr;

void inputData(void){
    scanf("%d", &R);
    scanf("%d", &C);
    for (int i =0; i < R; i++){
        scanf("%s", map[i]);
    }
}

void outputData(void){
    int max = -1 ;
    for (int i =0; i < simulResPtr; i++){
        if ( max < simulRes[i]){
            max = simulRes[i];
        }
    }

    printf("%d", max);
}

int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0} ;
int dc[8] = {-1,0, 1, 1, 1, 0 ,-1, -1 };
int simulation(void){
    int res = 0, nr, nc;
    for(int r =0; r<R; r++){
        for (int c =0; c <C ; c ++){
            if (map[r][c] == 'o'){
                for (int k=0; k<8; k++){
                    nr = r+dr[k];
                    nc = c+dc[k];
                    if ( nr <0 | nc<0 | nr>R-1 | nc>C-1) continue;
                    if(map[nr][nc]=='o'){
                        res +=1;
                    }else {
                        continue;
                    }
                }
            }else {
                continue;
            }
            
        }
    }
    return res/2;
}

void simulate(void){
    int simulateCnt =0;
    for (int i =0; i<R; i++){
        for (int j =0; j<C; j++){
            if(map[i][j] == '.'){
                map[i][j] = 'o';
                simulRes[simulResPtr++] = simulation();
                simulateCnt++;
                map[i][j] = '.';
            }else {
                continue;
            }
        }
    }

    if (simulateCnt == 0){
        simulRes[simulResPtr++] = simulation();
    }
}

int main(void){
    inputData();
    simulate();
    outputData();
    return 0;
}