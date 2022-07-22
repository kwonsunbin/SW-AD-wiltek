#include <stdio.h>
#include <string.h>

char str[100000 + 10];//쇠막대기와 레이저의 배치를 나타내는 괄호 표현 문자열
int ans;
void InputData(void){
	scanf("%s", str);
}

void solve(void){
    int opened=0;
    int fixOpened = 0;

    for (int i=0; i< strlen(str); i++){
        if (str[i]== '('){
            opened++;
        }
        if (str[i]== ')'){
            if(opened == 0 ){
                ans ++;
                opened ++;
            }else {
                opened--;
            }
        }
    }
    ans+=(opened/2);
}

int main(void)
{
      // 여기서부터 작성
      InputData();
      
      solve();
      printf("%d", ans);
 
      return 0;
}