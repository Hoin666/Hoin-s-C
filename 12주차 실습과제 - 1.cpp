#include<stdio.h>
int number = 6; // ������ ����
int INF = 1000000000; // ����

int a[6][6] = {
	{0, INF, 25, 15, INF, INF},
	{15, 0, INF, INF, 10, INF},
	{10, 50, 0, INF, 65, INF},
	{INF, 20, INF, 0, 35, INF},
	{INF, INF, INF, 30, 0, INF},
	{INF, INF, INF, 3, INF, INF}
};
bool v[6]; // �湮�� ���
int d[6]; // �ִ� �Ÿ�

int getSmallIndex() { // ���� �ּ� �Ÿ��� ���� ������ ��ȯ
	int min = INF;
	int index = 0;
	for (int i = 0; i < number; i++) {
		if (d[i] < min && !v[i]) { // �湮�� ���ϰ� �Ÿ��� �ּ��� ������ min�� ����
			min = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) { // ���ͽ�Ʈ��
	for (int i = 0; i < number; i++) {
		d[i] = a[start][i]; // start������ ��� ����� ����� ��´�.
	}
	v[start] = true; // �湮
	for (int i = 0; i < number - 2; i++) {
		int current = getSmallIndex(); // ���� ����� ���
		v[current] = true;
		for (int j = 0; j < 6; j++) {
			if (!v[j]) {
				if (d[current] + a[current][j] < d[j]) { // ���� ���� �����Ѵ�.
					d[j] = d[current] + a[current][j];
				}
			}
		}
	}
}
int main(void) {
	
	for (int i = 0; i < number; i++) {
		dijkstra(i);
		printf("%d��° ���� : ", i);
		for (int j = 0; j < number; j++) {
			printf("%d ", d[j]);
		}
		printf("\n");
	}
}