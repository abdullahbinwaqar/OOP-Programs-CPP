#include <iostream>
#include <cmath>
using namespace std;

class Vector{
	private:
		float x;
		float y;
	public:
		Vector(float a, float b) : x(a), y(b) {}
		Vector operator + (const Vector& other) const{
			return Vector(x+other.x, y+other.y);
		}
		Vector operator - (const Vector& other) const{
			return Vector(x-other.x, y-other.y);
		}
		Vector operator * (float scalar) const{
			return Vector(scalar*x, scalar*y);
		}
		Vector operator / (float scalar) const{
			if(scalar == 0){
				cout << "ZERO DIVISION ERROR!" << endl;
				return Vector(0, 0);
			}else{
				return Vector(x/scalar, y/scalar);
			}
		}
		float Magnitude() const{
			return sqrt(x*x + y*y);
		}
		void display() const{
			cout << "X-" << x << "\tY-" << y << endl;
		}
};

int main(){
	Vector v1(1, 2);
	Vector v2(3, 4);
	Vector v3(9, 6);
	Vector sum = v1 + v2;
	Vector difference = v2 - v1;
	Vector product = v1 * 3;
	Vector div = v3/3;
	cout << "SUM: \n"; sum.display(); 
	cout << "Magnitude of Sum: " << sum.Magnitude() << endl;
	cout << "DIFFERENCE: \n"; difference.display() ; 
	cout << "Magnitude of Difference: " << difference.Magnitude() << endl;
	cout << "PRODUCT: \n"; product.display();
	cout << "Magnitude of Product: " << product.Magnitude() << endl;
	cout << "DIVISION: \n"; div.display(); 
	cout << "Magnitude of Division: " << div.Magnitude() << endl;
	return 0;
}
