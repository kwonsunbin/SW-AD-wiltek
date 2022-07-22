#include <stdio.h>
#pragma warning(disable: 4996)

int a, b, c, d;

void InputData() {
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &d);
}

int CheckCross() {
	if (c > a && d < b ) {
		return 0;
	}
	else if ((c < a && d > b) || d<a || c > b ) {
		return 0;
	}
	else {
		return 1;
	}
	
}
int main(void) {
	InputData();
	int temp;
	if (b<a){
		temp = b;
		b = a;
		a = temp;
		
	}

	if (d < c) {
		temp = d;
		d = c;
		c = temp;

	}
	if (CheckCross()) {
		printf("cross");
	}
	else {
		printf("not cross");
	}
	
	

	
}