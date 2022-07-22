#include <stdio.h>
#pragma warning(disable : 4996)
#define MAXN ((int)1e4)

int queue[MAXN + 10];
int N;
int wp = 0;
int rp = 0;

int pop() { return queue[++rp]; }
void push(int d) { queue[++wp] = d; }
int top() { return queue[wp]; }
int empty() { return rp == wp; }
int size() { return wp - rp ; }

void inputData() {
	scanf("%d", &N);

	for (int i = 1; i < N+1; i++) {
		push(i);

	}
}

void solve() {
	int temp = 0;
	for (int i = 0; i < N-1; i++) { // N-1 ¹ø ¼öÇà
		temp = top() / 2;
		for (int j = 0; j < temp ; j++) {
			push(pop());
		}

		printf("%d ", pop());

	}
	printf("%d\n", pop());
}


int main() {
	inputData();
	solve();

	return 0;
}
