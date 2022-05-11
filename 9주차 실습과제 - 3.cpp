#include<stdio.h>
#include<stdlib.h> // malloc, free�� �� �� �ִ� header
typedef struct list_node* list_pointer; // linked list�� ����Ű�� pointer ����
typedef struct list_node { // linked list ����
	int data;
	list_pointer link;
}Node;
Node* head; // head ������ ����
void init() { // head�� ���� �ʱ�ȭ �����ִ� �Լ�
	head = NULL;
}
void insert(int data) { // data���� �ִ� �Լ�
	Node* ptr; // �߰� �Ǵ� �������� newNode�� �ֱ� ���� ������
	Node* newNode = (Node*)malloc(sizeof(Node)); // ���� ���� newNode�� ���� �Ҵ�
	newNode->data = data; // ������ ���� �ش�.
	newNode->link = NULL; // ��ũ ���� �ʱ�ȭ �Ѵ�.
	if (head == NULL) { // head ������ ��������� head�� newNode�� ����Ų��.
		head = newNode;
	}
	else {
		if (head->data > newNode->data) { // head ������ ������� ������ head�� ����Ű�� ��带 newNode�� ����Ų��.
			newNode->link = head;
			head = newNode;
			return;
		}
		for (ptr = head; ptr->link; ptr = ptr->link) { // �߰��� ��带 �ִ� �κ�, �ش� �ڵ�� newNode�� �߰��� �� ��
			if (ptr->data < newNode->data && ptr->link->data > newNode->data) {
				newNode->link = ptr->link; // newNode�� ptr�� ����Ű�� ��带 ����Ű��,
				ptr->link = newNode; // ptr�� newNode�� ����Ų��.
				return;
			}
		}
		ptr->link = newNode; // �������� ��带 �ִ� �κ�, ptr�� newNode�� ����Ű�� �ȴ�.
	}
}
int del(int data) { // �ش� ���� ����� �Լ�
	Node* cur, * prev; // ������ �ΰ��� ����
	cur = prev = head; // �� �����͸� head�� �ʱ�ȭ

	if (head == NULL) { // head�� �ƹ��͵� ����Ű�� ������ list�� ����ִ�.
		printf("list�� ����ֽ��ϴ�.\n");
		return -1;
	}
	if (head->data == data) { // head�� data�� �Է¹��� data�� ������ �ش� �κ� ����
		head = cur->link;
		cur->link = NULL;
		free(cur);
		return 1;
	}
	for (; cur; cur = cur->link) { // �Է¹��� data�� �߰� �Ǵ� �������� ���� �� �ش� �κ� ����
		if (cur->data == data) {
			prev->link = cur->link;
			cur->link = NULL;
			free(cur);
			return 1;
		}
		prev = cur;
	}
	printf("data�� �����ϴ�.\n"); // �ش��ϴ� data�� list�� ���� ��
	return -1;
}
void print_list(list_pointer head) { // linked list�� data�� ����ϴ� �Լ�
	list_pointer p = head; // head�� �ּҸ� ���� ������p ����

	while (p != NULL) { // p�� ����Ű�� ���� ������ �� ����Ѵ�.
		printf("%d ", p->data);
		p = p->link;
	}printf("\n");
}
bool search(list_pointer head, int num) { // num�� list�� �ִ��� ������ Ȯ���� �ִ� �Լ�
	list_pointer p = head; // head�� �ּҸ� ���� ������ p ����
	while (p) { // p�� ����Ű�� ���� ������ �� �д´�.
		if (p->data = num) { // p�� data�� num�̶� ������ num�� list�� �ִ� ���̴�.
			printf("%d�� list�� �ֽ��ϴ�.\n", num);
			return 0;
		}
	}
	printf("%d�� list�� �����ϴ�.\n", num);
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