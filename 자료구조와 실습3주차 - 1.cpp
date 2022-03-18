#include<stdio.h>
void func(int a, int b);
int main(void) {
	func(4984, 215);
	return 0;
}
void func(int a, int b) {
	for (int j = 1; b/j > 0; j = j* 10) {
		printf("%d\n", ((b / j) % 10) * a);
	}
	printf("%d", a * b);
}
