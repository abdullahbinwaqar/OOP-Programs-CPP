#include <iostream>
using namespace std;

class Person{
	protected:
		string name;
		string occupation;
	public:
		Person(string n, string o): name(n), occupation(o){}
		virtual void Draw() = 0;
};

class Artist:public Person{
	public:
		Artist(string n, string o):Person(n, o){}
		void Draw(){cout << "An artist can draw with a paint brush" << endl;}
};

class Gunman:public Person{
	public:
		Gunman(string n, string o):Person(n, o){}
		void Draw(){cout << "A gunman draws a gun to shoot" << endl;}
};

int main(){
	Person* list[2];
	list[0] = new Artist("Zain", "Artist");
	list[1] = new Gunman("Hammad", "Gunman");
	list[0]->Draw();
	list[1]->Draw();
	return 0;
}
