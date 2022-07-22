#include <stdio.h>
 
int R;
int ans;

void inputData(void){
    scanf("%d" ,&R);
    
}

int getDistSquare(int a, int b){
    return (R-a)*(R-a) + (R-b)*(R-b) ;
}

void howManySquares(void){

    for (int i=0; i<R; i++){
        for (int j=0; j<R; j++){
            if (getDistSquare(i,j) < R*R ){
                ans+=1;
            }
        }
    }
    
    ans *=4; // 4 조각 어차피 동일
}


void outputData(void){
    printf("%d", ans);
}


int main(void)
{
      // 여기서부터 작성
    inputData();
    howManySquares();
    outputData();

 
    return 0;
}