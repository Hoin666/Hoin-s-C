#include<iostream>
using namespace std;
class AbstractGate {
protected:
	bool x, y;
public:
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0;
};
class ANDGate : public AbstractGate {
public:
	bool operation() {
		if (x == true && y == true) {
			return true;
		}
		else if (x == false && y == false) {
			return false;
		}
		else {
			return false;
		}
	}
};
class ORGate : public AbstractGate {
public:
	bool operation() {
		if (x == true && y == true) {
			return true;
		}
		else if (x == false && y == false) {
			return false;
		}
		else {
			return true;
		}
	}
};
class XORGate : public AbstractGate {
public:
	bool operation() {
		if (x == true && y == true) {
			return false;
		}
		else if (x == false && y == false) {
			return false;
		}
		else {
			return true;
		}
	}
};
int main(void) {
	ANDGate andGate;
	ORGate orGate;
	XORGate xorGate;

	andGate.set(false, false);
	orGate.set(true, true);
	xorGate.set(false, true);
	cout.setf(ios::boolalpha);
	cout << andGate.operation() << endl;
	cout << orGate.operation() << endl;
	cout << xorGate.operation() << endl;
}