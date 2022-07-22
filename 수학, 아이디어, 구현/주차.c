#include <stdio.h>
 
int A, B, C;
int startTime[3];
int endTime[3];
int ans;

void inputData(){
    scanf("%d %d %d",&A, &B, &C);
    for (int i=0; i<3; i++){
        scanf("%d", &startTime[i]);
        scanf("%d", &endTime[i]);
    }
}

void solve(){
    int cnt = 0 ;

    for (int i=1; i<=100; i++){

        for(int j=0; j<3; j++){
            if (startTime[j] ==i ){
                cnt++;
            }
            if (endTime[j] == i){
                cnt--;
            }
        }

        if (cnt == 0 ){ continue;}
        else if (cnt == 1){ ans += A;}
        else if (cnt == 2){ans += 2*B;}
        else {ans += 3*C;}
    }
}

void outputData(){
    printf("%d", ans);
}
int main(void)
{
      // 여기서부터 작성
    inputData();
    solve();
    outputData();

    return 0;
}
