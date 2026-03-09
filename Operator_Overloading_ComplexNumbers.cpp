#include <iostream>
using namespace std;

class Complex{
	private:
		double real;
		double imaginary;
	public:
		Complex(double r, double i):real(r), imaginary(i){}
		Complex operator + (const Complex& other) const{
			return Complex(real + other.real, imaginary + other.imaginary);
		}
		friend ostream& operator << (ostream& out, const Complex& other);
};

ostream& operator << (ostream& out, const Complex& other){
	out << other.real << "+" << other.imaginary << "i" << endl;
	return out;
}

int main(){
	Complex c1(2, 3);
	Complex c2(4, 8);
	Complex sum = c1 + c2;
	cout << "Result: " << sum << endl;

  return 0;
}
