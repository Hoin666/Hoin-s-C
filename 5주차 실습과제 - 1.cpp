#define _CRT_SECURE_NO_WARNINGS // scanf�� fopen�� ������ �����ϱ� ���� ���
#include<stdio.h>
int main(void) {
	char buffer[1000] = { 0 ,}; // char �迭�� 0���� �ʱ�ȭ
	char name[100] = {};

	printf("��θ� �Է��ϼ��� : ");
	scanf("%s", name); // name�� ���� ������ �̸��� �Է��Ѵ�.

	FILE* fp = fopen(name, "r"); // fopen���� ������ ����

	fread(buffer, sizeof(buffer), 1, fp); // buffer�� fp�� �ѹ� �����Ѵ�.
	int char_Num = 0; // ���ڼ�(��������)�� ����
	int space_Num = 0; // ���� ���� ��Ÿ���� ����
	int row_Num = 0; // ���� ������ ��Ÿ���� ����
	for (int i = 0; i < sizeof(buffer); i++) { // buffer�� ���Ҹ� for������ �ϳ��� �д´�.
		if (buffer[i] == NULL) { // buffer�� i��° ���Ұ� null�̸� �ڿ� �ٸ� ���ڰ� ���� ����̴�.
			char_Num = i - row_Num; // �ٹٲ�(\n)�� ������ ���ش�.
			break;
		}
		if (buffer[i] == ' ') { // ���� �� üũ
			space_Num++;
		}
		else if (buffer[i] == '\n') { // �ٹٲ� üũ
			row_Num++;
		}
	}
	printf("%s\n", buffer); // ��� �κ�
	printf("���ڼ�(��������) : %d\n", char_Num);
	printf("���ڼ�(��������) : %d\n", char_Num - space_Num);
	printf("�� �� : %d\n", row_Num);
	fclose(fp); // fopen���� �� ������ �ݴ´�.
	return 0;
}