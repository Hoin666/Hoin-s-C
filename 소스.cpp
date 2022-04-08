#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


double interval(double a, double b);
int main(void) {
	srand((unsigned)time(NULL));
	char buffer[1000] = { 0 , };
	FILE* fp = fopen("circle.txt", "w");
	double x, y;
	for (int i = 1; i <= 100; i++){
		char temp1[10], temp2[10];
		x = interval(0.0, 1.0);
		y = interval(0.0, 1.0);
		sprintf(temp1, "%lf", x);
		sprintf(temp2, "%lf", y);
		fputs(temp1, fp);
		fputs(" ", fp);
		fputs(temp2, fp);
		fputs("\n", fp);
		
	}
	fclose(fp);
}
double interval(double a, double b) {
	double random;
	while (true) {
		random =a + (double)(rand()%1000) / 1000;
		if (random > a and random < b) {
			break;
		}
	}
	return random;
}