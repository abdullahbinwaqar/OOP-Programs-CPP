#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class Stack;

template <typename T>
void peek(Stack<T>& s);


class StackException:public exception{
	private:
		string e;
	public: 
		StackException(string m):e(m){}
		const char* what() const noexcept override{
			return e.c_str();
		}
};

template <class T>
class Stack{
	private:
		vector<T> stack;
	public:
		void push(T item){
			stack.push_back(item);
		}
		void pop(){
			if(!stack.empty()){
				stack.pop_back();
			}else{
				throw StackException("The stack is empty!");
			}
		}
//		template <typename U>
    	friend void peek<T>(Stack<T>& s);
    	void display(){
    		for(auto i: stack){
    			cout << i << endl;
			}
		}
};

template <typename T>
void peek(Stack<T>& s){
	cout << "Top Element: " << s.stack.back() << endl;
}

int main(){
	Stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.display();
	s.pop();
	s.pop();
	s.display();
	peek(s);
	try{
		s.pop();
		s.pop();
		s.pop();
		s.pop();
	}
	catch(const StackException& e){
		cout << "Error: " << e.what() << endl;
	}
	return 0;
}
