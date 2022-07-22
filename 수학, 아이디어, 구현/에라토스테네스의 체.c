#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS


int N, K ;
int erase_cnt;
int ans;
int arr[1000];
int smallest_sosu;

void InputData(void){
    scanf("%d" ,&N);
    scanf("%d" ,&K);
}

void InitArr(){
    for (int i=2; i<N+1; i++){
        arr[i-2]= i; // 0 ~ N-2
    }
}

int Filtering(int n){
    for (int i=0; i<N-1; i++){
        if (arr[i]== 0){continue;}
        if (arr[i] % n == 0){
            erase_cnt++;
            if (erase_cnt == K){
                return arr[i];
            }
            arr[i] = 0;
        }
    }
    return 0;
}

int IsSosu(int n){
    int numOfYaksu = 0;
    if (n == 0){
        return 0;
    }
    for (int i=1; i <n; i ++){
        if(n % i == 0) {
            numOfYaksu ++;
        }
    }
    if(numOfYaksu ==1){
        return 1;
    }else {
        return 0;
    }
}

int FindSmallestSosu(){
    for (int i=0; i<N-1; i++){
        if (IsSosu(arr[i])){
            return arr[i];
        }
    }
}

int getTotalSumOfArr(){
    int sum = 0 ;
    for (int i=0; i<N-1; i++){
        sum+= arr[i];
    }
    return sum;
}


int main(void){

    InputData();
    InitArr();


    while (getTotalSumOfArr() != 0){
        smallest_sosu = FindSmallestSosu();
        ans = Filtering(smallest_sosu);
        if (ans) break;

        
        

        
    }
    

    printf("%d", ans);
    
    
    

    return 0;
}