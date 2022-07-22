#include <stdio.h>
#pragma warning(disable : 4996)
#define MAXN 80000

int N;
int H[MAXN + 10];
int stack[MAXN + 10];
int sp = 0;
long long ans = 0;

int pop() { return stack[sp--]; }
int push(int d) { stack[++sp] = d; }
int top() { return stack[sp]; }
int empty() { return sp == 0; }
int size() { return sp; }


void inputData() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &H[i]);
	}
}

void outputData() {
	printf("%lld\n", ans);
}

// 앞소를 볼 수 있는 소들만 제거
void solve2() {
	int cnt = 0;
	push(H[0]);
	for (int i = 1; i <N ; i++) {
		while (!empty() && H[i] >= top()) { // i번 소보다 작거나 같은 소는 제거한다.
			pop();
		}

		ans += size();
		push(H[i]);
	}
	
}

void solve1() {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (H[i] > H[j]) {
				ans++;
			}
			else {
				break;
			}
		}
	}

}

int main(void) {
	inputData();
	solve2();
	outputData();
	return 0;
}