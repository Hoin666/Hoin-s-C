#include<stdio.h>
#include<stdlib.h>
int MAX_SIZE;
typedef struct Stack
{
	int* buf = (int*)malloc(sizeof(int) * MAX_SIZE);
	int top = -1;
}element;

bool IsEmpty(Stack* stack) {
	if (stack->top < 0) {
		return true;
	}
	else {
		return false;
	}
}
bool IsFull(Stack* stack) {
	if (stack->top == MAX_SIZE - 1) {
		return true;
	}
	else {
		return false;
	}
}
Stack CreateStack(int max_Size) {
	MAX_SIZE = max_Size;
	Stack stack = {};
	return stack;
}
void Push(Stack* stack, int data) {
	if (IsFull(stack)) {
		return;
	}
	stack->top++;
	stack->buf[stack->top] = data;
}
int Pop(Stack* stack) {
	int temp = -1;
	if (IsEmpty(stack)) {
		return temp;
	}
	temp = stack->buf[stack->top];
	stack->top--;
	return temp;
}
void Show(Stack* stack) {
	for (int i = 0; i <= stack->top; i++) {
		printf("buf[%d] : %d\n", i, stack->buf[i]);
	}
	printf("\n");
}
int main(void) {
	Stack stack = CreateStack(10);
	Push(&stack, 11);
	Show(&stack);
	Push(&stack, 12);
	Show(&stack);
	Push(&stack, 13);
	Show(&stack);
	Pop(&stack);
	Show(&stack);
	free(stack.buf);
}