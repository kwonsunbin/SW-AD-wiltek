#include <stdio.h>
#pragma warning(disable : 4996)
#define MAXN ((int)1e4)

typedef struct doc{
	int m;
	int importance;
}doc;

doc queue[MAXN + 10];
int T;
int N;
int M;
int arr[100 + 10];
int wp = 0;
int rp = 0;

doc pop() { return queue[++rp]; }
void push(doc d) { queue[++wp] = d; }
doc top() { return queue[wp]; }
int empty() { return rp == wp; } // 같으면 1 반환.
int size() { return wp - rp; }

int findMoreImportant(int n) {
	for (int i = rp+1; i <= wp; i++) {
		if (queue[i].importance > n) {
			return 1;
		}
	}
	return 0;
}


int solve() {
	doc temp;
	for (int i = 0; i < N; i++) {
		temp.m = i;
		temp.importance = arr[i];
		push(temp);

	}
;
	doc crnt;
	int cnt = 0;


	while (!empty()) {
		crnt = pop();
		if (findMoreImportant(crnt.importance)) {
			push(crnt);
		}
		else {
			if (crnt.m == M) {
				cnt++;
				return cnt;
			}
			++cnt;
		}
	}
}
int main() {
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		rp = 0; wp = 0;
		int ans = 0;
		scanf("%d", &N);
		scanf("%d", &M);
		
		
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[j]);
		}

		ans = solve();
		printf("%d\n", ans);
	}

	return 0;
}

