#include <stdio.h>
#pragma warning(disable : 4996)
int N;
#define MAXN ((int)1e5)

int P[MAXN+10];
int S[MAXN + 10];
int ans = 0;

void inputData() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &P[i], &S[i]);
    }
}

void solve() {
    int v = S[N-1];
    ans++;
    for (int i = N-2; i >= 0; i--) {
        if (v >= S[i]) {
            ans++;
            v = S[i];
        }

    }
}
int main()
{
    inputData();
    solve();
    printf("%d", ans);
    return 0;
}
