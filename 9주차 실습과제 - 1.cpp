#include<stdio.h>
#include<stdlib.h> // malloc, free를 쓸 수 있는 header
int MAX_SIZE; // 스택의 배열의 크기
typedef struct Stack // Stack을 구조체로 구현
{
	int* buf = (int*)malloc(sizeof(int) * MAX_SIZE); // 스택의 값 (정수형 변수)이 들어갈 배열을 동적 할당한다.
	int top = -1; // 스택의 탑을 초기화
}element;

bool IsEmpty(Stack* stack) { // 스택이 비어있는지 확인하는 함수
	if (stack->top < 0) { // 스택의 탑이 0보다 작으면
		return true; // true 반환
	}
	else {
		return false; // 아니면 false 반환
	}
}
bool IsFull(Stack* stack) { // 스택이 가득찼는지 확인하는 함수
	if (stack->top == MAX_SIZE - 1) { // 탑이 배열의 크기 - 1과 같으면 스택은 가득찬 것이다.
		return true; // true 반환
	}
	else {
		return false; // 아니면 false 반환
	}
}
Stack CreateStack(int max_Size) { // 스택을 생성하는 함수
	MAX_SIZE = max_Size; // 배열의 크기를 인수로 받아 초기화 한다.
	Stack stack = {};
	return stack;
}
void Push(Stack* stack, int data) { // 스택에 값을 집어 넣는 함수
	if (IsFull(stack)) { // 스택이 가득찼으면 값을 집어 넣을 수가 없다.
		return;
	}
	stack->top++; // 스택의 탑을 하나 증가 시킨 후에
	stack->buf[stack->top] = data; // 해당 탑에 해당하는 배열에 data를 넣는다.
}
int Pop(Stack* stack) { // 스택에 값을 반환하는 함수
	int temp = -1; // 반환 할 정수형 변수
	if (IsEmpty(stack)) { // 스택이 비어있으면 -1을 반환한다.
		return temp;
	}
	temp = stack->buf[stack->top]; // 스택이 비어있지 않으면 temp에 현재 탑에 해당하는 배열의 값을 temp에 넣는다.
	stack->top--; // 스택의 탑을 하나 감소 시킨다.
	return temp;
}
void Show(Stack* stack) { // 스택에 있는 원소를 프린트하는 함수
	for (int i = 0; i <= stack->top; i++) { // 현재 스택의 탑 만큼 배열을 프린트 한다.
		printf("buf[%d] : %d\n", i, stack->buf[i]);
	}
	printf("\n");
}
int main(void) {
	Stack stack = CreateStack(10); // 크기가 10인 스택 생성
	Push(&stack, 11);
	Show(&stack);
	Push(&stack, 12);
	Show(&stack);
	Push(&stack, 13);
	Show(&stack);
	Pop(&stack); // 가장 나중에 넣은 값인 13이 없어진다.
	Show(&stack);
	free(stack.buf);
}