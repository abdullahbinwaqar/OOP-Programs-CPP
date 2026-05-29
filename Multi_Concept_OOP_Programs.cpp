///////////////////////////PHARMACY MANAGEMENT SYSTEM///////////////////////////

#include <iostream>
using namespace std;

class medicine{
	protected:
		string name;
		float price;
	public:
		medicine(string n, float p):name(n), price(p){}
		virtual void displayDetails() = 0;
};

class PrescriptionMedicine:virtual public medicine{
	protected:
		string doctorName, patientName, prescriptionDate;
	public:
		PrescriptionMedicine(string n, float p, string d, string pa, string da):
		medicine(n, p), doctorName(d), patientName(pa), prescriptionDate(da){}
		void displayDetails(){
			cout << "Name: " << name << endl;
			cout << "Price: " << price << endl;
			cout << "Doctor Name: " << doctorName << endl;
			cout << "Patient Name: " << patientName << endl;
			cout << "Prescription Date" << prescriptionDate << endl;
		}
};

class OTCMedicine:virtual public medicine{
	protected:
		int maxDailyDosage, ageRestriction;
	public:
		OTCMedicine(string n, float p, int d, int a):
		medicine(n, p), maxDailyDosage(d), ageRestriction(a){}
		void displayDetails(){ 
			cout << "Max Daily Dosage: " << maxDailyDosage << endl;
			cout << "Age Restriction: " << ageRestriction << endl;
		}
};

class both:public PrescriptionMedicine, public OTCMedicine{
	public:
		both(string n, float p, string dn, string pn, string pd, int m, int a):
		medicine(n, p), PrescriptionMedicine(n, p, dn, pn, pd), OTCMedicine(n, p, m, a){}
		void displayDetails(){
			cout << "Name: " << name << endl;
			cout << "Price: " << price << endl;
			cout << "Doctor Name: " << doctorName << endl;
			cout << "Patient Name: " << patientName << endl;
			cout << "Prescription Date" << prescriptionDate << endl;
			cout << "Max Daily Dosage: " << maxDailyDosage << endl;
			cout << "Age Restriction: " << ageRestriction << endl; 
		}
};


int main(){

    medicine* store[5];
	store[0] = new PrescriptionMedicine("Panadol", 250, "Dr. Ahmed", "Ali", "28-05-2026");
	store[1] = new OTCMedicine("Disprin", 120, 3, 12);
	store[2] = new both("Augmentin", 500,"Dr. Khan", "Usman", "27-05-2026",2, 18);
	store[3] = new PrescriptionMedicine("Brufen", 300,"Dr. Sara", "Hamza", "26-05-2026");
	store[4] = new OTCMedicine("Paracetamol", 100, 4, 10);

    for(int i = 0; i < 5; i++){
        store[i]->displayDetails();
        cout << endl;
    }

    for(int i = 0; i < 5; i++){
        delete store[i];
    }

    return 0;
}

///////////////////////////ELEMENT FINDER(STL + LINEAR SEARCH)///////////////////////////

#include <iostream>
#include <stdexcept>
using namespace std;

class error:public exception{
	private:
		string m;
	public:
		error(string e):m(e){}
		const char* what() const noexcept override{
			return m.c_str();
		}
};

template <typename T>
int search(T arr[], int s, T e){
	bool found = false;
	for(int i=0; i<s; i++){
		if(arr[i]==e){
			cout << "Found" << endl;
			found = true;
			return i;
		}
	}
	if(!found) throw error("Element not found in array!");
	return -1;
	
}
int main(){
	float arra[] = {4,534.5, 34,89.48, 8,6,5,4,43.5,6,6,5};
	int size = sizeof(arra)/sizeof(arra[0]);
	try{
		int f = search(arra, size, float(888));
		cout << "Found at index: " << f << endl;
	}catch(error& e){
		cout << e.what() << endl;
	}
	return 0;
}

///////////////////////////SHOOPING CART IMPLEMENTED USING STL///////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class item{
	protected:
		string* name;
		int* id;
		float* price;
		bool* in;
	public:
		item(string n, int i, float p, bool is){
			name = new string(n);
			id = new int(i);
			price = new float(p);
			in = new bool(is);
		}
		item(const item& i){
			name = new string(*i.name);
			id = new int(*i.id);
			price = new float(*i.price);
			in = new bool(*i.in);
		}
		~item(){
			delete name;
			delete id;
			delete price;
			delete in;
		}
		item& operator=(const item& i){
			if(this != &i){
				*name = *i.name;
				*id = *i.id;
				*price = *i.price;
				*in = *i.in;
			}
			return *this;
		}
		bool operator==(const item& i){
			return(*id == *i.id);
		}
		bool operator<(const item& i){
			return (*price<*i.price);
		}
		int getID()const{return *id;}
		bool getIn()const{return *in;}
		string getName()const{return *name;}
		void display() const{
	        cout << "Name: " << *name << endl;
	        cout << "ID: " << *id << endl;
	        cout << "Price: " << *price << endl;
	        cout << "In Stock: " << (*in ? "Yes" : "No") << endl;
    	}
};

