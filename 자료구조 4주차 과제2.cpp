#include<stdio.h>
int func(int n);
int main(void) {
	int n = 6;
	printf("���� �� ���� ���� ���� ���� ������ n��° ���� %d�Դϴ�.", func(n));
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