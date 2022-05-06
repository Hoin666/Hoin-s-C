#include<stdio.h>
#include<stdlib.h>
int MAX_SIZE;
typedef struct C_Queue {
	int rear = -1;
	int front = -1;
	int* buf = (int*)malloc(sizeof(int) * MAX_SIZE);
}element;
bool IsEmpty(C_Queue* queue) {

}
bool IsFull(C_Queue* queue) {

}
C_Queue CreateQ(int max_size) {
	MAX_SIZE = max_size;
	C_Queue queue = {};
	return queue;
}
void AddQ(C_Queue* queue, int data) {

}
int DeleteQ(C_Queue* queue) {

}

int main(void) {

}