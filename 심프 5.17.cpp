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
		cout << "��ũ�� : " << model << ", " << manufacture << "	," << "���� ���� " << availableCount << "��  ,���� ��ũ " << availableInk << endl;
	}
	void printInkJet(int pages) {
		if (availableCount >= pages && availableInk >= pages) {
			cout << "����Ʈ �Ͽ����ϴ�." << endl;
			availableCount -= pages;
			availableInk -= pages;
		}
		else if (availableCount < pages) {
			cout << "������ �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
		}
		else if (availableInk < pages) {
			cout << "��ũ�� �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
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
		cout << "������ : " << model << ", " << manufacture << "	," << "���� ���� " << availableCount << "��  ,���� ��� " << availableToner << endl;
	}
	void printLaser(int pages) {
		if (availableCount >= pages && availableToner >= pages) {
			cout << "����Ʈ �Ͽ����ϴ�." << endl;
			availableCount -= pages;
			availableToner -= pages;
		}
		else if (availableCount < pages) {
			cout << "������ �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
		}
		else if (availableToner < pages) {
			cout << "��ʰ� �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
		}
	}
};
int main(void) {
	InkJet* pi = new InkJet("Officejet V40","Hp",5,10);
	Laser* pt = new Laser("SCX-6x45", "�Ｚ����", 3, 20);
	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����." << endl;
	pi->show();
	pt->show();
	cout << endl;
	int type, pages;
	char prt;
	do {
		cout << "������(1:��ũ��, 2:������)�� �ż� �Է� : ";
		cin >> type >> pages;
		if (type == 1) {
			pi->printInkJet(pages);
		}
		else if (type == 2) {
			pt->printLaser(pages);
		}
		pi->show();
		pt->show();
		cout << "�������Ʈ �Ͻðڽ��ϱ�?(y/n)";
		cin >> prt;
		cout << endl;
	} while (prt == 'y');
}