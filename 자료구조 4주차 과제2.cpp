#include<stdio.h>
int func(int n);
int main(void) {
	int n = 6;
	printf("직전 세 항의 합이 다음 항인 수열의 n번째 값은 %d입니다.", func(n));
	return 0;
}
int func(int n) {
	if (n <= 0) {
		return 0;
	}
	else if (n == 1) {
		return 0;
	}
	else if (n == 2) {
		return 1;
	}
	else if (n == 3) {
		return 2;
	}
	else {
		return func(n - 1) + func(n - 2) + func(n - 3);
	}
}