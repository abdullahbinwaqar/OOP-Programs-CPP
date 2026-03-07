#include <iostream>
using namespace std;

class Book{
	private:
		string title;
		string author;
		string isbn;
		bool isAvailable;
	public:
		Book(string t, string a, string i){
			title = t;
			author = a;
			isbn = i;
			isAvailable = true;
		}
		Book(){
			title = "";
			author = "";
			isbn = "";
			isAvailable = true;
		}
		
		void displayBookInfo(){
			cout << "Title: "<< title << endl;
			cout << "Author: " << author << endl;
			cout << "ISBN: "<< isbn << endl;
			cout << "Status: " << (isAvailable ? "Available":"Borrowed") << endl;
		}
		void setAvailability(bool status){isAvailable=status;}
		bool getAvailability() const{return isAvailable;}
		string getISBN(){return isbn;}
};

class Member{
	private:
		string name;
		static int memberID;
		int MemID;
		Book borrowedBooks[5]; // Member cannot have more than 5 borrowed books at a single time
		int index=0;
	public:
		Member(string n){
			name = n;
			MemID = memberID;
			memberID+=1;
		}
		void issueBook(Book &b){
			if(!b.getAvailability()){
				cout << "This Book Is Already Borrowed!" << endl;
				return;
			}
			if (index<5){
				b.setAvailability(false);
				borrowedBooks[index] = b;
				index+=1;
				cout << "Book Issued By Member!" << endl;
			}
			else{
				cout << "You Already Have Borrowed 5 Books!" << endl;
			}
		}
		void returnBook(Book &b){
			b.setAvailability(true);
			for(int i=0; i<=index; i++){
				if(b.getISBN()==borrowedBooks[i].getISBN()){
					b.setAvailability(true);
					for(int j=i; j<index; j++){
						borrowedBooks[j] = borrowedBooks[j+1];
					}
					index--;
					cout << "Book Returned Sucessfully!" << endl;
					return;
				}
			}
			cout << "This Member Does Not Have This Book!" << endl;
		}
		void displayBorrowedBooks(){
			cout << name << "'s Borrowed Books Are Listed Below:" << endl;
			if(index>0){
				for(int i=0; i<index; i++){
					cout << "Book " << i+1 << ":\n";
					borrowedBooks[i].displayBookInfo();
				}
			}else{
				cout << "This Member Has No Borrowed Books!" << endl;
			}
		}
};

int Member::memberID = 1;
int main(){
	Book b1("Programming Champs", "Abdullah Bin Waqar", "123-456");
	Book b2("Sharp Minds", "Saad", "145-068");
	
	Member m1("Hamza");
	Member m2("Zaid");
	m2.issueBook(b1);
	m2.issueBook(b2);
	m2.displayBorrowedBooks();
	
	m2.returnBook(b2);
	m2.displayBorrowedBooks();
	
	b2.displayBookInfo();
	return 0;
}
