#include <stdio.h>
 
int N;
int pillars[1000+100];
int ans;
int maxL = -1, minL = 1001 ;
int maxH = -1, maxHidx = -1 ;

void inputData(void){
    scanf("%d" ,&N);
    int idx = 0;
    int val = 0;

    for (int i = 0; i<N; i++){
        scanf("%d", &idx);
        scanf("%d", &val);
        pillars[idx]= val;
        if (maxL < idx ){
            maxL = idx;
        }
        if (minL > idx ){
            minL = idx;
        }
        if (maxH < val ){
            maxH = val;
            maxHidx = idx;
        }
    }    

}

void outputData(void){
    printf("%d", ans);
}

void solve(void){

    if (maxHidx == maxL | maxHidx == minL){
        ans -= maxH;
        if ( maxL == minL){
            ans -= maxH;
        }
    }

    // minL 부터 maxHidx -1까지 
    int height = pillars[minL];
    ans += height;

    for (int l = minL+1; l<maxHidx; l++){ 
        if (pillars[l] > height){
            height = pillars[l];
        }
        ans+=height;
    }
    // maxHidx만
    height = maxH;
    ans+= height;

    // maxL 부터 maxHidx+1 까지 15 ~ 9까지 .. 오른쪽부터
    height = pillars[maxL];
    ans += height;

    for (int l = maxL-1; l>maxHidx; l--){ 
        if (pillars[l] > height){
            height = pillars[l];
        }
        ans+=height;
    }
    
}

int main(void)
{
    inputData();
    solve();
    outputData();
 
    return 0;
}