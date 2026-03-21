#include <iostream>
using namespace std;

class Distance{
	private:
		int feet;
		int inches;
	public:
		Distance(int f, int i):feet(f){
			feet += i / 12;
    		inches = i % 12;
		}
		Distance operator + (const Distance& other)const{
			int ft = feet + other.feet;
			int in = inches + other.inches;
			
			ft += in/12;
			in %= 12;
			
			return Distance(ft, in);
		}
		friend ostream& operator << (ostream& out, const Distance& other);
};

ostream& operator << (ostream& out, const Distance& other){
	out << other.feet << " ft " << other.inches;
	out << (other.inches==1 ? " inch":" inches");
	return out;
}

int main(){
	Distance dist1(1, 11);
	Distance dist2(2, 2);
	
	Distance dist3 = dist1 + dist2;
	cout << dist3;

  return 0;
}
