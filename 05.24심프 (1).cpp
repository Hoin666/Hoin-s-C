#include<iostream>
using namespace std;
class Shape {
protected:
	string name;
	int width, height;
public:
	Shape(string n = "", int w = 0, int h = 0) {
		name = n;
		width = w;
		height = h;
	}
	virtual double getArea() = 0;
	string getName() { return name; }
};
class Oval : public Shape {
public:
	Oval(string n = "", int w = 0, int h = 0) : Shape(n, w, h) {}
	double getArea() {
		return width * height * 3.14;
	}
};
class Quadrangle : public Shape {
public:
	Quadrangle(string n = "", int w = 0, int h = 0) : Shape(n, w, h) {}
	double getArea() {
		return width * height;
	}
};
class Triangular : public Shape {
public:
	Triangular(string n = "", int w = 0, int h = 0) : Shape(n, w, h) {}
	double getArea() {
		return width * height * 0.5;
	}
};
int main(void) {
	Oval ov("Ÿ����", 20, 40);
	Quadrangle qu("�簢��", 32, 54);
	Triangular tr("�ﰢ��", 30, 50);
	cout << ov.getName() << " ���̴� " << ov.getArea() << endl;
	cout << qu.getName() << " ���̴� " << qu.getArea() << endl;
	cout << tr.getName() << " ���̴� " << tr.getArea() << endl;
}