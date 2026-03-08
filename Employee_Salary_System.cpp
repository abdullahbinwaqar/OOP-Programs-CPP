#include <iostream>
using namespace std;

class Employee{
	protected:
		int employeeID;
		string name;
		double basicSalary;
	public:
		Employee(int empID, string n, double salary){
			employeeID = empID;
			name = n;
			basicSalary = salary;
		}
		virtual ~Employee() {}
		virtual double calculateSalary() = 0;
		virtual void displayInfo(){
			cout << "Employee ID: " << employeeID << endl;
			cout << "Name: " << name << endl;
			cout << "Basic Salary: " << basicSalary << endl;
			cout << "Total Salary: " << calculateSalary() << endl << endl;
		}
};

class Manager:public Employee{
	private:
		double bonus;
	public:
		Manager(int empID, string n, double salary, double b):Employee(empID, n, salary){
			bonus = b;
		}
		double calculateSalary() override {
			double Salary = basicSalary + bonus;
			return Salary;
		}
};

class Engineer:public Employee{
	private:
		int overtime;
		double overtimeRate;
	public:
		Engineer(int empID, string n, double salary, int time, double timeRate) : Employee(empID, n, salary){
			overtime = time;
			overtimeRate = timeRate;
		}
		double calculateSalary() override {
			double Salary = basicSalary + (overtime * overtimeRate);
			return Salary;
		}
};

int main(){
	Employee* staff[2];
	
	staff[0] = new Manager(101 ,"Abdullah Bin Waqar", 150000, 100000);
	staff[1] = new Engineer(201 ,"Irshad Kamran", 85000, 10, 1000);
	
	staff[0]->displayInfo();
	staff[1]->displayInfo();
	
	for(int i=0; i<2; i++){
		delete staff[i];
	}
}
