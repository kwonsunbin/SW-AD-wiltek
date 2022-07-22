#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
int N;

char map[25 + 10][25 + 10];
int ans[25 * 25+10];
int ansPtr;

int compare(const void* a, const void* b)    // 오름차순 비교 함수 구현
{
	int num1 = *(int*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	int num2 = *(int*)b;  

	if (num1 < num2)   
		return -1;     

	if (num1 > num2)   
		return 1;      

	return 0;   
}

void inputData() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", &map[i]);
	}
}

void outputData() {
	printf("%d\n", ansPtr);
	for (int i = 0; i < ansPtr; i++) {
		printf("%d\n", ans[i]);
	}
	
}

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1, 0,0 };
int nr; int nc;
int temp;

void DFS(int r, int c) {
	temp++;
	for (int i = 0; i < 4; i++) {
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
				temp = 0;
				DFS(i, j);
				//printf("%d\n", temp);
				ans[ansPtr++] = temp;
				
				
			}
		}
	}
}

int main() {
	inputData();
	solve();
	qsort(ans, ansPtr, sizeof(0),compare);

	outputData();
	
	return 0;
}