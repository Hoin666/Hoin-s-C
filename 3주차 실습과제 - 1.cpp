#include<stdio.h>
void func(int a, int b); // int ���� a�� b�� �Ķ���ͷ� ���� �Լ� ����
int main(void) {
	func(215, 4984);
	return 0;
}
void func(int a, int b) { // �Լ� ����
	for (int j = 1; b / j > 0; j = j * 10){ // j�� 1���� 10�� ���� ������. b�� j�� �������� �� �������� 0�� �Ǹ� �����.
		printf("%d\n", ((b / j) % 10) * a); // j�� 10�� �����ϸ� b�� �� ���ڸ� ���ڰ� �������. ���⿡ a�� ���� ���� ����Ѵ�.
	}
	printf("%d", a * b); // a�� b�� ���� ���� ����Ѵ�.
}