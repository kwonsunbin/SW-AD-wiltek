// #include <stdio.h>
// #define MAXN ((int)1e3)
// int N;
// int arr[MAXN+10];

// void inputData(){
//     scanf("%d", &N);

//     for (int i =0; i<N; i++){
//         scanf("%d", &arr[i]);
//     }
// }

// int binarySearch(int s, int e, int j, int a){

//     if ( s > e ) return -1; 
//     int mid = (e+s) /2;
//     int val = arr[mid] - j;
//     if ( val >= a && val <= 2*a){
//         return mid;
//     }else if (a>val){ // val가 찾는 값보다 작다면 ? 
//         s = mid + 1;
//         return binarySearch(s, e, j, a);
//     }else { // val > 2a
//         e = mid - 1;
//         return binarySearch(s, e, j, a);
//     }
    
// }

// int checkPossible(int n, int diff){
//     if (n >= diff && n <= 2*diff){
//         return 1;
//     }else {
//         return 0;
//     }

// }

// searchNear(int j, int diff, int idx){
//     int idxUp;
//     int idxDown;
//     int cnt ;

//     cnt = 1;
//     idxUp = idx+1;
//     idxDown = idx-1;

//     for (;;){
//         if( checkPossible(arr[idxUp++]-j, diff) ){
//             int temp = idxUp -1;
//             printf("%d %d \n", arr[temp]-j, diff);
//             cnt ++;
//         }else {
//             break;
//         }
//     }

//     for (;;){
//         if( checkPossible(arr[idxDown--]-j, diff) ){
//             int temp = idxDown +1;
//             printf("%d %d \n", arr[temp]-j, diff);
//             cnt ++;
//         }else {
//             break;
//         }
//     }
//     return cnt;
// }

// int solve(){
//     int ans = 0;

//     int diff = 0;
//     int idx = 0;

//     for( int i =0; i <N-2; i++){
//         for (int j =i+1; j<N-1; j++){ // N-2 까지
//             diff = arr[j]-arr[i];
//             idx = binarySearch(j+1, N-1, j, diff);
//             printf("i=%d, j=%d, diff=%d\n", i, j, diff);
//             if (idx == -1){
//                 continue;
//             }else {
//                 ans += searchNear(j, diff, idx);
//             }
//             //printf("%d\n", ans);
//         }
//     }

//     return ans;
// }

// int compare(const void *a, const void *b){
//     int num1 = *(int *)a;
//     int num2 = *(int *)b;
//     return num1-num2;
// }

// int main(){
//     int ans ;
//     inputData();
//     qsort(arr, N, sizeof(int), compare);
//     ans = solve();
//     printf("%d", ans);
//     return 0;
// }

#include <stdio.h>
#define MAXN ((int)1e3)
int N;
int arr[MAXN+10];

void inputData(){
    scanf("%d", &N);

    for (int i =0; i<N; i++){
        scanf("%d", &arr[i]);
    }
}

int checkPossible(int n, int diff){
    if (n >= diff && n <= 2*diff){
        return 1;
    }else {
        return 0;
    }
}

int solve(){
    int ans = 0;

    int diff = 0;
    int idx = 0;

    for( int i =0; i <N-2; i++){
        for (int j =i+1; j<N-1; j++){ // N-2 까지
            diff = arr[j]-arr[i];
            
            for (int k = j+1; k<N; k++){
                if (checkPossible(arr[k]-arr[j], diff)){
                    ans ++;
                }
            }
        }
    }
    return ans;
}

int compare(const void *a, const void *b){
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    return num1-num2;
}

int main(){
    int ans ;
    inputData();
    qsort(arr, N, sizeof(int), compare);
    ans = solve();
    printf("%d", ans);
    return 0;
}
