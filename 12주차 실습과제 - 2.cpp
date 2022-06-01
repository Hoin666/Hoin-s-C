#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int size;
void bubble_sort(int *list, int n) { // (오름차순 버블 정렬)
	int temp;
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (list[j] > list[j + 1]) { // 배열의 변화가 일어날 때 중간 과정 출력
				printf("배열(버블정렬) : ");
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

void insertion_sort(int* list, int n) { // (오름차순 삽입 정렬)
	int i,j,k,key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) { // 배열의 변화가 일어날 때 중간 과정 출력
			printf("배열(삽입정렬) : ");
			list[j + 1] = list[j];
			list[j] = key;
			for (k = 0; k < n; k++) {
				printf("%d ", list[k]);
			}
			printf("\n");
		}
	}
}

int partition(int* list, int left, int right) { // 퀵정렬을 위한 파티션 나누기
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	
	do {
		do {
			low++;
		} while (low <= right && list[low] < pivot); // low와 right가 엇갈리거나 피봇보다 작으면 종료

		do {
			high--;
		} while (high >= left && list[high] > pivot); // low와 right가 엇갈리거나 피봇보다 크면 종료

		if (low < high) { // low와 high값 교환
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

void quick_sort(int* list, int left, int right, int n) { // (오름차순 퀵정렬)
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1, n);
		quick_sort(list, q + 1, right, n);
		printf("배열(퀵정렬) : "); // 배열의 변화가 일어 날 때 프린트
		for (int k = 0; k < n; k++) {
			printf("%d ", list[k]);
		}
		printf("\n");
	}
}

void merge(int* list, int left, int mid, int right) { // 배열을 합병
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

void merge_sort(int* list, int left, int right, int n) { // (오름차순 합병정렬)
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid,n);
		merge_sort(list, mid + 1, right,n);
		merge(list, left, mid, right);
		printf("배열(합병정렬) : "); // 배열의 변화가 일어 날 때 프린트
		for (int k = 0; k < n; k++) {
			printf("%d ", list[k]);
		}
		printf("\n");
	}
}

int main(void) {
	srand(time(NULL));
	
	printf("배열의 사이즈 : ");
	scanf_s("%d", &size);

	int* arr1 = (int*)malloc(sizeof(int) * size); // 배열을 동적할당
	int* arr2 = (int*)malloc(sizeof(int) * size);
	int* arr3 = (int*)malloc(sizeof(int) * size);
	int* arr4 = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) { // 10 미만의 값을 갖는 랜덤한 배열 생성
		arr1[i] = rand() % 10;
		arr4[i] = arr3[i] = arr2[i] = arr1[i];
	}
	printf("배열(원본) : ");
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