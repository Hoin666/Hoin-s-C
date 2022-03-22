#include<iostream>
#include<string>

using namespace std;
class CoffeeMachine {
public :
	int coffee = 0, water = 0, sugar = 0;
	CoffeeMachine(int cof, int wat, int sug);
	void show() {
		cout << "커피 머신 상태," << "커피 : " << coffee << " 물 : " << water << " 설탕 : " << sugar << endl;
	}
	void drinkEspresso() {
		coffee--;
		water--;
	}
	void drinkAmericano() {
		coffee--;
		water = water - 2;
	}
	void drinkSugarCoffee() {
		coffee--;
		water = water - 2;
		sugar--;
	}
	void fill() {
		coffee = 10; water = 10; sugar = 10;
	}
};
CoffeeMachine :: CoffeeMachine(int cof, int wat, int sug) {
	coffee = cof; water = wat; sugar = sug;
}
int main()
{
	CoffeeMachine java(5, 10, 3);
	java.drinkEspresso();
	java.show();
	java.drinkAmericano();
	java.show();
	java.drinkSugarCoffee();
	java.show();
	java.fill();
	java.show();
}