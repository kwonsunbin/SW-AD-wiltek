#include <stdio.h>

int W;
int howMany[6] ;
int howMuch[6]= {500,100,50,10,5,1};
int ans[6] ;

void inputData(){
    scanf("%d", &W);
    for (int i=0 ; i<6; i++){
        scanf("%d",&howMany[i]) ;
    }    
}

void outputData(){
    int sum = 0;
    for (int i=0 ; i<6; i++){
        sum += ans[i];
    }    

    printf("%d\n", sum);
    for (int i=0 ; i<6; i++){
        printf("%d ",ans[i]) ;
    }    
}

void solve(){
    for (int i =5; i>=0; i--){
        if (W ==0) break;

        if (i ==0){
            ans[0] = W/howMuch[0];
            break;
        }

        for (int j =  howMany[i]; j >=0 ; j--){

            if ( ( W - howMuch[i]* j ) % howMuch[i-1] == 0){
                ans[i] = j;
                W -= howMuch[i]* j ;
                break;
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
