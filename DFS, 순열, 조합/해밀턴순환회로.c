#include <stdio.h>
#define MAXN ((int)12)
#pragma warning(disable : 4996)

int N;
int arr[MAXN + 10][MAXN + 10];
void inputData() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}
int used[MAXN + 10];
int min;
void DFS(int n, int sum, int pre) { //1을 제외하고 순열
    if (sum >= min) return;
    if (n >= N -1) { // 0~ N-2 까지 까득 차있음
        if (arr[pre][0] == 0) return;
        sum += arr[pre][0];
        if (sum < min) {
            min = sum;
        }
        return; 
    }
    for (int i = 1; i < N; i++) { // 1~ N-1 번 대회장 다 들리기 
        if (used[i] == 1) continue;
        if (arr[pre][i] == 0)  continue;
        used[i] = 1;
        DFS(n+1, sum + arr[pre][i], i);
        used[i] = 0;
    }
}

int main(void)
{
    // 여기서부터 작성
    inputData();
    memset(used, 0, sizeof(0));
    min = (int)2e9;
    DFS(0, 0, 0);
    printf("%d", min);
    return 0;
}