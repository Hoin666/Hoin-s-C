#include<stdio.h>
void func(int* arr, int size); // int�� �迭 arr�� int�� ���� size�� ���� �Լ� ���� 
int main() {
	int arr[100]; // �迭�� ũ�⸦ 100���� �������ش�.
	int size = sizeof(arr) / sizeof(int); // ������ ������ ũ��� 4����Ʈ �̹Ƿ� �迭�� ũ�⸦ ���� ������ ũ��� ������ �迭�� ���� ����� �� �� �ִ�.
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) { // �迭arr�� 0���� 99������ ���ڸ� �ִ´�.
		arr[i] = i;
	}
	func(arr, size); // �Լ� ����
	return 0;
}
void func(int* arr, int size) { // �Լ� ������
	double sum = 0; // arr ������ ���� ���� ����
	double min_Value = 0; // arr ������ ��� ���� ���� ����
	int cnt = 0; // ��պ��� ���� ������ ������ ī��Ʈ�ϴ� ����
	for (int i = 0; i < size; i++) { // for���� ����� sum���ٰ� �迭�� ���� ��� ���� ������.
		sum += arr[i];
	}
	min_Value = sum / size; // ��հ��� ����Ѵ�.
	for (int i = 0; i < size; i++) { // �迭�� ���� ��հ����� �۴ٸ� cnt���� 1 ������Ų��.
		if (arr[i] < min_Value) {
			cnt++;
		}
	}
	printf("�迭�� ������ ��հ��� %lf�Դϴ�.\n", min_Value);
	printf("�迭�� ���� �� ��պ��� ���� ���Ҵ� %d���Դϴ�.", cnt);
}