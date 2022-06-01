#include<stdio.h>
int number = 6; // 정점의 개수
int INF = 1000000000; // 무한

int a[6][6] = {
	{0, INF, 25, 15, INF, INF},
	{15, 0, INF, INF, 10, INF},
	{10, 50, 0, INF, 65, INF},
	{INF, 20, INF, 0, 35, INF},
	{INF, INF, INF, 30, 0, INF},
	{INF, INF, INF, 3, INF, INF}
};
bool v[6]; // 방문한 노드
int d[6]; // 최단 거리

int getSmallIndex() { // 가장 최소 거리를 갖는 정점을 반환
	int min = INF;
	int index = 0;
	for (int i = 0; i < number; i++) {
		if (d[i] < min && !v[i]) { // 방문을 안하고 거리가 최소인 것으로 min값 변경
			min = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) { // 다익스트라
	for (int i = 0; i < number; i++) {
		d[i] = a[start][i]; // start정점의 모든 경로의 비용을 담는다.
	}
	v[start] = true; // 방문
	for (int i = 0; i < number - 2; i++) {
		int current = getSmallIndex(); // 가장 가까운 노드
		v[current] = true;
		for (int j = 0; j < 6; j++) {
			if (!v[j]) {
				if (d[current] + a[current][j] < d[j]) { // 작은 것을 저장한다.
					d[j] = d[current] + a[current][j];
				}
			}
		}
	}
}
int main(void) {
	
	for (int i = 0; i < number; i++) {
		dijkstra(i);
		printf("%d번째 정점 : ", i);
		for (int j = 0; j < number; j++) {
			printf("%d ", d[j]);
		}
		printf("\n");
	}
}