#include <stdio.h>
#include <string.h>
#define MAXN ((int)12)
#pragma warning(disable : 4996)
int arr[6][3];
int crntArr[6][3];

void inputData() {
	for (int i = 0; i < 6; i++) {
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}
}

void outputData() {
	for (int i = 0; i < 6; i++) {
		printf("%d %d %d\n", arr[i][0], arr[i][1], arr[i][2]);
	}
}

int matches[15+3][2];
int matchesPtr;
int match[2];
int flag;

void getMatches(int n, int s) {
	if (n >= 2) {
		matches[matchesPtr][0] = match[0];
		matches[matchesPtr][1] = match[1];
		matchesPtr++;
		return;
	}
	for (int i = s; i < 6; i++) { // n=2 일 때, 0 ,1 이 최초 임. n=3 일 때, 0,2
		match[n] = i;
		getMatches(n + 1, i + 1);
	}
}

int checkCrntState(int a, int b) {
	if (crntArr[a][0] > arr[a][0] || crntArr[b][0] > arr[b][0] || crntArr[a][2] > arr[a][2] || crntArr[b][2] > arr[b][2] || crntArr[a][1] > arr[a][1] || crntArr[b][1] > arr[b][1]) {
		// 방금 건드린 게 어느 하나라도 원래 결과보다 큰 값을 갖는 다면 이후 DFS 를 진행할 이유가 없음..
		return 0;
	}
	else {
		return 1;
	}

}

void DFS(int n) {

	if (flag == 1) { return; }

	if (n >= 15) {
		int cnt = 0;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (crntArr[i][j] == arr[i][j]) {
					cnt++;
				}
			}
		}

		if (cnt == 18) flag = 1;
		return;
	}

	

	// matches[n][0]이 승리
	crntArr[matches[n][0]][0]++;
	crntArr[matches[n][1]][2]++;

	if (checkCrntState(matches[n][0], matches[n][1])) {
		DFS(n + 1);
	}
	

	crntArr[matches[n][0]][0]--;
	crntArr[matches[n][1]][2]--;

	// matches[n][1]이 승리
	crntArr[matches[n][1]][0]++;
	crntArr[matches[n][0]][2]++;

	if (checkCrntState(matches[n][0], matches[n][1])) {
		DFS(n + 1);
	}

	crntArr[matches[n][1]][0]--;
	crntArr[matches[n][0]][2]--;

	// 무승부
	crntArr[matches[n][1]][1]++;
	crntArr[matches[n][0]][1]++;

	if (checkCrntState(matches[n][0], matches[n][1])) {
		DFS(n + 1);
	}

	crntArr[matches[n][1]][1]--;
	crntArr[matches[n][0]][1]--;


}


int solve() {
	memset(crntArr, 0, sizeof(0));
	memset(match, 0, sizeof(0));
	memset(matches, 0, sizeof(0));
	matchesPtr = 0;
	flag = 0;
	getMatches(0,0);

	
	
	DFS(0);

	return flag;
	
}

int main() {
	int ans[4];
	for (int i = 0; i < 4; i++) {
		
		inputData();
		
		ans[i]= solve();
	}

	for (int i = 0; i < 4; i++) {
		if (ans[i] == 1) { printf("1 "); }
		else { printf("0 "); }
	}
	
}