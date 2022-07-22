#include <stdio.h>
#include <stdlib.h>

typedef struct flower{
    int monthBloom, monthFail, dayBloom, dayFail;
}flower;

int N;
int ans;
flower arr[100000];

void inputData(){
    flower temp ;
    int a,b,c,d;
    scanf("%d", &N);
    for(int i =0; i<N; i++){
        scanf("%d %d %d %d", &a,&b,&c,&d);
        temp.monthBloom = a;
        temp.dayBloom =b;
        temp.monthFail =c;
        temp.dayFail =d;
        arr[i]= temp; // arr에 담기는 순간 값이 복사 되는 건가 ?? 포인터를 주는게 아니라서??
    }
}

void outputData(){
    printf("%d", ans);
 
}

int compare(const void *a, const void *b){
    flower *x = a;
    flower *y = b;

    if (x->monthFail > y->monthFail) return -1;
    else if (x->monthFail < y->monthFail) return 1;
    else {
        if (x->dayFail > y->dayFail) return -1;
        else if (x->dayFail < y->dayFail) return 1;
        else {
            return 0;
        }
    }

}

int failCompare(int *date, flower b){
    if (date[0] > b.monthFail) return -1;
    else if (date[0] < b.monthFail) return 1;
    else {
        if (date[1] > b.dayFail) return -1;
        else if (date[1] < b.dayFail) return 1;
        else {
            return 0;
            // if (x->monthBloom < y->monthBloom) return -1;
            // else if (x->monthBloom > y-> monthBloom) return 1;
            // else {
            //     if (x->dayBloom < y->dayBloom) return -1;
            //     else if (x->dayBloom > y-> dayBloom) return 1;
            //     else {
            //         return 0;
            //     }
            // }
        }
    }

}

int bloomCompare(int *date, flower b){
    if (date[0] > b.monthBloom) return -1;
    else if (date[0]< b.monthBloom) return 1;
    else {
        if (date[1]> b.dayBloom) return -1;
        else if (date[1]< b.dayBloom) return 1;
        else {
            return 0;
        }
    }

}

int intCompare(int *date1, int *date2){ // date 2 이 과거라면 -1, date2 이 미래라면 1
    if (date1[0] > date2[0]) return -1;
    else if (date1[0]< date2[0]) return 1;
    else {
        if (date1[1]> date2[1]) return -1;
        else if (date1[1]< date2[1]) return 1;
        else {
            return 0;
        }
    }
}


void solve(){
    int fail[2] ={12,1};// 12 1
    int bloom[2] = {13, 32};


    for (int i = 0; i<N; i ++){


        if (failCompare(fail, arr[i]) == -1 ) { // 현재 fail 보다 작으면 , 같아도 된다  1130일에 피어있어야해 같아도 되니깐 0 은 포함하면안됨
            ans ++;

            if (intCompare(fail, bloom) >= 0){ // 가장 이른 bloom date 가 현재 fail date 보다 미래거나 같다면면 ans = 0
                ans = 0;
                break;
            } 
            
            fail[0] = bloom[0]; // 가능한 가장 빠른 bloom date를 다음 fail date로
            fail[1] = bloom[1]; // 가능한 가장 빠른 bloom date를 다음 fail date로
            printf("ans=%d, %d %d\n", ans, fail[0],fail[1]);
            
            bloom[0] = 13; // bloom 초기화
            bloom[1] = 32; // bloom 초기화, 다음 min bloom date를 찾기 위해서
        } 

        if (bloomCompare(bloom, arr[i]) == -1 ){ // 현재 bloom 보다 작으면, 작을 수록 좋은 거다. min값 찾기 같으면 굳이 바꿀 필요 없지.
            bloom[0] = arr[i].monthBloom;
            bloom[1] = arr[i].dayBloom;

            if ( (bloom[0] == 3 && bloom[1]==1) || bloom[0]<=2){//종료 조건
                ans ++; 
                printf("ans=%d, %d %d\n", ans, bloom[0],bloom[1]);
                break;
            }
        }
        
    }
}

int main(void)
{
    inputData();
    qsort(arr, N, sizeof(flower), compare);
    solve();
    outputData();
    return 0;
}
