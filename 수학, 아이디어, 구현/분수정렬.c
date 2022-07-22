#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

typedef struct fraction{
    int top;
    int bottom;
    double val;
}fraction;

double prev_val;
int N;
fraction arr[160*100]; //N+ N*(N+1) / 2;
int arr_ptr ;

void InputData(void){
    scanf("%d", &N);
    
}

void InitArr(void){
    for (int i = 1; i< N+1; i++){
        for (int j=0; j< i+1; j++){
            fraction tmp;
            tmp.bottom = i;
            tmp.top = j;
            tmp.val = (double)j/(double)i;
            arr[arr_ptr++] = tmp;
        }
    }
}
int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    fraction *x =a;
    fraction *y =b;

    if (x->val < y->val)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (x->val > y->val)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    else { // a.val과 b.val 이 같은 경우는 분모의 값이 작은 것을 앞으로
        if(x->bottom < y->bottom) return -1;
        else return 1;
    }

}

int main(void){
    InputData();
    InitArr();
    int lenArr = N+ N*(N+1) / 2;


    qsort(arr, lenArr, sizeof(fraction), compare);

    prev_val = -1;
    for (int i=0; i<lenArr; i++){
        
        if (prev_val == arr[i].val) continue;
        printf("%d/%d\n", arr[i].top, arr[i].bottom);
        prev_val = arr[i].val;
    }


    return 0;
}