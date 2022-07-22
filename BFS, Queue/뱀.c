#include <stdio.h>
#pragma warning(disable : 4996)
#define MAXN ((int)1e2)

typedef struct coord{
	int x;
	int y;
}coord;

coord queue[10000];
int wp = 0; int rp = 0;

coord pop() { return queue[++rp]; }
void push(coord d) { queue[++wp] = d; }
coord top() { return queue[wp]; }
int empty() { return rp == wp; }
int size() { return wp - rp; }
int search(int x, int y) {
	for (int i = rp + 1; i <= wp; i++) {
		if (queue[i].x == x && queue[i].y == y) {
			return 1;
		}
	}
	return 0;
}

//void print() {
//	printf("===============\n");
//	for (int i = rp + 1; i <= wp; i++) {
//		printf("%d %d\n", queue[i].x, queue[i].y);
//	}
//	printf("===============\n");
//}

int N;
int K;
int D;

char order[10000+10]; // 10000 최대 idx 가 (0부터 담지 않음!)
int map[MAXN+1][MAXN+1];
void inputData() {
	scanf("%d", &N);
	scanf("%d", &K);
	int x = 0; int y = 0;
	for (int i = 0; i < K; i++) { // 1,1 부터 시작!
		scanf("%d %d", &x, &y);
		map[x][y] = 1;
	}
	scanf("%d", &D);
	int temp = 0;
	for (int i = 0; i < D; i++) {
		scanf("%d", &temp);
		scanf(" %c", &order[temp]);
	}
}

//void outputData() {
//
//	printf("map\n");
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			printf("%d ", map[i][j]);
//		}
//		printf("\n");
//	}
//	printf("order\n");
//	for (int i = 1; i < 21; i++) {
//		printf("%d %c\n", i, order[i]);
//	}
//	printf("\n");
//}

int solve() {

	coord start;
	start.x = 1; start.y = 1;
	push(start);

	int dir = 0; 
	int dx[4] = {0,0, -1 ,1}, dy[4] = {1,-1,0,0}; // 0 이 동쪽, 1이 서쪽, 2가 북쪽, 3이 남쪽
	int L[4] = { 2, 3, 1,0 }, D[4] = { 3,2,0,1 }; // 방향이 dir 일 때, L 명령 나오면 dir = L[dir]
	int x = 1, y = 1;
	for (int s = 0; s < 10001; s++) {


		// 매초 마다 이동을한다. 0~ 1 초 일 때 ?
		if (order[s] != 0) { // 방향 전환.
			if (order[s] == 'L') { // L
				dir = L[dir];
			}
			else { // R;
				dir = D[dir];
			}
		}

		x += dx[dir];
		y += dy[dir];

		if (x <= 0 || y <= 0 || x > N || y > N) {
			return s+1;
		}
		
		if (search(x, y)) {
			return s+1;
		}

		coord temp;
		temp.x = x; temp.y = y;
		push(temp);

		if (map[x][y] == 1) {
			map[x][y] = 0;
		}else {
			pop();
		}

		 
		
	}
}

int main() {
	inputData();
	//outputData();
	int ans;
	ans = solve();
	printf("%d", ans);
	return 0;
}