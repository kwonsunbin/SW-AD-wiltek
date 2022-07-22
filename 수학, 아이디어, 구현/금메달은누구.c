//1. ����(1���� : �հ�, 2���� : ��ȣ), �ܼ�����
#include <stdio.h>
#pragma warning(disable: 4996)
#define MAXN (10)
int N;
typedef struct {
	int id, sum; // ��ȣ, �հ�
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
	sort(0, N - 1); // �ܼ�����
	OutputData();
	return 0;
}