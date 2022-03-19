#include<stdio.h>
int com_mul(int a, int b); // a와 b의 공배수의 개수를 반환하는 함수 선언
int com_fac(int a, int b); // a와 b의 공약수의 개수를 반환하는 함수 선언
int main(void) {
    printf("100과 20의 공약수의 개수는 %d개 입니다.\n", com_fac(100, 20)); // a%b == 0 또는 b%a == 0 일 경우의 예제(case1)
    printf("100과 20의 공배수의 개수는 %d개 입니다.\n", com_mul(100, 20));
    printf("30과 25의 공약수의 개수는 %d개 입니다.\n", com_fac(30, 25)); // case1은 아니면서 1을 제외한 공약수가 있을 때의 예제(case2)
    printf("30과 25의 공배수의 개수는 %d개 입니다.\n", com_mul(30, 25));
    printf("40과 41의 공약수의 개수는 %d개 입니다.\n", com_fac(40, 41)); // a와b가 서로소일 때의 예제(case3)
    printf("40과 41의 공배수의 개수는 %d개 입니다.\n", com_mul(40, 41));
}
int com_fac(int a, int b) { // 함수 구현
    int i, j; // 변수 i, j선언
    int cd_num = 0; // 공약수의 개수를 저장할 변수
    j = (a < b) ? a : b; // a와 b중 작은 수를 j에 넣는다.
    for (i = 1; i <= j; i++) { // i를 1부터 j까지 돌려서 a와 b가 동시에 i로 나누어 떨어지면 그 i는 a, b의 공약수이다.
        if (a % i == 0 && b % i == 0)
            cd_num += 1; // 공약수의 개수를 하나씩 더해나감
    }
    return cd_num; // 공약수의 개수를 반환한다.
}
int com_mul(int a, int b) // 함수 구현
{
    int i, j; // 변수 i, j선언
    int cm; //공배수를 저장할 변수
    int cm_num; // 공배수의 개수를 저장할 변수
    j = (a > b) ? a : b; // a와 b중 큰 수를 j에 넣는다.
    for (i = j;; i++) { // i에 j값을 넣고 i를 1씩 증가시킨다. i가 a로도 나누어 떨어지고, b로도 나누어 떨어지면 i는 a, b의 최소 공배수이다.
        if (i % a == 0 && i % b == 0) {
            cm = i; // 최소 공배수를 cm에 넣고, 반복문을 종료시킨다.
            break;
        }
    }
    cm_num = a * b / cm; // a와 b의 곱을 최소 공배수로 나누면 a * b 이하의 공배수의 개수를 알 수 있다.
    return cm_num; // 공배수의 개수를 반환한다.
}
