#include <iostream>
#include <cmath>
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
		Circle(int n, float r) : Shape(n), radius(r) {}
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
		Triangle(int n, float h, float b) : Shape(n), height(h), base(b) {}
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
		Rectangle(int n, float l, float w) : Shape(n), length(l), width(w) {}
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
		Square(int n, float s) : Rectangle(n, s, s), side(s) {}
		float getSide() const {return side;}
		void generateArea(){
			float a = pow(side, 2); setArea(a);
		}
		bool checkSides() {return length==width;}
		string getName() {return "Square";}
};

int main(){
	Shape* shapes[4];
	shapes[0] = new Circle(0, 4);
	shapes[1] = new Triangle(3, 2, 3);
	shapes[2] = new Rectangle(4, 3, 6);
	shapes[3] = new Square(4, 4);
	
	for(int i = 0; i < 4; i++){
		shapes[i]->generateArea();
		cout << "Area of " << shapes[i]->getName() << " is: " << shapes[i]->getArea() << endl;
	}
	return 0;
}
