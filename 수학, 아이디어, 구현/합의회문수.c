#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

int N;
char numStr[10+3];
char sumStr[11+3];
int sum;

void InputData(void){
    scanf("%d", &N);
}

void GetSum(void){
    for (int j=0; j<strlen(numStr); j++){
        sum+= (numStr[j]-48) * pow(10,j) ;
        sum+= (numStr[j]-48) * pow(10,strlen(numStr)-j-1) ;
    }
}

void CheckMirrorNum(int n){
    if (n<10){
        printf("YES\n");
        return;
    }
    memset(sumStr,0,14);
    int a = n, len = 0;
    for (int i =0; i<14; i++){ // 임의의 수 14, 11을 넘을리는 없으니깐
        sumStr[i] = a%10 + 48;
        a /= 10;
        if (a<10){ sumStr[i+1] = a+48; break;}
    }

    len = strlen(sumStr);

    for (int i=0; i<len/2; i++){

        if(sumStr[i] != sumStr[len-1-i]){
            
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");

}

int main(void){
    InputData();
    
    for (int i=0; i<N; i++){
        scanf("%s", &numStr);
        sum = 0;
        GetSum();
        CheckMirrorNum(sum);

    }



}