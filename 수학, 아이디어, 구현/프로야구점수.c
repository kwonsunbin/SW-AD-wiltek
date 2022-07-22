#include <stdio.h>
 
int score ;
int r;
int runner[3] ;
int outCnt;


void inputData(){

    scanf("%d",&score);
    scanf("%d",&r);
    scanf("%d",&outCnt);

    if (r!=0){
        runner[r-1] = 1;
    }



}

void hit(int n ){

    for (int i =2; i>= 0; i--){
        if (runner[i] == 1){
            if ( i + n >= 3){
                runner[i]=0;
                score++;
            }else {
                runner[i+n] = 1;
                runner[i]=0;
            }
        }
    }
    if (n==4){
        score++;
    }else {
        runner[n-1]=  1;
    }
    
}

void solve(){
    int crntHitter ;
    //printf("점수 %d, 아웃 %d, 1루 %d, 2루, %d 3루, %d\n",score, outCnt, runner[0], runner[1], runner[2]);
    for(int i =0; i<10; i++){
        scanf("%d", &crntHitter);
        if (crntHitter==0){
            outCnt++;
            if (outCnt==3){
                break;
            }
        }else if(crntHitter==1){
            hit(1);
        }else if(crntHitter==2){
            hit(2);
        }else if(crntHitter==3){
            hit(3);
        }else {
            hit(4);
        }

        //printf("점수 %d, 아웃 %d, 1루 %d, 2루, %d 3루, %d\n",score, outCnt, runner[0], runner[1], runner[2]);
         
        
    }
}

void outputData(){ 
    printf("%d", score);
}

int main(void)
{
    inputData();
    solve();
    outputData();
 
    return 0;
}