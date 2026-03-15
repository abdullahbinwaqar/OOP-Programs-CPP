#include <iostream>
using namespace std;

class Calculator{
	private:
		int Num1;
		int Num2;
		int Num3;
	public:
		Calculator(){
			cout << "Enter Three Numbers: ";
			cin >> Num1 >> Num2 >> Num3;
		}
		int add(int a, int b) {return a + b;}
		int add(int a, int b, int c) {return a + b + c;}
		int multiply(int a, int b) {return a * b;}
		int multiply(int a, int b, int c) {return a * b * c;}
		int subtract(int a, int b) {return a - b;}
		double division(int a, int b) {
			if (b==0){
				cout << "ZERO DIVISION ERROR!" << endl;
				return 0;
			}else{
				return double(a)/b;}
			}
		
		void result(){
			cout << "\nAddition (2 numbers): " << add(Num1, Num2) << endl;
	        cout << "Addition (3 numbers): " << add(Num1, Num2, Num3) << endl;
	
	        cout << "Multiplication (2 numbers): " << multiply(Num1, Num2) << endl;
	        cout << "Multiplication (3 numbers): " << multiply(Num1, Num2, Num3) << endl;
	
	        cout << "Subtraction: " << subtract(Num1, Num2) << endl;
	        cout << "Division: " << division(Num1, Num2) << endl;
		}
};

int main(){
	Calculator expression;
	expression.result();
	
	return 0;
}
