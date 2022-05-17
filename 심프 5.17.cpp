#include<iostream>
#include<string>
using namespace std;
class Printer {
protected:
	string model;
	string manufacture;
	int printedCount;
	int availableCount;
public:
	Printer(string model, string manufacture, int availableCount) {
		this->model = model;
		this->manufacture = manufacture;
		this->availableCount = availableCount;
	}
	void print() {

	}
};
class InkJet : public Printer {
protected:
	int availableInk;
public:
	InkJet(string model, string manufacture, int availableCount, int availableInk) : Printer(model, manufacture, availableCount) {
		this->availableInk = availableInk;
	}
	void show() {
		cout << "잉크젯 : " << model << ", " << manufacture << "	," << "남은 종이 " << availableCount << "장  ,남은 잉크 " << availableInk << endl;
	}
	void printInkJet(int pages) {
		if (availableCount >= pages && availableInk >= pages) {
			cout << "프린트 하였습니다." << endl;
			availableCount -= pages;
			availableInk -= pages;
		}
		else if (availableCount < pages) {
			cout << "용지가 부족하여 프린트 할 수 없습니다." << endl;
		}
		else if (availableInk < pages) {
			cout << "잉크가 부족하여 프린트 할 수 없습니다." << endl;
		}
	}
};
class Laser : public Printer {
private:
	int availableToner;
public:
	Laser(string model, string manufacture, int availableCount, int availableToner) : Printer(model, manufacture, availableCount) {
		this->availableToner = availableToner;
	}
	void show() {
		cout << "레이저 : " << model << ", " << manufacture << "	," << "남은 종이 " << availableCount << "장  ,남은 토너 " << availableToner << endl;
	}
	void printLaser(int pages) {
		if (availableCount >= pages && availableToner >= pages) {
			cout << "프린트 하였습니다." << endl;
			availableCount -= pages;
			availableToner -= pages;
		}
		else if (availableCount < pages) {
			cout << "용지가 부족하여 프린트 할 수 없습니다." << endl;
		}
		else if (availableToner < pages) {
			cout << "토너가 부족하여 프린트 할 수 없습니다." << endl;
		}
	}
};
int main(void) {
	InkJet* pi = new InkJet("Officejet V40","Hp",5,10);
	Laser* pt = new Laser("SCX-6x45", "삼성전자", 3, 20);
	cout << "현재 작동중인 2 대의 프린터는 아래와 같다." << endl;
	pi->show();
	pt->show();
	cout << endl;
	int type, pages;
	char prt;
	do {
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력 : ";
		cin >> type >> pages;
		if (type == 1) {
			pi->printInkJet(pages);
		}
		else if (type == 2) {
			pt->printLaser(pages);
		}
		pi->show();
		pt->show();
		cout << "계속프린트 하시겠습니까?(y/n)";
		cin >> prt;
		cout << endl;
	} while (prt == 'y');
}