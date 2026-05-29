#include <iostream>
#include <map>
#include <queue>
#include <stdexcept>
using namespace std;

class RentalException : public exception{
    private:
        string e;
    public:
        RentalException(string m):e(m){}
        const char* what() const noexcept override{
            return e.c_str();
        }
};

class Vehicle{
	protected:
		string name;
		bool isAvailable;
	public:
		Vehicle(string n):name(n), isAvailable(true){}
		virtual void rent() = 0;
		bool getAvailable() const {
//		 cout << "Is Available: "<< (isAvailable? "Yes\n":"No\n");
		return isAvailable;
		}
		virtual ~Vehicle() {} 
};

class Car:virtual public Vehicle{
	public:
		Car(string n):Vehicle(n){}
		void rent(){
			if(isAvailable){
				cout << name << " rented successfully" << endl;
				isAvailable = false;
			}else{
				cout << "Vehicle already rented!" << endl;
			}
		}
};

class premiumService:virtual public Vehicle{
	public:
		premiumService(string n):Vehicle(n){}
		void rent(){
			if(isAvailable){
				cout << name << " rented successfully" << endl;
				isAvailable = false;
			}else{
				cout << "Vehicle already rented!" << endl;
			}
		}
};

class Luxury: public Car, public premiumService{
	protected:
		string extraFeatures;
	public:
		Luxury(string n, string e):premiumService(n), Car(n), Vehicle(n){
			extraFeatures = e;
		}
		void rent(){
			if(isAvailable){
				cout << name << " rented successfully!" << endl;
				cout << "Extra Features: " << extraFeatures << endl;
				isAvailable = false;
			}else{
				cout << "Vehicle Already rented!" << endl;
			}
		}
};

template <class T>
class RentalQueue{
	private:
		queue<T> requests;
	public:
		void addItem(T item){
			requests.push(item);
		}
		void fulfil(){
			if(requests.empty()){
				throw RentalException("The rental queue is empty!");
			}else{
				T frontItem = requests.front();
				frontItem->rent(); 
				requests.pop();
			}
		}
};

int main(){
	map<string, bool> availability;
	
	Vehicle* v[2];
	
	v[0] = new Car("Grande");
	v[1] = new Luxury("Mercedes", "Auto pilot, cruise control, parking sensors");
	
//	Luxury l("Mercedes", "Auto pilot, cruise control, parking sensors");
	
	availability["Grande"] = v[0]->getAvailable();
	availability["Mercedes"] = v[1]->getAvailable();
	
	RentalQueue<Vehicle*> req;
	req.addItem(v[0]);
	req.addItem(v[1]);
	
	for(auto car:availability){
		cout << "Name: " << car.first << endl;
		cout << "Is Available: " << (car.second? "Yes\n":"No\n") << endl;
	}
	try{
		req.fulfil();
		req.fulfil();
		req.fulfil();
	}
	catch(const RentalException& e){
    cout << e.what() << endl;
}
	availability["Grande"] = v[0]->getAvailable();
	availability["Mercedes"] = v[1]->getAvailable();
	
	for(auto car:availability){
		cout << "Name: " << car.first << endl;
		cout << "Is Available: " << (car.second? "Yes\n":"No\n") << endl;
	}
	delete v[0];
	delete v[1];
	return 0;
	
}
