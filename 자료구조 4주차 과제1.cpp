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
	printf("�迭�� ������ ��հ��� %lf�Դϴ�.\n", min_Value);
	printf("�迭�� ���� �� ��պ��� ���� ���Ҵ� %d���Դϴ�.", cnt);
}