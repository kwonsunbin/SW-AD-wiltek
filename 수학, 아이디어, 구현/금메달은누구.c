//1. 정렬(1순위 : 합계, 2순위 : 번호), 단순정렬
#include <stdio.h>
#pragma warning(disable: 4996)
#define MAXN (10)
int N;
typedef struct {
	int id, sum; // 번호, 합계
}STU;

STU stu[MAXN+10];

void InputData(void) {
	scanf("%d", &N);
	int i, j, d;
	for ( i = 0; i < N; i++) {
		scanf("%d", &stu[i].id);
		stu[i].sum = 0;
		for ( j = 0; j < 4; j++) {
			scanf("%d", &d);
			stu[i].sum += d;
		}
	}
}

int compare(STU* a, STU* b) {
	if (a->sum == b->sum) {
		return a->id < b->id;
	}
	return a->sum > b->sum;
}

void OutputData(void) {
	static const char* msg[] = { "GOLD :", "SILVER :", "BRONZE :" };
	int i, k = 0;
	for (i = 0; i < 3; i++) {
		printf("%s", msg[i]);
		printf(" %d", stu[k].id);
		for (k++;k < N; k++) {
			if (stu[k - 1].sum == stu[k].sum) printf(" %d", stu[k].id);
			else break;
		}
		printf("\n");
	}
}

void sort(int s, int e) {
	int i, j;
	STU tmp;
	for (i = s; i < e; i++) {
		for (j = i + 1; j <= e; j++) {
			if (compare(&stu[i], &stu[j]) == 0) {
				tmp = stu[i];
				stu[i] = stu[j];
				stu[j] = tmp;
			}
		}
	}
}
int main(void) {

	InputData();
	sort(0, N - 1); // 단순정렬
	OutputData();
	return 0;
}