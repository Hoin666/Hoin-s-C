#include <stdio.h>
#include<stdlib.h> // �����Ҵ��� �ϱ����� ����
#include<time.h> // ������ �õ尪�� ���� �ð����� �ϱ� ���� ����
#define MAX_VERTICES 50 // ��������� �ִ� ũ��

typedef struct GraphNode { // ��ũ�� ����Ʈ ������ ���
	int vertex; // ����
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType { // ��尡 ����Ǵ� ����Ʈ
	int n; // ������ ����
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

void init(GraphType* g) { // �׷����� �ʱ�ȭ �ϴ� �Լ�
	int v;
	g->n = 0; // �׷����� ������ ������ 0���� �ʱ�ȭ
	for (v = 0; v < MAX_VERTICES; v++) { // ��尡 ����Ǵ� ����Ʈ�� �ʱ�ȭ
		g->adj_list[v] = NULL;
	}
}

void insert_vertex(GraphType* g, int v) { // ������ ������ �ϳ� �ø���.
	if (((g->n) + 1) > MAX_VERTICES) {
		printf(" �׷��� �ִ� ���� ���� �ʰ�!\n");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v) { // u�� v�� �մ� ���� 
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		printf("�׷��� ���� ��ȣ ����!\n");
	}

	node = (GraphNode*)malloc(sizeof(GraphNode));
	node -> vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

void print_adj_list(GraphType* g) { // ���� ����Ʈ�� ����Ʈ
	for (int i = 0; i < g->n; i++) {
		GraphNode* p = g->adj_list[i];
		printf("���� %d�� ���� ����Ʈ ", i);
		while (p != NULL) {
			printf("-> %d", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

int main() {
	int v_num; // ������ ����
	int e_num; // ������ ����(����)
	int height = 6, width = 6; // ��������� ũ��
	int** arr; // �����Ҵ��� �迭
	srand(time(NULL)); // ������ �õ尪�� ���� �ð����� �ٲ�
	arr = (int**)malloc(sizeof(int*) * height); // 2���� �迭�� ���� �Ҵ�
	arr[0] = (int*)malloc(sizeof(int) * width * height);
	for (int i = 1; i < height; i++) {
		arr[i] = arr[i - 1] + width;
	}
	for (int i = 0; i < height; i++) { // diagonal�� 0�� �ְ� �������� �����ϰ� 0�Ǵ� 1�� �迭�� ����
		for (int j = 0; j < width; j++) {
			if (i == j) {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = rand() % 2;
			}
		}
	}
	for (int i = 0; i < height; i++) { // �����ϰ� ������ ����� ���
		for (int j = 0; j < width; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	


	GraphType* g; // (���� �׷���)
	GraphType* h; // (���� �׷���)
	g = (GraphType*)malloc(sizeof(GraphType)); // ���� �׷����� �����Ҵ�
	h = (GraphType*)malloc(sizeof(GraphType)); // ���� �׷����� �����Ҵ�
	init(g); // �׷��� �ʱ�ȭ
	init(h); // �׷��� �ʱ�ȭ
	
	
	v_num = height;

	for (int i = 0; i < v_num; i++) { // �������� �迭�� ũ�⸸ŭ �ø�
		insert_vertex(g, i);
		insert_vertex(h, i);
	}

	for (int i = 0; i < height; i++) { // ��������� ���� 1�̸� i�� j�� �̾��ִ� ���� ����
		for (int j = 0; j < width; j++) {
			if (arr[i][j] == 1) {
				insert_edge(g, i, j);
				insert_edge(h, i, j);
				if (arr[j][i] == 0) { // ������ �׷����� ��� transpose�� ���� 0�̸� �ش簪�� �߰��� ����� ��
					insert_edge(h, j, i);
				}
			}
		}
	}
	printf("<������ �׷���>\n");
	print_adj_list(g);
	printf("\n");
	printf("<������ �׷���>\n");
	print_adj_list(h);
	free(g);
	free(h);

	free(arr[0]);
	free(arr);
	return 0;
	
}