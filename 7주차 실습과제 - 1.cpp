#include<stdio.h>
int main() {
	int arr[9]; // 숫자가 들어갈 크기 9의 배열 선언
	double Avr[9]; // 누적평균값이 들어갈 크기 9의 배열 선언
	double sum = 0; // 누적된 값이 들어갈 실수형 변수 선언과 초기화
	printf("배열을 입력해주세요 : ");
	scanf_s("%d %d %d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7], &arr[8]); // 9개의 값을 배열에 넣는다.
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) { // 반복문으로 누적평균 값을 Avr에 넣는다.
		sum += arr[i]; // 배열의 값을 sum에 누적시킨다.
		Avr[i] = sum / (i + 1); // i + 1번째 누적평균값은 현재까지 누적된 값을 i + 1 로 나눈 값이다.
	}
	printf("Avr 출력\n");
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) { // 반복문으로 누적평균값을 하나씩 출력한다.
		printf("Avr[%d]: %lf\n", i, Avr[i]);
	}
	return 0;
}
// 시간복잡도: O(N)
/* 슈도코드
원래 값을 저장할 크기 9의 정수형 배열arr 선언
평균 값을 저장할 크기 9의 실수형 배열Avr 선언
원래 값을 하나씩 더해나갈 정수형 변수sum 선언과 초기화
안내문구 출력
원래 값 9개를 입력받음
반복문 시작 (i는 0부터 9까지)
{	sum에 arr[i] 값을 더함
	Avr[i] = sum / i + 1
}
안내문구 출력
반복문 시작 (i는 0부터 9까지)
{
	Avr[i]값 출력
}
*/