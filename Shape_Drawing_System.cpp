#include <iostream>
using namespace std;

class Shape{
	protected:
		string name;
	public:
		Shape(string n){name = n;}
		virtual void draw() = 0;
};

class Circle:public Shape{
	public:
		Circle(string n):Shape(n){}
		void draw() override{
			cout << "Drawing Circle: " << name << endl;
		}
};

class Rectangle:public Shape{
	public:
		Rectangle(string n):Shape(n){}
		void draw() override{
			cout << "Drawing Rectangle: " << name << endl;
		}
};

class Triangle:public Shape{
	public:
		Triangle(string n):Shape(n){}
		void draw() override{
			cout << "Drawing Triangle: " << name << endl;
		}
};

int main(){
	Shape* s[3];
	Rectangle rect("Rectangle");
	Triangle tri("Triangle");
	Circle cir("Circle");
	
	s[0] = &rect;
	s[0]->draw();
	
	s[1] = &tri;
	s[1]->draw();
	
	s[2] = &cir;
	s[2]->draw();
	
	return 0;
}