class Cart{
	protected:
		vector<item> cart;
	public:
		void add(const item& i){
			if(!i.getIn()){
				cout << "Item not in stock!" << endl;
			}else{
				auto it = find_if(cart.begin(), cart.end(), [&](const item& Item){
					return i.getID()==Item.getID();
				});
				if(it != cart.end()){
					cout << "Item already exist in cart!" << endl;
				}else{
					cout << i.getName() << " added to cart!" << endl;
					cart.push_back(i);
				}
			}
		}
		void remove(int id){
			auto it = find_if(cart.begin(), cart.end(), [&](const item& i){
				return id == i.getID();
			});
			if(it!=cart.end()){
				cout << it->getName() << " removed successfully!" << endl;
				cart.erase(it);
			}else{
				cout << "No item exist with id: " << id << endl;
			}
		}
		void find(int id){
			auto it = find_if(cart.begin(), cart.end(), [&](const item& i){
				return id == i.getID();
			});
			if(it!=cart.end()){
				cout << it->getName() << " is found at your id: " << id << endl;
				
			}else{
				cout << "No item exist with id: " << id << endl;
			}
		}
		void displayCart(){
	        if(cart.empty()){
	            cout << "Cart is empty!" << endl;
	            return;
	        }
	        cout << "\nCart Items:\n";
	
	        for(const auto& i : cart){
	            i.display();
	            cout << "-------------------" << endl;
	        }
	    }
};

int main(){
	Cart c;

    item i1("Laptop", 101, 1200.5, true);
    item i2("Mouse", 102, 25.5, true);
    item i3("Keyboard", 103, 40.0, false);

    c.add(i1);
    c.add(i2);
    c.add(i3);

    c.displayCart();
    c.find(102);
    c.remove(102);
    c.displayCart();

    return 0;
}

///////////////////////////INHERITANCE USING SHAPE CLASSES///////////////////////////

#include <iostream>
using namespace std;

class Shape{
	protected:
		int id;
		static int unique;
	public:
		Shape(){
			id = unique;
			++unique;
		}
		virtual void draw() = 0;
		virtual ~Shape()=default;
};

int Shape::unique = 1;

class ColoredShape:virtual public Shape{
	protected:
		string color;
	public:
		ColoredShape(string c):Shape(), color(c){}
		void draw(){
			cout << "Drawing a colored shape!" << endl;
		}
};

class TexturedShape:virtual public Shape{
	protected:
		string texture;
	public:
		TexturedShape(string t):Shape(), texture(t){}
		void draw(){
			cout << "Drawing a textured shape!" << endl;
		}
};

class ColoredTexturedShape:public ColoredShape, public TexturedShape{
	public:
		ColoredTexturedShape(string c, string t):Shape(), ColoredShape(c), TexturedShape(t){}
		void draw(){
			cout << "Drawing a colored & textured shape!" << endl;
		}
};

int main(){
	Shape* shapes[3];
	shapes[0] = new ColoredShape("orange");
	shapes[1] = new TexturedShape("rough");
	shapes[2] = new ColoredTexturedShape("red", "smooth");
	
	shapes[0]->draw();
	shapes[1]->draw();
	shapes[2]->draw();
	
	delete shapes[0];
	delete shapes[1];
	delete shapes[2];
	return 0;
}

///////////////////////////MEDIAN FINDER USING TEMPLATE FUNCTION///////////////////////////

#include <iostream>
using namespace std;

template <typename T>
T median(T arr[], int s){
	for(int i=0; i<s-1; i++){
		for(int j=0; j<s-i-1; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}
	
	T median;
	if(s%2!=0){
		return arr[s/2];
	}else{
		return (((arr[s/2] + arr[(s/2) - 1]))/2);
	}
}

int main(){
	int arr1[] = {7, 2, 9, 1, 5};
	int size1 = 5;

	cout << "Median of integer array: " << median(arr1, size1) << endl;

	float arr2[] = {4.5, 2.1, 9.8, 1.2};
	int size2 = 4;

	cout << "Median of double array: " << median(arr2, size2) << endl;

	return 0;
}

///////////////////////////DYANAMIC CHARACTER STRING///////////////////////////

#include <iostream>
#include <cstring>
using namespace std;

class String{
	private:
		char* str;
		int length;
	public:
		String(const char* msg){
			length = strlen(msg);
			str = new char[length+1];
			strcpy(str, msg);
		}
		String(){
		    length = 0;
		    str = new char[1];
		    str[0] = '\0';
		}
		String(const String& other){
			length = other.length;
			str = new char[length+1];
			strcpy(str, other.str);
		}
		char getCharAt(int index){
			return str[index];
		}
		
		String operator+(const String& other){
			String temp;
			temp.length = other.length + length + 1;
			delete[] temp.str;
			temp.str = new char[temp.length+1];
			strcpy(temp.str, str);
			strcat(temp.str, " ");
			strcat(temp.str, other.str);
			
			return temp;
		}
		
		bool operator==(const String& other){
			return (strcmp(str, other.str) == 0);
		}
		void display() const{
			cout << str << endl;
		}
		
		~String(){
			delete[] str;
		}
		
		String& operator=(const String& other){
			if(this != &other){
				delete[] str;
				length = other.length;
				str = new char[length + 1];
				
				strcpy(str, other.str);
			}
			return *this;
		}
};

int main(){

    String s1("Hello");
    String s2("World");

    cout << "s1: ";
    s1.display();

    cout << "s2: ";
    s2.display();

    String s3 = s1 + s2;

    cout << "\ns3 = s1 + s2: ";
    s3.display();

    String s4(s1);

    cout << "\ns4 (copy of s1): ";
    s4.display();

    String s5;

    s5 = s2;

    cout << "\ns5 after assignment from s2: ";
    s5.display();

    if(s1 == s4){
        cout << "\ns1 and s4 are equal\n";
    }
    else{
        cout << "\ns1 and s4 are not equal\n";
    }

    if(s1 == s2){
        cout << "s1 and s2 are equal\n";
    }
    else{
        cout << "s1 and s2 are not equal\n";
    }

    cout << "\nCharacter at index 1 in s1: "
         << s1.getCharAt(1) << endl;

    return 0;
}
