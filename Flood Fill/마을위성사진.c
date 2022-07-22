#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int N;
char map[100 + 10][100 + 10];
int ans;

void inputData() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", &map[i]);
	}
}


int dr[8] = { 0,1,1,1,0,-1,-1,-1 };
int dc[8] = { 1,1,0,-1,-1,1,-1,0,1 };
int nr; int nc;

void DFS(int r, int c) {
	for (int i = 0; i < 8; i++) {
		nr = r + dr[i];
		nc = c + dc[i];

		if (nr < 0 || nc < 0 || nr >= N || nc >= N) {
			continue;
		}
		if (map[nr][nc] == '1') {
			map[nr][nc] = '2';
			DFS(nr, nc);
		}
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1') {
				map[i][j] = '2';
	
				DFS(i, j);
				ans++;


			}
		}
	}
}

int main() {
	inputData();
	solve();

	printf("%d", ans);

	return 0;
}