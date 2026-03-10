#include <iostream>
using namespace std;

class Item{
	private:
		int itemID;
		string name;
		double price;
		static int totalItems;
	public:
		Item(){
			itemID = 0;
			name = "";
			price = 0.0;
		}
		Item(string n, double p){
			itemID = totalItems+1;
			name = n;
			price = p;
			totalItems++;
		}
		void Display(){
			cout << "-Item ID: " << itemID;
			cout << "\t-Name: " << name;
			cout << "\t-Price: " << price << endl;
		}
		static int getTotalCount(){
			return totalItems;
		}
};

int Item::totalItems = 0;

int main(){
	Item* items[3];
	items[0] = new Item("Face Wash", 20.00);
	items[1] = new Item("Hand Wash", 13.40);
	items[2] = new Item("Soap", 15.80);
	
	for(int i=0; i<3; i++){
		items[i]->Display();
	}
	
	cout << "\n\n\tTotal Items: " << Item::getTotalCount();
	
	for(int i=0; i<3; i++){
		delete items[i];
	}
	return 0;
}
