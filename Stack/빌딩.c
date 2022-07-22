#include <stdio.h>
#pragma warning(disable : 4996)
#define MAXN ((int)1e6)

typedef struct building {
	int h;
	int x;
}building;

int N;
int ans[MAXN + 10];
int H[MAXN + 10];

building stack[MAXN + 10];
int sp = 0;

building pop() { return stack[sp--]; }
void push(building b) { stack[++sp] = b; }
building top() {return stack[sp];}
int empty() { return sp == 0; }
int size() { return sp; }

void inputData() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &H[i]);
	}
}

void outputData() {
	for (int i = 0; i < N; i++) {
		printf("%d\n", ans[i]);
	}
}

void solve() {
	building temp;
	for (int i = 0; i < N; i++) {
		while (!empty() && H[i] > top().h) {
			ans[pop().x-1] = i+1;
		}
		temp.x = i + 1;
		temp.h = H[i];
		push(temp);
	}
}

int main() {
	inputData();
	solve();
	outputData();
	return 0;
}