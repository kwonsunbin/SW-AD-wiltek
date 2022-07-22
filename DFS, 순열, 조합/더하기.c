#include <stdio.h>
#define MAXN ((int )1e6)
#pragma warning(disable : 4996)

int T; int N; int K;
int arr[MAXN + 10];


// 조합 문제다..
int flag = 0;
void DFS(int n, int s, int sum) {
	if (sum == K) { flag = 1; return; }

	if (n >= N) {
		return;
	}

	for (int i = s; i < N; i++) {
		sum += arr[i];
		DFS(n + 1, i+1, sum);
		sum -= arr[i];
	}
}

int main() {
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &K);
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[j]);
		}
		flag = 0;
		DFS(0, 0, 0);
		if (flag) { printf("YES\n"); }
		else {
			printf("NO\n");
		}
	}
	

	return 0;
}