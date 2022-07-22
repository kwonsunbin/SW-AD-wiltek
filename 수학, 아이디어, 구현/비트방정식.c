#include <stdio.h>
#pragma warning(disable: 4996)

long long  X, K;

void InputData() {
	scanf("%lld", &X);
	scanf("%lld", &K);

}

int main(void) {
	InputData();

	long long Y = 0;
	for (int i = 0; (K > 0) && (i < 64); i++) {
		if (((X >> i) & 1) == 0) {
			Y |= (K & 1) << i;
			K >>= 1;
		}
	}

	printf("%lld\n", Y);
  
    return 0;
	




}