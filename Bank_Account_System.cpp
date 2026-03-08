#include <iostream>
using namespace std;

class BankAccount{
	private:
		int accountNumber;
		string accountHolderName;
		double balance;
	public:
		BankAccount(int accNo, string name){
			accountNumber = accNo;
			accountHolderName = name;
			balance = 0.0;
		}
		void deposit(double amount){
			if (amount>0){
				balance += amount;
			}else{
				cout << "Invalid Amount!" << endl;
			}
		}
		void withdraw(double amount){
			if (amount <= balance){
				balance -= amount;
				cout << "Transaction Successful!" << endl;
			}else{
				cout << "Insufficient Balance!" << endl;
			}
		}
		void displayAccountInfo(){
			cout << "\nAccount Number: " << accountNumber << endl;
			cout << "Account Holder Name: " << accountHolderName << endl;
			cout << "Balance: " << balance << endl << endl;
		}
		~BankAccount(){
			cout << "Account Object Destroyed!" << endl;
		}
};

int main(){
	BankAccount account(1, "Abdullah Bin Waqar");
	account.displayAccountInfo();
	
	account.withdraw(20000);
	
	account.deposit(15000);
	account.displayAccountInfo();
	
	account.withdraw(8000);
	
	account.displayAccountInfo();
}
