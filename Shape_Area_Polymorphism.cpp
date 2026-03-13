#include <iostream>
#include <cmath>
#include <typeinfo>
# define Pi 3.142
using namespace std;

class Shape{
	protected:
		int numberOfSides;
		float area;
	public:
		Shape(int n) : numberOfSides(n), area(0) {}
		virtual void generateArea() = 0;
		virtual string getName() = 0;
		float getArea() const {return area;}
		int getNumberOfSides() const {return numberOfSides;}
		void setArea(float a) {area=a;}
};

class Circle : public Shape{
	private:
		float radius;
	public:
		Circle(float r) : Shape(0), radius(r) {}
		float getRadius() const {return radius;}
		void generateArea(){
			float a = Pi * pow(radius, 2); setArea(a);
		}
		string getName() {return "Circle";}
};

class Triangle : public Shape{
	private:
		float height;
		float base;
	public:
		Triangle(float h, float b) : Shape(3), height(h), base(b) {}
		float getHeight() const {return height;}
		float getBase() const {return base;}
		string getName() {return "Triangle";}
		void generateArea(){
			float a = 0.5 * base * height; setArea(a);
		}	
};

class Rectangle : public Shape{
	protected:
		float length;
		float width;
	public:
		Rectangle(float l, float w) : Shape(4), length(l), width(w) {}
		float getLength() const {return length;}
		float getWidth() const {return width;}
		string getName() {return "Rectangle";}
		void generateArea(){
			float a = length * width; setArea(a);
		}
};

class Square : public Rectangle {
	private:
		float side;
	public:
		Square(float s) : Rectangle(s, s), side(s) {}
		float getSide() const {return side;}
		void generateArea(){
			float a = pow(side, 2); setArea(a);
		}
		bool checkSides() {return length==width;}
		string getName() {return "Square";}
};

int main(){
	Shape* shapes[4];
	shapes[0] = new Circle(4);
	shapes[1] = new Triangle(2, 3);
	shapes[2] = new Rectangle(3, 6);
	shapes[3] = new Square(4);
	
	Square sq(4);
	for(int i = 0; i < 4; i++){
		shapes[i]->generateArea();
		cout << "Area of " << shapes[i]->getName() << " is: " << shapes[i]->getArea() << endl;
	}
	
	cout << (sq.checkSides() ? "Both sides of squares are equal!" : "Both sides of squares are not equal!") << endl;
	
	for(int i = 0; i < 4; i++){delete shapes[i];}
	return 0;
}
