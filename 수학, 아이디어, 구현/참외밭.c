#include <stdio.h>
typedef struct vector{
    int dir;
    int len;
}vector;

vector arr[6];
int N;
int ans;

void inputData(){
    vector temp ;
    scanf("%d", &N);
    int a = 0;
    int b = 0;
    for (int i=0; i<6; i++){
        scanf("%d", &a);
        scanf("%d", &b);
        temp.dir = a;
        temp.len = b;
        arr[i]= temp;
    }
}

void outputData(){
    for (int i=0; i<6; i++){
        printf("dir=%d, len=%d\n", arr[i].dir, arr[i].len);
    }
}

void solve(){
    int rowLen=0;
    int colLen=0;
    vector temp;
    
    for (;;){

        if (arr[1].len == (arr[3].len + arr[5].len) && arr[0].len == (arr[2].len + arr[4].len) ){
            break;
        }
        else {
            temp = arr[5];
            for (int i =5; i>0; i--){
                arr[i] = arr[i-1];
            }
            arr[0] = temp;
        }
    }

    ans = (arr[1].len* arr[0].len - arr[3].len *arr[4].len)*N;

}

int main(void)
{
      // 여기서부터 작성
      inputData();
      //outputData();
      solve();
      //outputData();
      printf("%d",ans);

 
      return 0;
}
