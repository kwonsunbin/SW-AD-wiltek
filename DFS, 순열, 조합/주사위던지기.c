#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int N, M;
int dice[5 + 5];

void DFS(int n) { // 던진 횟수
	
	if (n >= N) { // 종료 조건
		for (int i = 0; i < N; i++) {
			printf("%d ", dice[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= 6; i++) {
		dice[n] = i;
		DFS(n + 1);
	}
}


void DFS2(int n, int s) { // 던진 횟수

	if (n >= N) { // 종료 조건
		for (int i = 0; i < N; i++) {
			printf("%d ", dice[i]);
		}
		printf("\n");
		return;
	}

	for (int i = s; i <= 6; i++) {
		dice[n] = i;
		DFS2(n + 1, i); // i -> i+1 로하면 조합임!
	}

}

int used[7];
void DFS3(int n) { // 던진 횟수

	if (n >= N) { // 종료 조건
		for (int i = 0; i < N; i++) {
			printf("%d ", dice[i]);
		}
		printf("\n");
		return;
	}


	for (int i =1; i <= 6; i++) {
		if (used[i]) continue;
		used[i] = 1;
		dice[n] = i;
		DFS3(n + 1);
		used[i] = 0;
	}
	
}
void solve() {
	if (M == 1) { // 중복 순열
		DFS(0);
	}
	if (M == 2) { // 중복 조합, 조합
		DFS2(0, 1);
	}
	if (M == 3) { // 순열
		memset(used, 0, sizeof(0));
		DFS3(0);
	}
}

void inputData() {
	scanf("%d %d", &N, &M);

}

int main() {
	inputData();
	solve();

	return 0;
}