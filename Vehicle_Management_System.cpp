#include <iostream>
using namespace std;

class Vehicle{
	protected:
		string vehicleName;
		float speed;
	public:
		Vehicle(string n, float s){
			vehicleName=n;
			speed=s;	
		}
		virtual void startEngine() = 0;
};

class Car:public Vehicle{
	public:
		Car(string n, float s):Vehicle(n, s){}
		void startEngine(){
			cout << "Starting " << vehicleName << "'s Engine with speed " << speed << endl; 
		}
};

class Bike:public Vehicle{
	public:
		Bike(string n, float s):Vehicle(n, s){}
		void startEngine(){
			cout << "Starting " << vehicleName << "'s Engine with speed " << speed << endl;
		}
};
class Truck:public Vehicle{
	public:
		Truck(string n, float s):Vehicle(n, s){}
		void startEngine(){
			cout << "Starting " << vehicleName << "'s Engine with speed " << speed << endl;
		}
};

int main(){
	Vehicle* inventory[3];
	inventory[0] = new Car("Corolla", 120);
	inventory[1] = new Bike("ZX1000", 160);
	inventory[2] = new Truck("Freightliner", 80);
	
	for(int i=0; i<3; i++){
		inventory[i]->startEngine();
	}
	
	for(int i=0; i<3; i++){
		delete inventory[i];
	}
	
	return 0;
}
