#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)5e3)
int N;
int arr[MAXN*2];

void inputData(){
    scanf("%d", &N);

    for(int i =0; i<N; i++){
        scanf("%d", &arr[i]); 
    }
}

void outputData(){
    for(int i =0; i<N; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int compare(const void *a, const void *b){
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    return num1-num2;
}

int solve(){

    qsort(arr, N, sizeof(int), compare);
    int cost ;
    int sumCost = 0;
    int s = 0; int e = N-1;

    for (;;){
        if (s+1 == e){
            sumCost+= arr[s]+arr[s+1];
            break;
        }
        int cost = arr[s]+arr[s+1];
        int flag = 0;

        for (int i =s+2; i <e+1; i++){ // 정렬 된 것에 삽입하기 마지막 e까지..
            if (arr[i] >= cost){
                for (int j=e+1; j>i; j-- ){ // e+1 부터 i+1까지..
                    arr[j] = arr[j-1];
                }
                arr[i] = cost;
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            arr[e+1] = cost;
        }

        sumCost+= cost;
        e++;
        s+=2;
        
    }
    

    return sumCost;
}

int main(void)
{
    inputData();

    int ans;
    ans = solve();
    
    printf("%d", ans);
    return 0;
}