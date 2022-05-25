#include <stdio.h>
#include<stdlib.h> // 동적할당을 하기위해 삽입
#include<time.h> // 랜덤의 시드값을 현재 시간으로 하기 위해 삽입
#define MAX_VERTICES 50 // 인접행렬의 최대 크기

typedef struct GraphNode { // 링크드 리스트 형태의 노드
	int vertex; // 정점
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType { // 노드가 저장되는 리스트
	int n; // 정점의 개수
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

void init(GraphType* g) { // 그래프를 초기화 하는 함수
	int v;
	g->n = 0; // 그래프의 정점의 개수를 0개로 초기화
	for (v = 0; v < MAX_VERTICES; v++) { // 노드가 저장되는 리스트를 초기화
		g->adj_list[v] = NULL;
	}
}

void insert_vertex(GraphType* g, int v) { // 정점의 개수를 하나 늘린다.
	if (((g->n) + 1) > MAX_VERTICES) {
		printf(" 그래프 최대 정점 개수 초과!\n");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v) { // u와 v를 잇는 간선 
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		printf("그래프 정점 번호 오류!\n");
	}

	node = (GraphNode*)malloc(sizeof(GraphNode));
	node -> vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

void print_adj_list(GraphType* g) { // 인접 리스트를 프린트
	for (int i = 0; i < g->n; i++) {
		GraphNode* p = g->adj_list[i];
		printf("정점 %d의 인접 리스트 ", i);
		while (p != NULL) {
			printf("-> %d", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

int main() {
	int v_num; // 정점의 개수
	int e_num; // 간선의 개수(유향)
	int height = 6, width = 6; // 인접행렬의 크기
	int** arr; // 동적할당할 배열
	srand(time(NULL)); // 랜덤의 시드값을 현재 시간으로 바꿈
	arr = (int**)malloc(sizeof(int*) * height); // 2차원 배열을 동적 할당
	arr[0] = (int*)malloc(sizeof(int) * width * height);
	for (int i = 1; i < height; i++) {
		arr[i] = arr[i - 1] + width;
	}
	for (int i = 0; i < height; i++) { // diagonal에 0을 넣고 나머지는 랜덤하게 0또는 1인 배열을 생성
		for (int j = 0; j < width; j++) {
			if (i == j) {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = rand() % 2;
			}
		}
	}
	for (int i = 0; i < height; i++) { // 랜덤하게 생성된 행렬을 출력
		for (int j = 0; j < width; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	


	GraphType* g; // (유향 그래프)
	GraphType* h; // (무향 그래프)
	g = (GraphType*)malloc(sizeof(GraphType)); // 유향 그래프를 동적할당
	h = (GraphType*)malloc(sizeof(GraphType)); // 유향 그래프를 동적할당
	init(g); // 그래프 초기화
	init(h); // 그래프 초기화
	
	
	v_num = height;

	for (int i = 0; i < v_num; i++) { // 정점들을 배열의 크기만큼 늘림
		insert_vertex(g, i);
		insert_vertex(h, i);
	}

	for (int i = 0; i < height; i++) { // 인접행렬의 값이 1이면 i와 j를 이어주는 간선 생성
		for (int j = 0; j < width; j++) {
			if (arr[i][j] == 1) {
				insert_edge(g, i, j);
				insert_edge(h, i, j);
				if (arr[j][i] == 0) { // 무방향 그래프의 경우 transpose의 값이 0이면 해당값도 추가를 해줘야 됨
					insert_edge(h, j, i);
				}
			}
		}
	}
	printf("<유방향 그래프>\n");
	print_adj_list(g);
	printf("\n");
	printf("<무방향 그래프>\n");
	print_adj_list(h);
	free(g);
	free(h);

	free(arr[0]);
	free(arr);
	return 0;
	
}