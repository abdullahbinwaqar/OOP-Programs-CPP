#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

class QueueException:public exception{
	private:
		string m;
	public:
		QueueException(string e):m(e){}
		const char* what() const noexcept{
			return m.c_str();
		}
};

class Queue{
	private:
		int* arr;
		int front;
		int back;
		int capacity;
		int size;
		
		void resize(){
			int newCapacity = capacity * 2;
			
			int* temp = new int[newCapacity];
			for(int i=0; i<size; i++){
				temp[i] = arr[(front+i)%capacity];
			}
			delete[] arr;
			arr = temp;
			front = 0;
			back = size;
			capacity = newCapacity;
		}
	public:
		Queue():capacity(5), size(0), front(0), back(0){
			arr = new int[capacity];
		}
		~Queue() {
            delete[] arr;
        }
		bool isEmpty(){
			return (size==0);
		}
		bool isFull(){
			return (size == capacity);
		}
		void Enqueue(int x){
			if(isFull()){
				resize();
			}
			arr[back] = x;
			back = (back+1)%capacity;
			size++;
		}
		int Dequeue(){
			if(isEmpty()){
				throw QueueException("ERROR: Queue is empty!");
			}else{
				
				int val = arr[front];
				front = (front+1) % capacity;
				size--;
				return val;
			}
		}
		int Peek(){
			if(isEmpty()){
				throw QueueException("ERROR: Queue is empty!");
			}else{
				return arr[front];
			}
		}
};

int main(){
	try{
		Queue my;
//		my.Dequeue();
//		my.Dequeue();
		my.Enqueue(1);
		my.Enqueue(2);
		my.Enqueue(3);
		cout << "1st Dequeue: " << my.Dequeue() << endl;
		cout << "2nd Dequeue: " << my.Dequeue() << endl;
		cout << "3rd Dequeue: " << my.Dequeue() << endl;
//		cout << "4th Dequeue: " << my.Dequeue() << endl;
		my.Enqueue(1);
		my.Enqueue(2);
		my.Enqueue(3);
		cout << "1st Dequeue: " << my.Dequeue() << endl;
		cout << "2nd Dequeue: " << my.Dequeue() << endl;
		cout << "3rd Dequeue: " << my.Dequeue() << endl;
	}
	catch(const QueueException& e){
		cout << e.what() << endl;
	}
	return 0;
}
