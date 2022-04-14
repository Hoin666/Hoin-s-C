#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h> // rand()�Լ��� �̿��ϱ����� ��ó��
#include<time.h> // rand()�Լ��� �õ尪���� ���� �ð����� �ֱ� ���� ��ó��


double interval(double a, double b); // a�� b������ �Ǽ��� ��ȯ�ϴ� �Լ� ����
int main(void) {
	srand((unsigned)time(NULL)); // rand()�Լ��� �õ尪���� ���� �ð����� �ִ´�.
	FILE* gp = fopen("square.txt", "w"); // square.txt�� ���� �������� ����.
	double s, t; // s�� t�� �ִ� ���ڸ� tempo1, tempo2�� �ְ� txt ���Ͽ� ��� �ִ´�.
	for (int i = 1; i <= 10000; i++){
		char tempo1[10], tempo2[10];
			s = interval(0.0, 1.0);
			t = interval(0.0, 1.0);
			sprintf(tempo1, "%lf", s);
			sprintf(tempo2, "%lf", t);
			fputs(tempo1, gp);
			fputs(" ", gp);
			fputs(tempo2, gp);
			fputs("\n", gp);
	}
	fclose(gp); // gp�� �ݴ´�.
	FILE* fp = fopen("circle.txt", "w"); // circle.txt�� ���� �������� ����.
	double x, y; // x�� y�� �ִ� ���ڸ� temp1, temp2�� �ְ� txt ���Ͽ� ��� �ִ´�.
	for (int i = 1; i <= 10000; i++) {
		char temp1[10], temp2[10];
		while (true) {
			x = interval(0.0, 1.0);
			y = interval(0.0, 1.0);
			if ((x - 0.5) * (x - 0.5) + (y - 0.5) * (y - 0.5) < 0.5 * 0.5) { // �߽� 0.5 ������ 0.5 ���ȿ� ���� txt�� �����Ѵ�.
				sprintf(temp1, "%lf", x);
				sprintf(temp2, "%lf", y);
				fputs(temp1, fp);
				fputs(" ", fp);
				fputs(temp2, fp);
				fputs("\n", fp);
			}
			break;
		}
	}
	fclose(fp);
}
double interval(double a, double b) { // �Լ� ������
	double random; // ������ ���� ���� ����
	while (true) {
		random =  rand() + (double)(rand() % 1000) / 1000; // ������ �Ǽ����� ����
		if (random > a and random < b) { // �� �Ǽ� ���� a�� b���̿� ������ �ݺ����� ��������
			break;
		}
	}
	return random;
}