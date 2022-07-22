#include <stdio.h>
#include <string.h>
 
int M;
char a[100+10];
char b[100+10];
int b_ptr;

void inputData(){
    scanf("%d", &M);
    scanf("%s", &a);  
}

void solve(){
    char prevChar, crntChar ;
    int cnt = 1 ;
    prevChar = a[0];
    b[0] = a[0];
    b_ptr ++;

    for (int i =1; i < strlen(a)+1; i++){
        crntChar = a[i];
        if ( (prevChar == crntChar)  ){
            cnt ++;
        }else {
            if (cnt >= M){
                b[b_ptr+1-cnt] = '(';
                b[b_ptr+2-cnt] = cnt + '0';
                b[b_ptr+3-cnt] = ')';
                memset(&b[b_ptr+4-cnt], 0, sizeof(char)*(110 - b_ptr+4-cnt));
                b_ptr= b_ptr+3-cnt +1;
                cnt = 1;
            }else {
                cnt = 1;
            }
        }
        if(i == strlen(a)){
            break;
        }
        b[b_ptr++] = crntChar;
        prevChar = crntChar;
    }
}

void outputData(){
    printf("%s", b);
}

int main(void)
{
      // 여기서부터 작성
      inputData();
      solve();
      outputData();
 
      return 0;
}
