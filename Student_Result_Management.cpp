#include <iostream>
#include <cmath>
using namespace std;

class Student{
	private:
		static int studentCount;
		string name;
		string rollNumber;
		int marks[3];
	public:
		Student(){
			name = "";
			rollNumber = "";
			for(int i=0; i<3; i++){marks[i]=0;}
		}
		Student(string n, string r, int numbers[3]){
			name = n;
			rollNumber = r;
			studentCount++;
			for(int i=0; i<3; i++){
				marks[i] = numbers[i];
			}
		}
		int calculateTotal(){
			int total = 0;
			for(int i=0; i<3; i++){
				total += marks[i];
			}
			return total;
		}
		double calculateAverage(){
			return double(calculateTotal()/3.0);
		}
		char calculateGrade(){
			double avg = calculateAverage();

		    if(avg >= 85) return 'A';
		    else if(avg >= 70) return 'B';
		    else if(avg >= 60) return 'C';
		    else if(avg >= 50) return 'D';
		    else return 'F';
		}
		void displayStudentDetails() const{
			cout << "Name: " << name << endl;
			cout << "Roll Number: " << rollNumber << endl;
		}
		static void showStudentCount(){
			cout << "Total Students: " << studentCount << endl;
		}
		void displayResult(){
			displayStudentDetails();
			cout << "Total Marks: " << calculateTotal() << endl;
			cout << "Average Marks: " << round(calculateAverage()) << endl;
			cout << "Marks Obtained: " << endl;
			cout << "Grade: " << calculateGrade() << endl;
			for(int i=0; i<3; i++){
				cout << "- " << marks[i] << endl;
			}
			cout << "\n\n";
		}
		
		
};

int Student::studentCount = 0;

int main(){
	Student students[3];
	
	int stu1[3] = {89, 92, 90};
	int stu2[3] = {77, 56, 90};
	int stu3[3] = {50, 62, 60};
	
	students[0] = Student("Abdullah Bin Waqar", "CT-1010", stu1);
	students[0].displayResult();
	
	students[1] = Student("Zaid Hassan", "CT-1000", stu2);
	students[1].displayResult();
	
	students[2] = Student("Fatima Ahsan", "CT-0010", stu3);
	students[2].displayResult();
	
	
	cout << "\n\nTotal Number Of Students: ";
	Student::showStudentCount();
	
	
	
}
