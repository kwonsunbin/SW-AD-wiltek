#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int N;
int arr[200][3];
int ans[200];

void InputData(void){
    scanf("%d", &N);
    for (int i =0; i<N; i++){
        for (int j=0; j<3; j++){
            scanf("%d",&arr[i][j]);
        }
    }
}

void PrintData(void){
    for (int i =0; i<N; i++){
        for (int j=0; j<3; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void GetResult(void){
    int tmp = 0;
    int duplicate_flag = 1;

    for (int j=0; j<3; j++){
        for (int i=0; i<N; i++){
            tmp = arr[i][j];
            duplicate_flag = 1;
            for (int k=0; k<N; k++){
                if (k==i)continue;
                if (tmp == arr[k][j]) {
                    duplicate_flag = 0;
                    break;
                }
            }
            if (duplicate_flag){
                ans[i] += tmp;
            }
        }
    }


}

int main(void){
    InputData();
    GetResult();

    for (int i =0; i<N; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}