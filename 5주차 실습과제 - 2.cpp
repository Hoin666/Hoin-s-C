#define _CRT_SECURE_NO_WARNINGS // scanf와 fopen의 오류를 방지하기 위해 사용
#include<stdio.h>
#include<conio.h> // getche함수를 사용하기 위해 전처리
int main(void) {
	char buffer[100] = { 0, }; // char배열 초기화
	char name[100] = {}; 
	int char_Num = 0; // 문자 개수를 나타내는 변수
	char ch; // 키보드 입력값을 받는 변수
	printf("메세지를 입력하세요 : ");
	scanf("%[^\n]s", name); // %[^\n] 엔터키를 제외한 값을 입력받을 수 있음 (공백 입력 가능)
	FILE* fp = fopen("hello.txt", "w"); // fopen으로 쓰기 형식으로 hello.txt를 연다.
	fputs(name, fp); // fp에 입력한 메세지를 넣는다.
	fclose(fp); // fp를 닫는다.
	FILE* fp2 = fopen("hello.txt", "r"); // fopen으로 읽기 형식으로 hello.txt를 연다.
	fread(buffer, sizeof(buffer), 1, fp2); // buffer에 fp2의 내용을 한번 복사한다.
	for (int i = 0; i < sizeof(buffer); i++) { // buffer의 원소를 for문으로 하나씩 읽는다.
		if (buffer[i] == NULL) { // buffer의 i번째 원소가 null이면 뒤에 다른 문자가 없는 경우이다.
			char_Num = i;
			break;
		}
	}
	for (int i = 0; i < char_Num; i++) { // 문자 개수만큼 돌아가는 forans
		ch = _getche(); // 변수에 키보드 입력값을 넣는다.
		while (true) {
			if (buffer[i] != ch) { // 입력값과 버퍼의 값이 다르면 소리 출력
				printf("\a");
			}
			else { // 맞으면 다음 문자로 넘어간다.
				break;
			}
			ch = _getche();
		}
	}
	fclose(fp2); // fp2를 닫는다.
}