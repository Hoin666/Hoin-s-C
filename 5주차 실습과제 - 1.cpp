#define _CRT_SECURE_NO_WARNINGS // scanf와 fopen의 오류를 방지하기 위해 사용
#include<stdio.h>
int main(void) {
	char buffer[1000] = { 0 ,}; // char 배열을 0으로 초기화
	char name[100] = {};

	printf("경로를 입력하세요 : ");
	scanf("%s", name); // name에 읽을 파일의 이름을 입력한다.

	FILE* fp = fopen(name, "r"); // fopen으로 파일을 연다

	fread(buffer, sizeof(buffer), 1, fp); // buffer에 fp를 한번 복사한다.
	int char_Num = 0; // 문자수(공백포함)의 변수
	int space_Num = 0; // 공백 수를 나타내는 변수
	int row_Num = 0; // 줄의 개수를 나타내는 변수
	for (int i = 0; i < sizeof(buffer); i++) { // buffer의 원소를 for문으로 하나씩 읽는다.
		if (buffer[i] == NULL) { // buffer의 i번째 원소가 null이면 뒤에 다른 문자가 없는 경우이다.
			char_Num = i - row_Num; // 줄바꿈(\n)의 개수를 빼준다.
			break;
		}
		if (buffer[i] == ' ') { // 공백 수 체크
			space_Num++;
		}
		else if (buffer[i] == '\n') { // 줄바꿈 체크
			row_Num++;
		}
	}
	printf("%s\n", buffer); // 출력 부분
	printf("문자수(공백포함) : %d\n", char_Num);
	printf("문자수(공백제외) : %d\n", char_Num - space_Num);
	printf("줄 수 : %d\n", row_Num);
	fclose(fp); // fopen으로 연 파일을 닫는다.
	return 0;
}