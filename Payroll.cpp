#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T> 
class Employee;

template <typename T> 
void updateSalary(Employee<T>& e, T s);

class PayrollException:public exception{
	private:
		string e;
	public:
		PayrollException(string msg) {
        	e = msg;
    	}
    	const char* what() const noexcept{
			return e.c_str();
		}
};

template <class T>
class Employee{
	private:
		int id;
		string name;
		T salary;
	public:
		Employee(int i, string n, T s){
			id = i;
			name = n;
			if(s>0){
				salary = s;
			}else{
				throw PayrollException("Invalid Salary Entered!");
			}
		}
		friend void updateSalary<T>(Employee<T>&, T);
		void display() const {
	        cout << "ID: " << id << endl;
	        cout << "Name: " << name << endl;
	        cout << "Salary: " << salary << endl << endl;
    	}
    	T getSalary () const{
    		return salary;
		}
};

template <typename T>
void updateSalary(Employee<T>& e, T s){
	if(s>0){
		e.salary += s;
	}else{
		throw PayrollException("Invalid Salary Entered!");
	}
}

template <class T>
class Payroll{
	private:
		vector<Employee<T>> stored;
	public:
		void add(const Employee<T>& e){
			stored.push_back(e);
		}
		void sortBySalary() {
    		sort(stored.begin(), stored.end(), 
			[](auto a, auto b){
				return a.getSalary() > b.getSalary();
			});
		}
		void displayStore(){
			for(const auto emp:stored){
				emp.display();
			}
		}
		Employee<T>& getEmp(int index){
			return stored.at(index);
		}
};

int main(){
	try{
		Payroll<double> payroll;

        Employee<double> e1(101 ,"Ali", 50000.5);
        Employee<double> e2(102 ,"Ahmed", 500.5);
        Employee<double> e3(103 ,"Sara", 100000.5);
       
       	payroll.add(e1);
        payroll.add(e2);
        payroll.add(e3);
        
        payroll.displayStore();
//       	updateSalary(e1, -100.0);
		updateSalary(payroll.getEmp(0), 60000.5);
		
		payroll.displayStore();
		
		payroll.sortBySalary();
		payroll.displayStore();
	}
	catch(const PayrollException& e){
		cout << e.what() << endl;
	}
	return 0;
}
