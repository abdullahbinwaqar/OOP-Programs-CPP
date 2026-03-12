#include <iostream>
using namespace std;

class Patient{
	private:
		int patientID;
		string name;
		string disease;
		static int nextID;
	public:
		Patient(){
			patientID = 0;
			name = "";
			disease = "";
		}
		Patient(string n, string d){
			patientID = nextID; nextID++;
			name = n;
			disease = d;
		}
		void admitPatient(string n, string d){	
			patientID = nextID; 
			nextID++;
			name = n;
			disease = d;
		}
		int getID() const {return patientID;}
		void dischargePatient(Patient p[], int &size){
			for(int i=0; i<size; i++){
				if(patientID==p[i].patientID){
					cout << "\n\n\t\tPatient Removed With ID " << patientID << endl << endl;
					for(int j=i; j<size-1; j++){
						p[j] = p[j+1];
					}
					size--;
					break;
				}
			}
		}
		void Display(){
			cout << "\n-Patient ID: " << patientID;
			cout << "\t-Name: " << name;
			cout << "\tDisease: " << disease << endl;
		}
};

int Patient::nextID = 1;

int main(){
	int size = 3;
	Patient patients[size];
	patients[0].admitPatient("Ahmed Kamran", "Sore Throat");
	patients[1].admitPatient("Noman Zain", "Dry Cough");
	patients[2].admitPatient("Yahya Khurram", "Eye Flu");
	
	for(int i=0; i<size; i++){
		patients[i].Display();
	}	
	
	patients[0].dischargePatient(patients, size);
	
	for(int i=0; i<size; i++){
		patients[i].Display();
	}
	return 0;
}
