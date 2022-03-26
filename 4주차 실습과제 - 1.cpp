#include<stdio.h>
void func(int* arr, int size); // int형 배열 arr와 int형 변수 size를 갖는 함수 선언 
int main() {
	int arr[100]; // 배열의 크기를 100으로 지정해준다.
	int size = sizeof(arr) / sizeof(int); // 정수형 변수의 크기는 4바이트 이므로 배열의 크기를 정수 변수의 크기로 나누면 배열의 항이 몇개인지 알 수 있다.
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) { // 배열arr에 0부터 99까지의 숫자를 넣는다.
		arr[i] = i;
	}
	func(arr, size); // 함수 실행
	return 0;
}
void func(int* arr, int size) { // 함수 구현부
	double sum = 0; // arr 원소의 합이 들어가는 변수
	double min_Value = 0; // arr 원소의 평균 값이 들어가는 변수
	int cnt = 0; // 평균보다 작은 원소의 개수를 카운트하는 변수
	for (int i = 0; i < size; i++) { // for문을 사용해 sum에다가 배열의 값을 모두 더해 나간다.
		sum += arr[i];
	}
	min_Value = sum / size; // 평균값을 계산한다.
	for (int i = 0; i < size; i++) { // 배열의 값이 평균값보다 작다면 cnt값을 1 증가시킨다.
		if (arr[i] < min_Value) {
			cnt++;
		}
	}
	printf("배열의 원소의 평균값은 %lf입니다.\n", min_Value);
	printf("배열의 원소 중 평균보다 작은 원소는 %d개입니다.", cnt);
}