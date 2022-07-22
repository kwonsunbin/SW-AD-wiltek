#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct Number{
    int type;
    int a;
    int b;
} Number;

int A, B;
int Num;
Number arr[10000];


void InputData(void){
    scanf("%d", &A);
    scanf("%d", &B);
}

void CheckFriend(int n){
    int MySum =0;
    int YourSum = 0;
    for (int i=1; i<n; i++){
        if(n%i ==0){
            MySum+=i;
        }
    }

    for (int i=1; i<MySum; i++){
        if(MySum%i ==0){
            YourSum+=i;
        }
    }
    if (n == YourSum && MySum != YourSum ){
        Number temp;
        temp.type = 1;
        temp.a = YourSum;
        temp.b = MySum;
        arr[Num++] = temp;
    }

}

void CheckComplete(int n){
    int sum =0;
    for (int i=1; i<n; i++){
        if(n%i ==0){
            sum+=i;
        }
    }
    if(sum==n){
        Number temp;
        temp.a = n;
        temp.type = 0;
        arr[Num++] = temp;
    }

    
}




int main(void){
    InputData();
    for (int i = A; i<B+1; i++){
        CheckComplete(i);
        CheckFriend(i);
    }
    printf("%d\n",Num);
    Number tmp;
    for (int i = 0; i<Num; i++){
        
        tmp = arr[i];
        if(tmp.type ==0){
            printf("%d\n", tmp.a);
        }

        if(tmp.type ==1){
            printf("%d %d\n", tmp.a, tmp.b);
        }
    }

    return 0;
}