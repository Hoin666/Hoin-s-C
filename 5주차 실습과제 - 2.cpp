#define _CRT_SECURE_NO_WARNINGS // scanf�� fopen�� ������ �����ϱ� ���� ���
#include<stdio.h>
#include<conio.h> // getche�Լ��� ����ϱ� ���� ��ó��
int main(void) {
	char buffer[100] = { 0, }; // char�迭 �ʱ�ȭ
	char name[100] = {}; 
	int char_Num = 0; // ���� ������ ��Ÿ���� ����
	char ch; // Ű���� �Է°��� �޴� ����
	printf("�޼����� �Է��ϼ��� : ");
	scanf("%[^\n]s", name); // %[^\n] ����Ű�� ������ ���� �Է¹��� �� ���� (���� �Է� ����)
	FILE* fp = fopen("hello.txt", "w"); // fopen���� ���� �������� hello.txt�� ����.
	fputs(name, fp); // fp�� �Է��� �޼����� �ִ´�.
	fclose(fp); // fp�� �ݴ´�.
	FILE* fp2 = fopen("hello.txt", "r"); // fopen���� �б� �������� hello.txt�� ����.
	fread(buffer, sizeof(buffer), 1, fp2); // buffer�� fp2�� ������ �ѹ� �����Ѵ�.
	for (int i = 0; i < sizeof(buffer); i++) { // buffer�� ���Ҹ� for������ �ϳ��� �д´�.
		if (buffer[i] == NULL) { // buffer�� i��° ���Ұ� null�̸� �ڿ� �ٸ� ���ڰ� ���� ����̴�.
			char_Num = i;
			break;
		}
	}
	for (int i = 0; i < char_Num; i++) { // ���� ������ŭ ���ư��� forans
		ch = _getche(); // ������ Ű���� �Է°��� �ִ´�.
		while (true) {
			if (buffer[i] != ch) { // �Է°��� ������ ���� �ٸ��� �Ҹ� ���
				printf("\a");
			}
			else { // ������ ���� ���ڷ� �Ѿ��.
				break;
			}
			ch = _getche();
		}
	}
	fclose(fp2); // fp2�� �ݴ´�.
}