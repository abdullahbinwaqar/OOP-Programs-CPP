#include <iostream>
#include <stdexcept>
using namespace std;

class StackException:public exception{
	private:
		string m;
	public:
		StackException(string e):m(e){}
		const char* what() const noexcept{
			m.c_str();
		}
};

class Stack{
	private:
		int* arr;
		int top;
		int capacity;
		
		void resize(){
			capacity *= 2;
			
			int* copy = new int[capacity];
			
			for(int i=0; i<=capacity; i++){
				copy[i] = arr[i];
			}
			delete[] arr;
			arr = copy;
		}
		
	public:
		Stack(int c):capacity(c){
			arr = new int[capacity];
			top = -1;
		}
		~Stack(){
			delete[] arr;
		}
		bool isEmpty(){return (top==-1);}
		bool isFull(){return top==capacity-1;}
		void push(int e){
			if(isFull()){
				resize();
			}
			arr[++top] = e;
			cout << e << " pushed in the stack!" << endl;
		}
		void pop(){
			if(isEmpty()){
				throw StackException("ERROR: STACK IS EMPTY!");
				return;
			}
			cout << arr[top] << " has been poped from the stack!" << endl;
			--top;
		}
		int topElement(){
			if(isEmpty()){
				throw StackException("ERROR: STACK IS EMPTY!");
				return 0;
			}
			return arr[top];
		}
		void display(){
			if(isEmpty()){
				throw StackException("ERROR: STACK IS EMPTY!");
				return;
			}
			cout << "\tSTACK ELEMENTS\n" << endl;
			for(int i=0; i<=top ; i++){
				cout << "Element: " << arr[i] << endl;
			}
		}
};

int main(){
	try{
		Stack s(6);
//		s.pop(); This thorws exception
		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);
		s.push(5);
		s.push(55);
		s.pop();
	}
	catch(const StackException& e){
		cout << e.what() << endl;
	}
	
	return 0;
}
