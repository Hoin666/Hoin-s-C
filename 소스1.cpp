#include<iostream>
#include<string>
using namespace std;
class Character {
public : 
	string name;
	int hp, damage;
	int ragepoint = 1;
	Character(string na, int h, int dam);
	Character();
	void pointUp();
	void show();
};
Character::Character(string na, int h, int dam) {
	name = na +"[" + to_string(ragepoint) + "]", hp = h, damage = dam;
}

void Character::pointUp() {
	hp += 25, damage += 10;
}
void Character::show() {
	cout << name << " " << hp << " " << damage << endl;
}
Character::Character() {
	ragepoint++;
}
int main(void) {
	Character character1("¸ó½ºÅÍ", 100, 20);
	character1.pointUp();
	Character character2(character1);
	character2.pointUp();
	Character character3(character2);
	character3.pointUp();
	character1.show();
	character2.show();
	character3.show();

}