#include<stdio.h>
#include<stdlib.h> // malloc, free�� �� �� �ִ� header
int MAX_SIZE; // ��ȯť �迭�� ũ��
typedef struct C_Queue { // ��ȯť�� ����ü�� ����
	int rear = -1; // rear�� �ʱ�ȭ
	int front = -1; // front�� �ʱ�ȭ
	int* buf = (int*)malloc(sizeof(int) * MAX_SIZE); // ��ȯť�� �迭�� ���� �Ҵ�
}element;
bool IsEmpty(C_Queue* queue) { // ��ȯť�� ������� Ȯ���ϴ� �Լ�
	if (queue->front == queue->rear) { // front�� rear�� ������ ť�� ����ִ�.
		return true;
	}
	else {
		return false;
	}
} 
bool IsFull(C_Queue* queue) { // ��ȯť�� ����á���� Ȯ���ϴ� �Լ�
	if (((queue->rear + 1) % MAX_SIZE) == queue->front) { // front�� rear���� �տ� ������ ť�� �������ִ�.(��ȯť�̱⿡ MAX_SIZE�� ������)
		return true;
	}
	else return false;

}
C_Queue CreateQ(int max_size) { // ��ȯť�� �����ϴ� �Լ�
	MAX_SIZE = max_size; // ��ȯť�� �迭�� ũ�⸦ �ʱ�ȭ�Ѵ�.
	C_Queue queue = {};
	return queue;
}
void AddQ(C_Queue* queue, int data) { // ��ȯť�� ���� �ִ� �Լ�
	if (IsFull(queue)) { // ��ȯť�� ����á�ٸ� ���� ���� �� ����.
		return;
	}
	queue->rear = (queue->rear + 1) % (MAX_SIZE); // rear���� 1������Ų������
	queue->buf[queue->rear] = data; // �ش��ϴ� �迭�� data�� �ִ´�.
}
int DeleteQ(C_Queue* queue) { // ��ȯť�� ���� ��ȯ�ϴ� �Լ�
	int temp = -1; // ��ȯ�� ������ ����
	if (IsEmpty(queue)) { // ��ȯť�� ����ִٸ� -1�� ��ȯ�Ѵ�.
		return temp;
	}
	queue->front = (queue->front + 1) % MAX_SIZE; // ��ȯť�� front���� 1������Ų �Ŀ�
	return queue->buf[queue->front]; // �ش��ϴ� �迭�� ���� ��ȯ�Ѵ�.
}
void Show(C_Queue* queue) { // ��ȯť�� �迭�� ���� ����ϴ� �Լ�
	for (int i = queue-> front + 1; i <= queue->rear; i++) { // front + 1���� rear������ ���� ����Ѵ�.
		printf("buf[%d] : %d\n", i, queue->buf[i]);
	}
	printf("\n");
}

int main(void) {
	C_Queue cq = CreateQ(10); // ũ�Ⱑ 10�� ��ȯť ����
	AddQ(&cq, 11);
	Show(&cq);
	AddQ(&cq, 12);
	Show(&cq);
	AddQ(&cq, 13);
	Show(&cq);
	DeleteQ(&cq); // ���� ó�� ���� ���� 11�� ��������.
	Show(&cq);

}