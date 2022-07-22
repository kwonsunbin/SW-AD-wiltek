#include <stdio.h>
#define MAXN ((int)5e4)

int N; int T;
int arr[MAXN+10];
int arrT[10000+10];

void inputData(){
    scanf("%d", &N);

    for(int i =0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &T);
    for(int i =0; i<T; i++){
            scanf("%d", &arrT[i]);
    }
}

void outputData(){

    for(int i =0; i<N; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    for(int i =0; i<T; i++){
        printf("%d ", arrT[i]);
    }
    printf("\n");
}

int binarySearch(int s, int e, int a){

    if ( s > e ) return 0; // 왜 ??

    int mid = (e+s) /2;

    if ( arr[mid] == a){
        return mid+1;
    }else if (a<arr[mid]){
        e = mid-1;
        return binarySearch(s, e, a);
    }else {
        s = mid+1; 
        return binarySearch(s, e, a);
    }
    
}

void solve(){
    for (int i =0; i<T; i++){
        printf("%d\n",binarySearch(0, N-1, arrT[i]));
    }
}

int main(void)
{
    inputData();
    solve();
    //outputData();
    return 0;
}
