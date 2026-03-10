#include <iostream>
using namespace std;

class Course{
	private:
		string courseName;
		string courseCode;
	public:
		Course(string n, string c):courseName(n),courseCode(c){}
		Course():courseName(""),courseCode(""){};
		void displayCourse(){
			cout << "\n\t-Course Name: " << courseName;
			cout << "\t-Course Code: " << courseCode;
		}
		string getCourseCode() const{
			return courseCode;
		}
};

class Student{
	private:
		string name;
		string rollNumber;
		Course courses[6];
		int courseCount;
	public:
		Student(string n, string rollNum){
			name = n;
			rollNumber = rollNum;
			courseCount = 0;
		}
		void enrollCourse(Course enroll){
			if(courseCount<6){
				courses[courseCount] = enroll;
				courseCount++;
			}else{
				cout << "You cannot opt for more than 6 Courses Per semester!" << endl;
			}
		}
		void dropCourse(string cc){
			bool found = false;
			for(int i=0; i<courseCount; i++){
				if(courses[i].getCourseCode() == cc){
					found = true;
					for(int j=i; j<courseCount-1; j++){
						courses[j] = courses[j+1];
					}
					cout << "Student Dropped Course " << cc << " Successfully!" << endl;
					courseCount--;
					break;
				}
			}
			if(!found){
				cout << "Student is not registered in this course!" << endl;
			}
		}
		void displayEnrolledCourses(){
			cout << "\n\n-Name: " << name;
			cout << "\t-Roll Number: " << rollNumber;
			for(int i=0; i<courseCount; i++){
				courses[i].displayCourse();
			}
			cout << "\n\n";
		}
};

int main(){
	Course c1("Programming Fundamental", "PF-111");
	Course c2("Pakistan Studies", "PST-222");
	Course c3("Discrete Structure", "DS-333");
	Student std1("Abdullah Bin Waqar", "CT-0001");
	
	std1.enrollCourse(c1);
	std1.enrollCourse(c2);
	std1.enrollCourse(c3);
	std1.displayEnrolledCourses();
	
	std1.dropCourse("CT-090");
	std1.dropCourse("DS-333");
	
	return 0;
}
