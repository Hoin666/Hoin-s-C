#include<iostream>
#include<string>
using namespace std;
class Person {
protected:
	int age;
	string name;
public :
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	int ageRR() {
		return age;
	}
};
class Student : public Person {
private :
	int studentID;
	int temp;
public :
	Student(string name, int age, int ID) : Person(name, age) {
		studentID = ID;
		temp = num;
		num++;
	}
	static int num;
	void show() {
		cout << temp << "��° " << "�л��� �̸�, ����, �й� : " << name << " " << age << " " << studentID << endl;
	}
};
int Student::num = 1;
int main(void) {
	Student st[5] = { Student("¯��",20,2022100123),Student("ö��",21,2021200357),Student("����",22,2020300789),Student("�ͱ�",23,2019400712),Student("����",24,2018644897) };
	int temp[5];
	int stemp;
	for (int i = 0; i < 5; i++) {
		st[i].show();
		temp[i] = st[i].ageRR();
	}
	for (int i = 4; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (temp[j] < temp[j + 1]) {
				stemp = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = stemp;
			}
		}
	}
	cout << "���̰� ���� ���� ��� : "  << 


}