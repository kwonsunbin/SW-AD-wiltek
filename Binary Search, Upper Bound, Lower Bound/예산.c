#include <stdio.h>
#define MAXN ((int)1e4)
int N; int M;
int arr[MAXN+10];

void inputData(){
    scanf("%d",&N);
    
    for (int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d",&M);

}

int findMax(){
    int max = -1;
    for (int i=0; i<N; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}


int solve(){
    int sum = 0;
    int max = findMax();
    for (int i=0; i<N; i++){
        sum += arr[i];
    }

    int tempArr[MAXN+10];

    for (int i=0; i<N; i++){
        tempArr[i] = arr[i];
    }
    
    if (sum > M){
        int testSum;
        int s =0; int e = max-1;
        int sol = -1;

        while(s<=e){ // 상한 찾기 잖아 이건!..
            int m = (s+e)/2;
            testSum = 0;
            
            for (int i=0; i<N; i++){
                if (arr[i] > m){
                    testSum+= m;
                }else {
                    testSum+=arr[i];
                }
            }

            if (testSum > M){ // m 일때의 결과 값이 M보다 크다면 ?
                e = m -1;
            }else { // testSum <= M, 이걸 만족하는 m 중에서 가장 큰 값 찾기! 상한 찾기!
                sol = m;
                s = m+1;
            }
        }
        return sol;
        // for ( int maxBudget = max-1; maxBudget>=0; maxBudget--){
        //     testSum = 0;

        //     for (int i=0; i<N; i++){
        //         if (arr[i] > maxBudget){
        //             testSum+= maxBudget;
        //         }else {
        //             testSum+=arr[i];
        //         }
        //     }
        //     if (testSum <= M){
        //         return maxBudget;
        //     }
        // } 

    }else {
        return max;
    }
}
int main(void)
{
    int ans;
    inputData();
    ans = solve();
    printf("%d", ans);
 
    return 0;
}