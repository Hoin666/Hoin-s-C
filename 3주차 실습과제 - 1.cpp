#include<stdio.h>
void func(int a, int b); // int 변수 a와 b를 파라미터로 갖는 함수 선언
int main(void) {
	func(215, 4984);
	return 0;
}
void func(int a, int b) { // 함수 구현
	for (int j = 1; b / j > 0; j = j * 10){ // j를 1부터 10씩 곱해 나간다. b를 j로 나누었을 때 나머지가 0이 되면 멈춘다.
		printf("%d\n", ((b / j) % 10) * a); // j가 10씩 증가하면 b의 맨 뒷자리 숫자가 사라진다. 여기에 a를 곱한 값을 출력한다.
	}
	printf("%d", a * b); // a와 b를 곱한 값을 출력한다.
}