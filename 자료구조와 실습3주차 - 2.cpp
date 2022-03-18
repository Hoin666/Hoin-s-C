#include<stdio.h>
int com_mul(int a, int b);
int com_fac(int a, int b);
int main(void) {
    printf("%d\n", com_fac(100, 20));   // a%b == 0 또는 b%a == 0 일 경우의 예제(case1)
    printf("%d\n", com_mul(100, 20));   
    printf("%d\n", com_fac(30, 25));    // case1은 아니면서 1을 제외한 공약수가 있을 때의 예제(case2)
    printf("%d\n", com_mul(30, 25));
    printf("%d\n", com_fac(40, 41));    // 공약수가 1밖에 없을 때의 예제(case3)
    printf("%d\n", com_mul(40, 41));
}
int com_fac(int a, int b) {
    int i, j;
    int cd_num = 0; //공약수의 개수를 저장할 변수
    j = (a < b) ? a : b; //둘중 작은수를 구함
    for (i = 1; i <= j; i++) {
        if (a % i == 0 && b % i == 0)
            cd_num += 1;
    }
    return cd_num;
}
int com_mul(int a, int b)
{
    int i, j;
    int cm; //공배수를 저장할 변수
    int cm_num; // 공배수의 개수를 저장할 변수
    j = (a > b) ? a : b; //둘중 큰수를 구함
    for (i = j;; i++) {
        if (i % a == 0 && i % b == 0) {
            cm = i;
            break;
        }
    }
    cm_num = a * b / cm;
    return cm_num;
}


