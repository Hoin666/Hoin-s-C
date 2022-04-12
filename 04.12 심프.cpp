#include <iostream>
using namespace std;

class Car {
	int speed;
	int gear;
	string color;
public :
	Car(int s = 0, int g = 1, string c = "red") : speed(s), gear(g), color(c){}
	void display() {
		cout << "�ӵ�: " << speed << " ���: " << gear << " ����: " << color << endl;
	}
};
void swapObjects(Car* c1, Car* c2) {
	Car temp(0, 1, "none");
	temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}
int main()
{
	Car mine(0, 1, "blue");
	Car yours(0, 1);

	cout << "�Լ� ȣ�� ��" << endl;
	mine.display();
	yours.display();

	cout << endl << "�Լ� ȣ�� ��" << endl;
	swapObjects(&mine, &yours);
	mine.display();
	yours.display();

	return 0;
}