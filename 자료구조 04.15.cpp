#include<stdio.h>
#include<stdlib.h>
int main() {
	int arr[9];
	double Avr[9];
	double sum = 0;
	printf("�迭�� �Է����ּ��� : ");
	scanf_s("%d %d %d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7], &arr[8]);
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		sum += arr[i];
		Avr[i] = sum / (i + 1);
	}
	printf("Avr ���\n");
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		printf("Avr[%d]: %lf\n", i, Avr[i]);
	}
}
// �ð����⵵: O(N)
/* �����ڵ�
���� ���� ������ ũ�� 9�� ������ �迭arr ����
��� ���� ������ ũ�� 9�� �Ǽ��� �迭Avr ����
���� ���� �ϳ��� ���س��� ������ ����sum ����� �ʱ�ȭ
�ȳ����� ���
���� �� 9���� �Է¹���
�ݺ��� ���� (i�� 0���� 9����)
{	sum�� arr[i] ���� ����
	Avr[i] = sum / i + 1
}
�ȳ����� ���
�ݺ��� ���� (i�� 0���� 9����)
{
	Avr[i]�� ���
}

*/