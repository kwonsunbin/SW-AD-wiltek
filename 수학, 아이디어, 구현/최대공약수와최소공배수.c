#include <stdio.h>
#pragma warning(disable: 4996)

int a, b;

void InputData() {
	scanf("%d", &a);
	scanf("%d", &b);
}

int yaksu(int a, int b) {
	
	int yaksu = 0;

	for (int i = 1; i <a+1 ; i++) {
		if (a % i == 0 && b % i == 0) yaksu = i;
	}

	return yaksu;

}

int baesu(int a, int b, int yaksu) {
	int baesu = 0;
	int temp_a, temp_b;

	temp_a = a / yaksu;
	temp_b = b / yaksu;

	baesu = yaksu * temp_a * temp_b;

	return baesu;
}
int main(void) {
	InputData();
	
	printf("%d\n", yaksu(a, b));
	printf("%d\n", baesu(a, b, yaksu(a,b)));
	




}