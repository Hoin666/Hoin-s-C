#include<stdio.h>
int com_mul(int a, int b);
int com_fac(int a, int b);
int main(void) {
    printf("%d\n", com_fac(100, 20));   // a%b == 0 �Ǵ� b%a == 0 �� ����� ����(case1)
    printf("%d\n", com_mul(100, 20));   
    printf("%d\n", com_fac(30, 25));    // case1�� �ƴϸ鼭 1�� ������ ������� ���� ���� ����(case2)
    printf("%d\n", com_mul(30, 25));
    printf("%d\n", com_fac(40, 41));    // ������� 1�ۿ� ���� ���� ����(case3)
    printf("%d\n", com_mul(40, 41));
}
int com_fac(int a, int b) {
    int i, j;
    int cd_num = 0; //������� ������ ������ ����
    j = (a < b) ? a : b; //���� �������� ����
    for (i = 1; i <= j; i++) {
        if (a % i == 0 && b % i == 0)
            cd_num += 1;
    }
    return cd_num;
}
int com_mul(int a, int b)
{
    int i, j;
    int cm; //������� ������ ����
    int cm_num; // ������� ������ ������ ����
    j = (a > b) ? a : b; //���� ū���� ����
    for (i = j;; i++) {
        if (i % a == 0 && i % b == 0) {
            cm = i;
            break;
        }
    }
    cm_num = a * b / cm;
    return cm_num;
}


