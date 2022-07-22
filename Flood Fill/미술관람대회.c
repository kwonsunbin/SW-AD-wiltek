#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
int N;
char map[100 + 10][100 + 10];
char mapRG[100 + 10][100 + 10];
int ans;
int ansRG;


void inputData() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", &map[i]);
	}
	memcpy(mapRG, map, sizeof(map));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mapRG[i][j] == 'R') {
				mapRG[i][j] = 'G';
			}
		}
	}
}

void check(){
	for (int i = 0; i < N; i++) {
		printf("%s\n", map[i]);

	}

	for (int i = 0; i < N; i++) {
		printf("%s\n", mapRG[i]);
	}
}

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1, 0,0 };
int nr; int nc;


void DFS(int r, int c, char color) {

	for (int i = 0; i < 4; i++) {
		nr = r + dr[i];
		nc = c + dc[i];

		if (nr < 0 || nc < 0 || nr >= N || nc >= N) {
			continue;
		}
		if (map[nr][nc] == color) {
			map[nr][nc] = '0';
			DFS(nr, nc, color);
		}

	}
}


void DFSRG(int r, int c, char color) {

	for (int i = 0; i < 4; i++) {
		nr = r + dr[i];
		nc = c + dc[i];

		if (nr < 0 || nc < 0 || nr >= N || nc >= N) {
			continue;
		}
		if (mapRG[nr][nc] == color) {
			mapRG[nr][nc] = '0';
			DFSRG(nr, nc, color);
		}

	}
}


void outputData() {
	printf("%d %d", ans, ansRG);
}


char color;

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != '0') {
				color = map[i][j];
				map[i][j] = '0';
				DFS(i, j, color);
				ans++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mapRG[i][j] != '0') {
				color = mapRG[i][j];
				mapRG[i][j] = '0';
				DFSRG(i, j, color);
				ansRG++;
			}
		}
	}

}

int main() {
	inputData();
	//check();
	solve();
	
	outputData();

	return 0;
}