#include<stdio.h>
#include<stdlib.h> // malloc, free�� �� �� �ִ� header
int MAX_SIZE; // ������ �迭�� ũ��
typedef struct Stack // Stack�� ����ü�� ����
{
	int* buf = (int*)malloc(sizeof(int) * MAX_SIZE); // ������ �� (������ ����)�� �� �迭�� ���� �Ҵ��Ѵ�.
	int top = -1; // ������ ž�� �ʱ�ȭ
}element;

bool IsEmpty(Stack* stack) { // ������ ����ִ��� Ȯ���ϴ� �Լ�
	if (stack->top < 0) { // ������ ž�� 0���� ������
		return true; // true ��ȯ
	}
	else {
		return false; // �ƴϸ� false ��ȯ
	}
}
bool IsFull(Stack* stack) { // ������ ����á���� Ȯ���ϴ� �Լ�
	if (stack->top == MAX_SIZE - 1) { // ž�� �迭�� ũ�� - 1�� ������ ������ ������ ���̴�.
		return true; // true ��ȯ
	}
	else {
		return false; // �ƴϸ� false ��ȯ
	}
}
Stack CreateStack(int max_Size) { // ������ �����ϴ� �Լ�
	MAX_SIZE = max_Size; // �迭�� ũ�⸦ �μ��� �޾� �ʱ�ȭ �Ѵ�.
	Stack stack = {};
	return stack;
}
void Push(Stack* stack, int data) { // ���ÿ� ���� ���� �ִ� �Լ�
	if (IsFull(stack)) { // ������ ����á���� ���� ���� ���� ���� ����.
		return;
	}
	stack->top++; // ������ ž�� �ϳ� ���� ��Ų �Ŀ�
	stack->buf[stack->top] = data; // �ش� ž�� �ش��ϴ� �迭�� data�� �ִ´�.
}
int Pop(Stack* stack) { // ���ÿ� ���� ��ȯ�ϴ� �Լ�
	int temp = -1; // ��ȯ �� ������ ����
	if (IsEmpty(stack)) { // ������ ��������� -1�� ��ȯ�Ѵ�.
		return temp;
	}
	temp = stack->buf[stack->top]; // ������ ������� ������ temp�� ���� ž�� �ش��ϴ� �迭�� ���� temp�� �ִ´�.
	stack->top--; // ������ ž�� �ϳ� ���� ��Ų��.
	return temp;
}
void Show(Stack* stack) { // ���ÿ� �ִ� ���Ҹ� ����Ʈ�ϴ� �Լ�
	for (int i = 0; i <= stack->top; i++) { // ���� ������ ž ��ŭ �迭�� ����Ʈ �Ѵ�.
		printf("buf[%d] : %d\n", i, stack->buf[i]);
	}
	printf("\n");
}
int main(void) {
	Stack stack = CreateStack(10); // ũ�Ⱑ 10�� ���� ����
	Push(&stack, 11);
	Show(&stack);
	Push(&stack, 12);
	Show(&stack);
	Push(&stack, 13);
	Show(&stack);
	Pop(&stack); // ���� ���߿� ���� ���� 13�� ��������.
	Show(&stack);
	free(stack.buf);
}