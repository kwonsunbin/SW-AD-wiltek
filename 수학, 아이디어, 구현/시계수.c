#include <stdio.h>


int arr[4];
int clockNum;
int ans;

void InputData(void){
    for (int i =0; i<4; i++){
        scanf("%d", &arr[i]);
    }    
}

void OutputData(void){
    printf("%d", ans);
    
}

int getClockNum(){
    int min = 10000;
    int toCompare[4] = {0,};

    toCompare[0]= arr[0]*1000 + arr[1]*100 + arr[2] * 10 + arr[3];
    toCompare[1]= arr[1]*1000 + arr[2]*100 + arr[3] * 10 + arr[0];
    toCompare[2]= arr[2]*1000 + arr[3]*100 + arr[0] * 10 + arr[1];
    toCompare[3]= arr[3]*1000 + arr[0]*100 + arr[1] * 10 + arr[2];

    for (int i=0; i<4; i++){
        if ( min > toCompare[i]){
            min = toCompare[i];
        }
    }
    return min;
}

int getTmpClockNum(int n){
    int min = 10000;
    int toCompare[4] = {0,};
    int arr[4] = {0,};

    for (int i = 3; i>=0; i--){
        arr[i]=n%10 ; // 1123 -> 0 : 3, 1: 2, 2: 1, 3: 1
        n/=10; 
    }


    toCompare[0]= arr[0]*1000 + arr[1]*100 + arr[2] * 10 + arr[3];
    toCompare[1]= arr[1]*1000 + arr[2]*100 + arr[3] * 10 + arr[0];
    toCompare[2]= arr[2]*1000 + arr[3]*100 + arr[0] * 10 + arr[1];
    toCompare[3]= arr[3]*1000 + arr[0]*100 + arr[1] * 10 + arr[2];

    for (int i=0; i<4; i++){
        if ( min > toCompare[i]){
            min = toCompare[i];
        }
    }
    return min;
}


void countOrder(void){
    for (int i=1111; i< clockNum+1; i++){
        
        if ( i == getTmpClockNum(i)){
            ans++;
        }

    }
};


int main(void){
    InputData();
    clockNum = getClockNum();
    countOrder();
    OutputData();

    return 0;
}