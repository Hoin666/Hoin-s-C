#include<iostream>
#include<string>
using namespace std;
class Histogram {
public:
	string sentence;
	Histogram(string sentence = "") {
		this->sentence = sentence;
	}
	Histogram& operator << (string sentence) {
		this->sentence = this->sentence + sentence;
		return *this;
	}
	Histogram& operator << (char sen) {
		this->sentence = this->sentence + sen;
		return *this;
	}
	void operator !(){
		cout << sentence;
	}
};

int main(void) {
	Histogram song("Lorem Ipsum is simly dummy text of the printing and typesetting industry.\n");
	song << "Lorem Ipsum" << "has been the" << "industry's standard";
	song << 'd' << 'u' << 'm' << 'y';
	!song;
}