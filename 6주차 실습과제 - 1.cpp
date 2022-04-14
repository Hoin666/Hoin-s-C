#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h> // rand()함수를 이용하기위해 전처리
#include<time.h> // rand()함수의 시드값으로 현재 시간값을 넣기 위해 전처리


double interval(double a, double b); // a와 b사이의 실수를 반환하는 함수 선언
int main(void) {
	srand((unsigned)time(NULL)); // rand()함수의 시드값으로 현재 시간값을 넣는다.
	FILE* gp = fopen("square.txt", "w"); // square.txt를 쓰기 형식으로 연다.
	double s, t; // s와 t에 있는 숫자를 tempo1, tempo2에 넣고 txt 파일에 찍어 넣는다.
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
	fclose(gp); // gp를 닫는다.
	FILE* fp = fopen("circle.txt", "w"); // circle.txt를 쓰기 형식으로 연다.
	double x, y; // x와 y에 있는 숫자를 temp1, temp2에 넣고 txt 파일에 찍어 넣는다.
	for (int i = 1; i <= 10000; i++) {
		char temp1[10], temp2[10];
		while (true) {
			x = interval(0.0, 1.0);
			y = interval(0.0, 1.0);
			if ((x - 0.5) * (x - 0.5) + (y - 0.5) * (y - 0.5) < 0.5 * 0.5) { // 중심 0.5 반지름 0.5 원안에 들어가면 txt에 저장한다.
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
double interval(double a, double b) { // 함수 구현부
	double random; // 랜덤한 값이 들어가는 변수
	while (true) {
		random =  rand() + (double)(rand() % 1000) / 1000; // 랜덤한 실수값을 생성
		if (random > a and random < b) { // 그 실수 값이 a와 b사이에 있으면 반복문을 빠져나옴
			break;
		}
	}
	return random;
}