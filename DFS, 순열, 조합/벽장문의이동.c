#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define MAXN (20)

int N;
int sl, sr;
int M;
int seq[MAXN + 10];
void InputData(void) {
    scanf("%d", &N);
    scanf("%d %d", &sl, &sr);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &seq[i]);
    }
}

int min = 2e9;

void DFS(int n, int sum, int l, int r) {

    if (n >= M) { 
        if (sum < min) { min = sum; }
        return; 
    }

    DFS(n + 1, sum + abs(seq[n] - l), seq[n], r);

    DFS(n + 1, sum + abs(seq[n] - r), l, seq[n]);

}
int main(void) {
    int ans = -1;
    

    InputData();//입력받는 부분

    DFS(0,0,sl,sr);
    ans = min;
    printf("%d\n", ans);//출력하는 부분
    return 0;
}