#include <iostream>
using namespace std;

class Product{
	private:
		static int id;
		int productID;
		string name;
		double price;
		int quantity;
	public:
		Product(){
			productID = 0;
			name = "";
			price = 0.0;
		}
		Product(string n, double p, int qty){
			productID = id; id++;
			name = n;
			price = p;
			quantity = qty;
		}
		void displayProduct(){
			cout << "-Product ID: " << productID;
			cout << "\t-Name: " << name;
			cout << "\t-Price: " << price;
			cout << "\t-Quantity: " << quantity << endl;
		}
		double getPrice() const{
			return price;
		}
		int getQuantity() const{
			return quantity;
		}
};

class Cart{
	private:
		Product products[10];
		static int count;
		int index;
	public:
		Cart(){
			index = 0;
		}
		void addProduct(Product add){products[index] = add; index++;}
		double calculateTotalPrice()const{
			double total = 0.0;
			for(int i=0; i<=index; i++){
				total += (products[i].getPrice() * products[i].getQuantity());
			}
			return total;
		}
		void displayReceipt(){
			cout << "\n\n\t\t===RECEIPT\n\n";
			cout << "\t\tProduct(s)\n" << endl;
			for(int i=0; i<index; i++){
				products[i].displayProduct();
			}
			cout << "Total Number of Products: " << index << endl;
			cout << "\n\n\tAmount To Be Paid: " << calculateTotalPrice();
			
		}
};

int Product::id=1;

int main(){
	Product p1("Coffee", 2.0, 2);
	Product p2("Chocolate", 1.5, 4);
	Product p3("Chips", 3.0, 3);
	
	Cart checkout;
	checkout.addProduct(p1);
	checkout.addProduct(p2);
	checkout.addProduct(p3);
	
	checkout.displayReceipt();
	
	return 0;
}
