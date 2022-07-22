#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int N, P;
int arr[10000];
int arr_ptr;

void InputData(void){
    scanf("%d", &N);
    scanf("%d", &P);
    
}

void InitArr(void){
    arr[0] = N;
    arr_ptr = 1;
}

int CheckPrev(int n){
    // if n이 Arr에 존재 -> return 해당 반복된 친구 인덱스;
    for (int i = 0 ; i < arr_ptr-1; i++){
        if (n == arr[i]){
            return i;
        }
    }
    // else -> return 0;
    return 0;
}

int main(void){
    InputData();
    InitArr();

    int idx = 0;

    while(1){
        arr[arr_ptr] = ( arr[arr_ptr-1] * N ) % P;
        arr_ptr ++;

        idx = CheckPrev(arr[arr_ptr-1]);
        if( idx ){
            break;
        }
    }


    printf("%d", (arr_ptr-1) -idx );

    return 0;
}