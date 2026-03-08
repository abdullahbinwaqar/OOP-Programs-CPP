#include <iostream>
using namespace std;

class DynamicArray{
	private:
		int* array;
		int size;
		bool assigned = false;
	public:
		DynamicArray(int s){
			size = s;
			array = new int[size];
			cout << "Dynamic Array of size " << size << " has been allocated" << endl;
		}
		void insertElements(){
			cout << "Start Entering Elements: " << endl;
			for(int i=0; i<size; i++){
				cout << "Enter Element[" << i+1 << "]: ";
				cin >> array[i];
			}
			assigned = true;
		}
		void displayElements(){
			if(assigned){
				cout << "The Elements of The Array Are:" << endl;
				for(int i=0; i<size; i++){
					cout << "- " << array[i] << endl;
				}
			}else{
				cout << "\n\t\tNo Element(s) have been assigned yet\n" << endl;
			}
		}
		~DynamicArray(){
			delete[] array;
			cout << "\n\nMemory released!";
		}	
};

int main(){
	int n;
	
	cout << "Enter the size of Dynamic Array: ";
	cin >> n;
	
	DynamicArray arr(n);
	arr.displayElements();
	arr.insertElements();
	arr.displayElements();
  return 0;
}
