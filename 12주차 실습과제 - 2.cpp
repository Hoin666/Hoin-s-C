#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int size;
void bubble_sort(int *list, int n) { // (�������� ���� ����)
	int temp;
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (list[j] > list[j + 1]) { // �迭�� ��ȭ�� �Ͼ �� �߰� ���� ���
				printf("�迭(��������) : ");
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
				for (int k = 0; k < n; k++) {
					printf("%d ", list[k]);
				}
				printf("\n");
			}
		}
	}
}

void insertion_sort(int* list, int n) { // (�������� ���� ����)
	int i,j,k,key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) { // �迭�� ��ȭ�� �Ͼ �� �߰� ���� ���
			printf("�迭(��������) : ");
			list[j + 1] = list[j];
			list[j] = key;
			for (k = 0; k < n; k++) {
				printf("%d ", list[k]);
			}
			printf("\n");
		}
	}
}

int partition(int* list, int left, int right) { // �������� ���� ��Ƽ�� ������
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	
	do {
		do {
			low++;
		} while (low <= right && list[low] < pivot); // low�� right�� �������ų� �Ǻ����� ������ ����

		do {
			high--;
		} while (high >= left && list[high] > pivot); // low�� right�� �������ų� �Ǻ����� ũ�� ����

		if (low < high) { // low�� high�� ��ȯ
			temp = list[low];
			list[low] = list[high];
			list[high] = temp;
		}
	} while (low < high);

	temp = list[left];
	list[left] = list[high];
	list[high] = temp;

	return high;
}

void quick_sort(int* list, int left, int right, int n) { // (�������� ������)
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1, n);
		quick_sort(list, q + 1, right, n);
		printf("�迭(������) : "); // �迭�� ��ȭ�� �Ͼ� �� �� ����Ʈ
		for (int k = 0; k < n; k++) {
			printf("%d ", list[k]);
		}
		printf("\n");
	}
}

void merge(int* list, int left, int mid, int right) { // �迭�� �պ�
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;
	int* sorted = (int*)malloc(sizeof(int) * size);
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) {
			sorted[k++] = list[i++];
		}
		else {
			sorted[k++] = list[j++];
		}
	}

	if (i > mid) {
		for (l = j; l <= right; l++) {
			sorted[k++] = list[l];
		}
	}
	else {
		for (l = i; l <= mid; l++) {
			sorted[k++] = list[l];
		}
	}
	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
	}
}

void merge_sort(int* list, int left, int right, int n) { // (�������� �պ�����)
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid,n);
		merge_sort(list, mid + 1, right,n);
		merge(list, left, mid, right);
		printf("�迭(�պ�����) : "); // �迭�� ��ȭ�� �Ͼ� �� �� ����Ʈ
		for (int k = 0; k < n; k++) {
			printf("%d ", list[k]);
		}
		printf("\n");
	}
}

int main(void) {
	srand(time(NULL));
	
	printf("�迭�� ������ : ");
	scanf_s("%d", &size);

	int* arr1 = (int*)malloc(sizeof(int) * size); // �迭�� �����Ҵ�
	int* arr2 = (int*)malloc(sizeof(int) * size);
	int* arr3 = (int*)malloc(sizeof(int) * size);
	int* arr4 = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) { // 10 �̸��� ���� ���� ������ �迭 ����
		arr1[i] = rand() % 10;
		arr4[i] = arr3[i] = arr2[i] = arr1[i];
	}
	printf("�迭(����) : ");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");

	bubble_sort(arr1, size);
	printf("\n");
	insertion_sort(arr2, size);
	printf("\n");
	quick_sort(arr3, 0, size - 1, size);
	printf("\n");
	merge_sort(arr4, 0, size - 1, size);
	
}