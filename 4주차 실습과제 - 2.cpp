#include<stdio.h>
int func(int n); // 정수 값을 변수로 갖고 정수값을 반환하는 함수 선언
int main(void) {
	int n = 6; // n이 6일 때값 출력
	printf("직전 세 항의 합이 다음 항인 수열의 %d번째 값은 %d입니다.",n, func(n)); // n이 6일 때값 출력
	return 0;
}
int func(int n) { // 전 3항의 값의 합을 반환하는 수열을 구현한 함수
	if (n <= 1) { // n이 1이하이면 0을 반환한다.
		return 0;
	}
	else if (n == 2) { // n이 2이면 1을 반환한다.
		return 1;
	}
	else if (n == 3) { // n이 3이면 2를 반환한다.
		return 2;
	}
	else { // n이 4 이상일 경우네는 재귀호출로 전 3항의 값을 반환하도록 한다.
		return func(n - 1) + func(n - 2) + func(n - 3);
	}
}