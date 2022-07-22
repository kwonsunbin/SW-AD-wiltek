#include <stdio.h>
#include <string.h>

char str[100000];
int ans;
int cnt;

void inputData(){
    scanf("%s", &str);
}

void outputData(){
    printf("%d", ans);
}

void solve(){
    int len = strlen(str);
    char target = '-';

    for (int i =0; i< len; i++ ){
        if (str[i] == '('){
            cnt++;
        }
    }

    if (cnt == len/2){
        ans = 0;
        return;
    }

    int balance= 0;
    if (cnt > len/2){
        target = '(';
        
        for (int i =len-1; i>=0; i-- ){
            if (str[i] == target){
                if (i == len-1){
                    ans =1;
                    return;
                }
                if (i ==0){
                    break;
                }
                ans++;
                balance ++;
            }else {
                balance --;
            }
        }
    }else {
        target = ')';

        for (int i =0; i<len; i++ ){
            
            if (str[i] == target){
                if (i == 0){
                    ans =1; 
                    return;
                }
                if (i == len-1){
                    break;
                }
                ans++;
                balance ++;
            }else {
                balance --;
            }
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
