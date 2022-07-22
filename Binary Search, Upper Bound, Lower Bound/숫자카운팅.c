#include <stdio.h>
#define MAXN ((int)2e6)

int N; int M;
int arr[MAXN+10];
int arrM[MAXN+10];

void inputData(){
    scanf("%d", &N);

    for(int i =0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &M);
    for(int i =0; i<M; i++){
            scanf("%d", &arrM[i]);
    }
}

void outputData(){

    for(int i =0; i<N; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    for(int i =0; i<M; i++){
        printf("%d ", arrM[i]);
    }
    printf("\n");
}

int binarySearch(int s, int e, int a){

    if ( s > e ) return -1; // 왜 ??
    int mid = (e+s) /2;

    if ( arr[mid] == a){
        return mid;
    }else if (a<arr[mid]){
        e = mid-1;
        return binarySearch(s, e, a);
    }else {
        s = mid+1; 
        return binarySearch(s, e, a);
    }
    
}

void solve(){
    int targetIdx ;
    int targetIdxUp;
    int targetIdxDown;
    int target ;
    int cnt ;
    for (int i =0; i<M; i++){
        cnt = 1;
        target = arrM[i];
        
        targetIdx = binarySearch(0, N-1, target);
        if (targetIdx== -1 ){ cnt = 0; }
        targetIdxUp = targetIdx+1;
        targetIdxDown = targetIdx-1;

        for (;;){
            if(arr[targetIdxUp++] != target){
                break;
            }else {
                cnt ++;
            }
        }

        for (;;){
            if(arr[targetIdxDown--] != target){
                break;
            }else {
                cnt ++;
            }
        }
        printf("%d ", cnt);
    }
}

int main(void)
{
    inputData();
    solve();
    //outputData();
    return 0;
}
