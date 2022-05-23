#include<iostream>
#include<fstream>
#include<string>
#include<filesystem>

using namespace std;
#define MAX 100
int intro = 1;

class Member { // 회원 정보
private :
	string name;
	string id;
	string password;
	string address;
public :
	int type1() { // 안내 문구1
		int num = 0;
		cout << "1) 회원가입, 2) 로그인, 3) 회원탈퇴 : ";
		cin >> num;
		return num;
	}
	int type2() {
		int num = 0;
		cout << "1) 예치금 넣기, 2) 주문하기, 3) 정보 보기, 4) 친구 추가";
		cin >> num;
		return num;
	}
	void create(string name, string id, string password, string address) { // 가입 정보를 txt로 저장
		this->name = name;
		this->id = id;
		this->password = password;
		ofstream fout;
		fout.open(id + ".txt");
		fout << id << endl;
		fout << password << endl;
		fout << name << endl;
		fout << address << endl;
		cout << "회원가입 성공!" << endl;

		fout.close();
	}
	void createM() { // 가입 정보 입력
		string name, id, password;
		while (true) {
			cout << "이름 : ";
			cin >> name;
			if (name.length() > 8) {
				cout << "잘못 입력했습니다." << endl;
			}
			else {
				break;
			}
		}
		while (true) {
			cout << "아이디 : ";
			cin >> id;
			if (id.length() > 12) {
				cout << "잘못 입력했습니다." << endl;
			}
			else {
				break;
			}
		}
		while (true) {
			cout << "비밀번호 : ";
			cin >> password;
			if (id.length() > 12) {
				cout << "잘못 입력했습니다." << endl;
			}
			else {
				break;
			}
		}
		while (true) {
			cout << "주소 : ";
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
			cout << "로그인 성공!" << endl;
			fin.close();
			intro = 0;
		}
		else {
			cout << "로그인 실패!" << endl;
			fin.close();
		}
		
	}
	void loginM() {
		while (true) {
			cout << "아이디 : ";
			cin >> id;
			if (id.length() > 12) {
				cout << "잘못 입력했습니다." << endl;
			}
			else {
				break;
			}
		}
		while (true) {
			cout << "비밀번호 : ";
			cin >> password;
			if (id.length() > 12) {
				cout << "잘못 입력했습니다." << endl;
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
			cout << "인증 성공! 회원 탈퇴 하였습니다." << endl;
			ofstream fout;
			fout.open(id + ".txt");
			fout << 00000000 << endl;
			fout << 00000000 << endl;
			fout << 00000000 << endl;

			fout.close();

		}
		else {
			cout << "인증 실패!" << endl;
		}
		fin.close();
	}
	void delM() {
		while (true) {
			cout << "아이디 : ";
			cin >> id;
			if (id.length() > 12) {
				cout << "잘못 입력했습니다." << endl;
			}
			else {
				break;
			}
		}
		while (true) {
			cout << "비밀번호 : ";
			cin >> password;
			if (id.length() > 12) {
				cout << "잘못 입력했습니다." << endl;
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