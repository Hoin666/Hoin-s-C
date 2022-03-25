#include<stdio.h>
void func(int* arr, int size);
int main() {
	int arr[100];
	int size = sizeof(arr) / sizeof(int);
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		arr[i] = i;
	}
	func(arr, size);
	return 0;
}
void func(int* arr, int size) {
	double sum = 0;
	double min_Value = 0;
	int cnt = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	min_Value = sum / size;
	for (int i = 0; i < size; i++) {
		if (arr[i] < min_Value) {
			cnt++;
		}
	}
	printf("배열의 원소의 평균값은 %lf입니다.\n", min_Value);
	printf("배열의 원소 중 평균보다 작은 원소는 %d개입니다.", cnt);
}