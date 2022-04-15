#include<stdio.h>
#include<stdlib.h>
int main() {
	int arr[9];
	double Avr[9];
	double sum = 0;
	printf("배열을 입력해주세요 : ");
	scanf_s("%d %d %d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7], &arr[8]);
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		sum += arr[i];
		Avr[i] = sum / (i + 1);
	}
	printf("Avr 출력\n");
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		printf("Avr[%d]: %lf\n", i, Avr[i]);
	}
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