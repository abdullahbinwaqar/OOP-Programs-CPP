#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class ArrayException:public exception{
	private:
		string e;
	public:
		ArrayException(string m):e(m){}
		const char* what() const noexcept override{
			return e.c_str();
		}
};

template <class T>
class Array;

template <class T>
T sum(Array<T>& a);

template <class T>
class Array{
	private:
		vector<T> arr;
	public:
		Array(int s){
			arr.resize(s);
		}
		void input(){
			for(int i=0; i<arr.size(); i++){
				cout << "Enter element: ";
				cin >> arr[i];
			}
		}
		T& operator[](int index){
			if(index<0 || index>=arr.size()){
				throw ArrayException("Out of bound!");
			}else{
//				cout << "Element at index[" << index << "]: " << arr[index] << endl;
				return arr[index];
			}
		}
		friend T sum<T>(Array<T>& arra);
};
template <typename T>
T sum(Array<T>& a){
	T sum = 0;
	for(int i=0; i<a.arr.size(); i++){
		sum += a[i];
	}
	return sum;
}

int main(){
	Array<int> one(5);
	one.input();
	
	try{
		cout << "Element at index[]: " << one[5] << endl;
	}catch(const ArrayException& e){
		cout << e.what() << endl;
	}
	cout << "Sum is: " << sum(one);
	return 0;
}
