#include<stdio.h>
#include<stdlib.h> // malloc, free를 쓸 수 있는 header
typedef struct list_node* list_pointer; // linked list를 가르키는 pointer 선언
typedef struct list_node { // linked list 구현
	int data;
	list_pointer link;
}Node;
Node* head; // head 포인터 선언
void init() { // head의 값을 초기화 시켜주는 함수
	head = NULL;
}
void insert(int data) { // data값을 넣는 함수
	Node* ptr; // 중간 또는 마지막에 newNode를 넣기 위한 포인터
	Node* newNode = (Node*)malloc(sizeof(Node)); // 새로 넣을 newNode를 동적 할당
	newNode->data = data; // 데이터 값을 준다.
	newNode->link = NULL; // 링크 값을 초기화 한다.
	if (head == NULL) { // head 다음이 비어있으면 head는 newNode를 가르킨다.
		head = newNode;
	}
	else {
		if (head->data > newNode->data) { // head 다음이 비어있지 않으면 head가 가르키는 노드를 newNode가 가르킨다.
			newNode->link = head;
			head = newNode;
			return;
		}
		for (ptr = head; ptr->link; ptr = ptr->link) { // 중간에 노드를 넣는 부분, 해당 코드는 newNode가 중간에 들어갈 때
			if (ptr->data < newNode->data && ptr->link->data > newNode->data) {
				newNode->link = ptr->link; // newNode는 ptr가 가르키는 노드를 가르키고,
				ptr->link = newNode; // ptr는 newNode를 가르킨다.
				return;
			}
		}
		ptr->link = newNode; // 마지막에 노드를 넣는 부분, ptr가 newNode를 가르키면 된다.
	}
}
int del(int data) { // 해당 값을 지우는 함수
	Node* cur, * prev; // 포인터 두개를 생성
	cur = prev = head; // 두 포인터를 head로 초기화

	if (head == NULL) { // head가 아무것도 가르키지 않으면 list는 비어있다.
		printf("list가 비어있습니다.\n");
		return -1;
	}
	if (head->data == data) { // head의 data가 입력받은 data랑 같으면 해당 부분 삭제
		head = cur->link;
		cur->link = NULL;
		free(cur);
		return 1;
	}
	for (; cur; cur = cur->link) { // 입력받은 data가 중간 또는 마지막에 있을 때 해당 부분 삭제
		if (cur->data == data) {
			prev->link = cur->link;
			cur->link = NULL;
			free(cur);
			return 1;
		}
		prev = cur;
	}
	printf("data가 없습니다.\n"); // 해당하는 data가 list에 없을 때
	return -1;
}
void print_list(list_pointer head) { // linked list의 data를 출력하는 함수
	list_pointer p = head; // head의 주소를 갖는 포인터p 선언

	while (p != NULL) { // p가 가르키는 것이 있으면 쭉 출력한다.
		printf("%d ", p->data);
		p = p->link;
	}printf("\n");
}
bool search(list_pointer head, int num) { // num이 list에 있는지 없는지 확인해 주는 함수
	list_pointer p = head; // head의 주소를 갖는 포인터 p 선언
	while (p) { // p가 가르키는 것이 있으면 쭉 읽는다.
		if (p->data = num) { // p의 data가 num이랑 같으면 num이 list에 있는 것이다.
			printf("%d는 list에 있습니다.\n", num);
			return 0;
		}
	}
	printf("%d는 list에 없습니다.\n", num);
	return 0;
}
int main() {
	init();
	insert(10);
	insert(20);
	print_list(head);
	del(30);
	del(10);
	print_list(head);
	search(head, 10);
	search(head, 20);
}