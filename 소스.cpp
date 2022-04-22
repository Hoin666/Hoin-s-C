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
주관식
Q1. 2개의 정수를 서로 교환하는 함수 알고리즘을 슈도코드로 작성해라.

A : void swap(*A, *B){
	temp <- *A;
	*A <- *B;
	*B <- temp;
Q2. 다음 코드의 시간 복잡도는? (이때 n = 2^t)
 for(int i = 1; i < n; i *= 2){
	printf("Hello");
}

A : 총 t번의 연산이 이루어지고 반복문이 종료되므로,
	시간복잡도 = t = log2 n 이다.

Q3. O(n^2)의 시간복잡도를 가지는 알고리즘에서 입력의 개수가 2배가 되면 실행시간은 얼만큼 증가하는가?

A : n = t일때 t^2 만큼 시간이 걸리고
    n = 2t일때 4t^2 만큼 시간이 걸리므로 4배만큼 증가한다.

Q4. int a[10][20]에서 배열이 차지하는 메모리 공간의 크기는 얼마인가?

A : int형 변수의 크기는 4byte이고 개수가 10 x 20 개 이므로 800바이트이다.

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

	printf("정수 배열의 크기 : ");
	scanf_s("%d", &n);
	printf("정수를 입력하시오 : ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &temp);
		Stack_push(&s, temp);
	}
	printf("반전된 정수 배열 : ");
	for (int i = 0; i < n; i++) {
		printf("%d ", Stack_pop(&s));
	}
	return 0;
}
*/