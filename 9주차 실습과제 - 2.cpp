#include<stdio.h>
#include<stdlib.h> // malloc, free를 쓸 수 있는 header
int MAX_SIZE; // 순환큐 배열의 크기
typedef struct C_Queue { // 순환큐를 구조체로 구현
	int rear = -1; // rear값 초기화
	int front = -1; // front값 초기화
	int* buf = (int*)malloc(sizeof(int) * MAX_SIZE); // 순환큐의 배열을 동적 할당
}element;
bool IsEmpty(C_Queue* queue) { // 순환큐가 비었는지 확인하는 함수
	if (queue->front == queue->rear) { // front와 rear가 같으면 큐는 비어있다.
		return true;
	}
	else {
		return false;
	}
} 
bool IsFull(C_Queue* queue) { // 순환큐가 가득찼는지 확인하는 함수
	if (((queue->rear + 1) % MAX_SIZE) == queue->front) { // front가 rear보다 앞에 있으면 큐는 가득차있다.(순환큐이기에 MAX_SIZE로 나눈다)
		return true;
	}
	else return false;

}
C_Queue CreateQ(int max_size) { // 순환큐를 생성하는 함수
	MAX_SIZE = max_size; // 순환큐의 배열의 크기를 초기화한다.
	C_Queue queue = {};
	return queue;
}
void AddQ(C_Queue* queue, int data) { // 순환큐에 값을 넣는 함수
	if (IsFull(queue)) { // 순환큐가 가득찼다면 값을 넣을 수 없다.
		return;
	}
	queue->rear = (queue->rear + 1) % (MAX_SIZE); // rear값을 1증가시킨다음에
	queue->buf[queue->rear] = data; // 해당하는 배열에 data를 넣는다.
}
int DeleteQ(C_Queue* queue) { // 순환큐의 값을 반환하는 함수
	int temp = -1; // 반환할 정수형 변수
	if (IsEmpty(queue)) { // 순환큐가 비어있다면 -1을 반환한다.
		return temp;
	}
	queue->front = (queue->front + 1) % MAX_SIZE; // 순환큐의 front값을 1증가시킨 후에
	return queue->buf[queue->front]; // 해당하는 배열의 값을 반환한다.
}
void Show(C_Queue* queue) { // 순환큐의 배열의 값을 출력하는 함수
	for (int i = queue-> front + 1; i <= queue->rear; i++) { // front + 1에서 rear까지의 값을 출력한다.
		printf("buf[%d] : %d\n", i, queue->buf[i]);
	}
	printf("\n");
}

int main(void) {
	C_Queue cq = CreateQ(10); // 크기가 10인 순환큐 생성
	AddQ(&cq, 11);
	Show(&cq);
	AddQ(&cq, 12);
	Show(&cq);
	AddQ(&cq, 13);
	Show(&cq);
	DeleteQ(&cq); // 가장 처음 넣은 값인 11이 없어진다.
	Show(&cq);

}