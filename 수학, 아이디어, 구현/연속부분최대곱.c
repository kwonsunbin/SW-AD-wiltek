#include <stdio.h>
 
int N;
double arr[10000];

double res; // res[5000*10001] ->double 1억개. 8바이트 1억개. 8억 바이트, 800 메가 ? 이거 문제있다..

void inputData(void){
    scanf("%d" ,&N);
    for (int i=0; i < N; i++){
        scanf("%lf", &arr[i]);
    }
}

void outputData(void){
    printf("%.3f", res);
}

void solve(void){
    double tmp = 1;
    int k = 0;
    for (int ptr =0; ptr< N; ptr ++ ){
        tmp = 1;
        k = 0;
        for(;;){
            tmp *= arr[ptr+k];
            k++;
            if (tmp > res) res= tmp;
            if (ptr+k > N-1) { break ;} 
        }
    }
}


int main(void)
{
    inputData();  
    solve();
    outputData();    
 
    return 0;
}