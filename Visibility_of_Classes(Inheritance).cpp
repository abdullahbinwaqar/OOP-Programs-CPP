#include <iostream>
using namespace std;

class base{
	private:
		int privateInt;
	protected:
		int protectedInt;
	public:
		int publicInt;
		
		void setPvtInt(int n){privateInt=n;}
		void setProInt(int n){protectedInt=n;}
		void setPubInt(int n){publicInt=n;}
		
		
		int getPvtInt() const{
			return privateInt;
		}
		
};

class publicChild : public base{
	public:
		void display(){
			cout << "Public Inheritance" << endl;
			cout << "Private Integer: " << getPvtInt() << endl;
			cout << "Protected Integer: " << protectedInt << endl;
			cout << "Public Integer: " << publicInt << endl;
 		}
};

class protectedChild : protected base{
	public:
		void set(){
			setPvtInt(10);
			protectedInt = 20;
			publicInt = 30;
		}
		void display(){
			cout << "\n\nProtected Inheritance" << endl;
			cout << "Private Int: " << getPvtInt() << endl;
			cout << "Protected Integer: " << protectedInt << endl;
			cout << "Public Integer: " << publicInt << endl;
		}
};

class privateChild : private base{
	public:
		void set(){
			setPvtInt(40);
			protectedInt = 50;
			publicInt = 60;
		}
		void display(){
			cout << "\n\nPrivate Inheritance" << endl;
			cout << "Private Int: " << getPvtInt() << endl;
			cout << "Protected Integer: " << protectedInt << endl;
			cout << "Public Integer: " << publicInt << endl;
		}
};

int main(){
	publicChild obj1;
	obj1.setPvtInt(1);
	obj1.setProInt(2);
	obj1.setPubInt(3);
	obj1.display();
	
	protectedChild obj2;
	obj2.set();
	obj2.display();
	
	privateChild obj3;
	obj3.set();
	obj3.display();
	
	return 0;
}
