#include <iostream>
using namespace std;

class Item{
	protected:
		string Name;
		int quantity;
	public:
		Item(string n, int qty) : Name(n), quantity(qty){}
		virtual double calculateBill() = 0;
		virtual ~Item() {}
};	

class BakedGoods : public Item{
	protected:
		float discount = 0.1;
	public:
		BakedGoods(string n, int qty) : Item(n, qty){}
		virtual double calculateBill() = 0;
};

class Cakes : public BakedGoods{
	protected:
		int price = 600;
	public:
		Cakes(string n, int qty) : BakedGoods(n, qty){}
		double calculateBill() {
			cout << "-Name: " << Name;
			cout << "\t-Price: " << price;
			cout << "\t-Quantity: " << quantity << endl;
			return price * (1 - discount) * quantity;
		}
};

class Bread : public BakedGoods{
	private:
		int price = 200;
	public:
		Bread(string n, int qty) : BakedGoods(n, qty){}
		double calculateBill(){
			cout << "-Name: " << Name;
			cout << "\t-Price: " << price;
			cout << "\t-Quantity: " << quantity << endl;
			return price * (1 - discount) * quantity;
		}
};

class Drinks : public Item{
	private:
		double discount = 0.05;
		int price = 100;
	public:
		Drinks(string n, int qty) : Item(n, qty){}
		double calculateBill(){
			cout << "-Name: " << Name;
			cout << "\t-Price: " << price;
			cout << "\t-Quantity: " << quantity << endl;
			return price * (1 - discount) * quantity;
		}	
};

int main(){
	int c, b, d;
	int itemsAvailable = 3;
	double  total = 0;
	Item* items[itemsAvailable];
	cout << "\t\t===Welcome To Billing System===\n\n" << endl;
	cout << "Enter Number of Cakes: ";
	cin >> c;
	cout << "Enter Number of Breads: ";
	cin >> b;
	cout << "Enter Number of Drinks: ";
	cin >> d;
	
	items[0] = new Cakes("Cake", c);
	items[1] = new Bread("Bread", b);
	items[2] = new Drinks("Drink", d);
	
	cout << "\t\t===RECEIPT===\n" << endl;
	for(int i=0; i<itemsAvailable; i++){
		total += items[i]->calculateBill();
	}
	cout << "\n\n\t\tAmount To Be Paid: " << total << endl;
	
	for(int i=0; i<itemsAvailable; i++){
    	delete items[i];
	}
	
	return 0;
}
