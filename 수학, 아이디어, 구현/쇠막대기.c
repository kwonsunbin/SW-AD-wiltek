#include <stdio.h>
#include <string.h>

char str[100000 + 10];//쇠막대기와 레이저의 배치를 나타내는 괄호 표현 문자열
int ans;
void InputData(void){
	scanf("%s", str);
}

void solve(void){
    int crntBarNum = 0;

    for (int i =0; i<strlen(str); i++){

        if(str[i]=='('){
            if (str[i+1]==')') continue;
            else { crntBarNum+=1;}
        }

        if(str[i]==')'){
            if (str[i-1]=='(') ans+=crntBarNum;// laser이라면, 
            else {                       // laser가 아니라면,  
                ans+=1;
                crntBarNum-=1;
            }
        }
    }
}

int main() {
	InputData();//입력
	
	//여기서부터 작성
    solve();
	
	printf("%d\n", ans);//출력
	return 0;
}