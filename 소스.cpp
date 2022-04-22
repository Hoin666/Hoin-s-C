#include<stdio.h>
void swap(int *A,int  *B){
	int temp = *A;
	*A = *B;
	*B = temp;
}
int main(void) {
	int a = 3, b = 4;
	swap(&a, &b);
	printf("%d  %d", a, b);
	return 0;
}
/*
�ְ���
Q1. 2���� ������ ���� ��ȯ�ϴ� �Լ� �˰����� �����ڵ�� �ۼ��ض�.

A : void swap(*A, *B){
	temp <- *A;
	*A <- *B;
	*B <- temp;
Q2. ���� �ڵ��� �ð� ���⵵��? (�̶� n = 2^t)
 for(int i = 1; i < n; i *= 2){
	printf("Hello");
}

A : �� t���� ������ �̷������ �ݺ����� ����ǹǷ�,
	�ð����⵵ = t = log2 n �̴�.

Q3. O(n^2)�� �ð����⵵�� ������ �˰��򿡼� �Է��� ������ 2�谡 �Ǹ� ����ð��� ��ŭ �����ϴ°�?

A : n = t�϶� t^2 ��ŭ �ð��� �ɸ���
    n = 2t�϶� 4t^2 ��ŭ �ð��� �ɸ��Ƿ� 4�踸ŭ �����Ѵ�.

Q4. int a[10][20]���� �迭�� �����ϴ� �޸� ������ ũ��� ���ΰ�?

A : int�� ������ ũ��� 4byte�̰� ������ 10 x 20 �� �̹Ƿ� 800����Ʈ�̴�.

Q5.

#define max_size 100

typedef struct Stacktype {
	int stack[max_size];
	int top;
}Stacktype;

void Stack_init(Stacktype* s) {
	s->top = -1;
}

void Stack_push(Stacktype* s, int item) {
	s->stack[++(s->top)] = item;
	return;
}

bool is_empty(Stacktype* s) {
	return s->top == -1;
}

int Stack_pop(Stacktype* s) {
	int t = s->stack[s->top];
	s->stack[s->top] = 0;
	s->top--;
	return t;
}

int main(void) {
	int n, temp;
	Stacktype s;
	Stack_init(&s);

	printf("���� �迭�� ũ�� : ");
	scanf_s("%d", &n);
	printf("������ �Է��Ͻÿ� : ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &temp);
		Stack_push(&s, temp);
	}
	printf("������ ���� �迭 : ");
	for (int i = 0; i < n; i++) {
		printf("%d ", Stack_pop(&s));
	}
	return 0;
}
*/