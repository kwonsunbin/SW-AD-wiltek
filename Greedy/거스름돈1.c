#include <stdio.h>
 
int ans;
int a ;

void inputData(){
    scanf("%d",&a);
}

void solve(){
    ans += (a / 500); 
    a = (a % 500);

    ans += (a /100);
    a = (a % 100);
    
    ans += (a/50);
    a = (a%50);

    ans += (a/10);
    a = (a%10);
    
}

int main(void)
{
      // 여기서부터 작성
    inputData();
    solve();
    printf("%d", ans);
    return 0;
}