#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)
#define MAXN ((int)1e1)

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

int min = 2e9;
int used[MAXN + 10];
int buildings[MAXN + 10];

// A , B , C , D 순서 대로 

void DFS(int n) { // 순열 문제임
	if (n >= N) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += arr[i][buildings[i]];
		}
		if (sum < min) {
			min = sum;
		}
		return; 
	}

	for (int i = 0; i < N; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		buildings[n] = i;
		DFS(n + 1);
		used[i] = 0;
	}

}

int main() {
	inputData();
	memset(used, 0, sizeof(0));
	min = 2e9;
	DFS(0);
	printf("%d", min);
	return 0;
}