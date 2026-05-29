#include <iostream>
using namespace std;

class Employee{
	private:
		int id;
		string name;
		string designation;
		double salary;
	public:
		Employee(int i, string n, string d, double s){
			id = i;
			name = n;
			designation = d;
			salary = s;
		}
		friend void updation(Employee &e, double s);
		void display(){
			cout << "Employee ID: " << id << endl;
			cout << "Name: " << name << endl;
			cout << "Designation: " << designation << endl;
			cout << "Salary: " << salary << endl;
		}
};
void updation(Employee &e, double s) {
    e.salary = s;
}
int main(){
	Employee ceo(246, "Abdullah Bin Waqar", "CEO", 500000);
	ceo.display();
	updation(ceo ,600000);
	cout << "\nSalary After Updation: " << endl << endl;
	ceo.display();
	return 0;
}
