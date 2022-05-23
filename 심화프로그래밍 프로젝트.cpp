#include<iostream>
#include<fstream>
#include<string>
#include<filesystem>

using namespace std;
#define MAX 100
int intro = 1;

class Member { // ȸ�� ����
private :
	string name;
	string id;
	string password;
	string address;
public :
	int type1() { // �ȳ� ����1
		int num = 0;
		cout << "1) ȸ������, 2) �α���, 3) ȸ��Ż�� : ";
		cin >> num;
		return num;
	}
	int type2() {
		int num = 0;
		cout << "1) ��ġ�� �ֱ�, 2) �ֹ��ϱ�, 3) ���� ����, 4) ģ�� �߰�";
		cin >> num;
		return num;
	}
	void create(string name, string id, string password, string address) { // ���� ������ txt�� ����
		this->name = name;
		this->id = id;
		this->password = password;
		ofstream fout;
		fout.open(id + ".txt");
		fout << id << endl;
		fout << password << endl;
		fout << name << endl;
		fout << address << endl;
		cout << "ȸ������ ����!" << endl;

		fout.close();
	}
	void createM() { // ���� ���� �Է�
		string name, id, password;
		while (true) {
			cout << "�̸� : ";
			cin >> name;
			if (name.length() > 8) {
				cout << "�߸� �Է��߽��ϴ�." << endl;
			}
			else {
				break;
			}
		}
		while (true) {
			cout << "���̵� : ";
			cin >> id;
			if (id.length() > 12) {
				cout << "�߸� �Է��߽��ϴ�." << endl;
			}
			else {
				break;
			}
		}
		while (true) {
			cout << "��й�ȣ : ";
			cin >> password;
			if (id.length() > 12) {
				cout << "�߸� �Է��߽��ϴ�." << endl;
			}
			else {
				break;
			}
		}
		while (true) {
			cout << "�ּ� : ";
			cin >> address;
			break;
		}
		create(name, id, password,address);
	}
	void login(string id, string password) {
		ifstream fin;
		char temp_id[12];
		char temp_password[12];
		fin.open(id + ".txt");
		fin.getline(temp_id, 12);
		fin.getline(temp_password, 12);
		if (id.compare(temp_id) == 0 && password.compare(temp_password) == 0){
			cout << "�α��� ����!" << endl;
			fin.close();
			intro = 0;
		}
		else {
			cout << "�α��� ����!" << endl;
			fin.close();
		}
		
	}
	void loginM() {
		while (true) {
			cout << "���̵� : ";
			cin >> id;
			if (id.length() > 12) {
				cout << "�߸� �Է��߽��ϴ�." << endl;
			}
			else {
				break;
			}
		}
		while (true) {
			cout << "��й�ȣ : ";
			cin >> password;
			if (id.length() > 12) {
				cout << "�߸� �Է��߽��ϴ�." << endl;
			}
			else {
				break;
			}
		}
		login(id, password);
	}
	void del(string id, string password) {
		ifstream fin;
		char temp_id[12];
		char temp_password[12];
		fin.open(id + ".txt");
		fin.getline(temp_id, 12);
		fin.getline(temp_password, 12);
		if (id.compare(temp_id) == 0 && password.compare(temp_password) == 0) {
			cout << "���� ����! ȸ�� Ż�� �Ͽ����ϴ�." << endl;
			ofstream fout;
			fout.open(id + ".txt");
			fout << 00000000 << endl;
			fout << 00000000 << endl;
			fout << 00000000 << endl;

			fout.close();

		}
		else {
			cout << "���� ����!" << endl;
		}
		fin.close();
	}
	void delM() {
		while (true) {
			cout << "���̵� : ";
			cin >> id;
			if (id.length() > 12) {
				cout << "�߸� �Է��߽��ϴ�." << endl;
			}
			else {
				break;
			}
		}
		while (true) {
			cout << "��й�ȣ : ";
			cin >> password;
			if (id.length() > 12) {
				cout << "�߸� �Է��߽��ϴ�." << endl;
			}
			else {
				break;
			}
		}
		del(id, password);
	}
};
int main(void) {
	Member ho;
	while (true) {
		while (intro == 1) {
			int type1 = ho.type1();
			switch (type1) {
			case 1:
				ho.createM();
				break;
			case 2:
				ho.loginM();
				break;
			case 3:
				ho.delM();
				break;
			}
		}
		while (intro == 0) {
			int type2 = ho.type2();
			switch (type2) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			}
		}
	}
}