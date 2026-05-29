#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;

class MatrixException:public exception{
	private:
		string e;
	public:
		MatrixException(string m):e(m){}
		const char* what() const noexcept override{
			return e.c_str();
		}
};

template <class T>
class matrix;

template <typename T>
T maxElement(matrix<T>& m);

template <class T>
class matrix{
	private:
		vector<vector<T>> data;
		int row, col;
	public:
		matrix(int r, int c):row(r), col(c){
			if(r>0 && c>0){
				data.resize(row, vector<T>(col));
			}else{
				throw MatrixException("Invalid Bounds!");
			}
		}
		vector<T>& operator[](int index){
			if(index>=0 && index<row){
				return data[index];
			}else{
				throw MatrixException("Invalid Index");
			}
		}
		const vector<T>& operator[](int index) const{
			if(index>=0 && index<row){
				return data[index];
			}else{
				throw MatrixException("Invalid Bound");
			}
		}
		matrix operator+(const matrix& m){
			if(m.col == col && m.row == row){
			matrix sum(row, col);
				for(int i=0; i<row; i++){
					for(int j=0; j<col; j++){
						sum.data[i][j] = m.data[i][j] + data[i][j];
					}
				}
				return sum;
			}else{
				throw MatrixException("Matrix dimensions do not match for addition!");
			}
		}
		void sortCols(){
			for(int i=0; i<col; i++){
				vector<T> sortedColumn;
				for(int j=0; j<row; j++){
					sortedColumn.push_back(data[j][i]);
				}
				sort(sortedColumn.begin(), sortedColumn.end());
				for(int k=0; k<row; k++){
					data[k][i] = sortedColumn[k];
				}
			}
		}
		void display() const {
	        for(int i=0;i<row;i++){
	            for(int j=0;j<col;j++)
	            {
	                cout<<data[i][j]<<" ";
	            }
	            cout<<endl;
	        }
    	}
    	
    	friend T maxElement<T>(matrix<T>&);
};

template <typename T>
T maxElement(matrix<T>& m){
	T max = m.data[0][0];
	for(int i=0; i<m.row; i++){
		for(int j=0; j<m.col; j++){
			if(max<m.data[i][j]){
				max = m.data[i][j];
			}
		}
	}
	return max;
}

int main(){
	try{
        matrix<int> A(3,3);
        matrix<int> B(3,3);

        // Fill Matrix A
        A[0][0]=9;
        A[0][1]=2;
        A[0][2]=7;

        A[1][0]=4;
        A[1][1]=8;
        A[1][2]=1;

        A[2][0]=6;
        A[2][1]=3;
        A[2][2]=5;

        // Fill Matrix B
        B[0][0]=1;
        B[0][1]=1;
        B[0][2]=1;

        B[1][0]=2;
        B[1][1]=2;
        B[1][2]=2;

        B[2][0]=3;
        B[2][1]=3;
        B[2][2]=3;


        cout<<"Matrix A:\n";
        A.display();

        cout<<"\nMatrix B:\n";
        B.display();


        // Addition
        matrix<int> C=A+B;

        cout<<"\nA+B:\n";
        C.display();


        // Maximum element
        cout<<"\nMaximum element in A: ";
        cout<<maxElement(A)<<endl;


        // Sort columns
        cout<<"\nMatrix A after sorting columns:\n";
        A.sortCols();
        A.display();


        // Dimension mismatch exception
        cout<<"\nTesting dimension mismatch:\n";

        matrix<int> X(2,2);

        matrix<int> Y=A+X;


    }catch(MatrixException& e){

        cout<<"\nException: "
            <<e.what()<<endl;
    }


    try{

        matrix<int> Z(3,3);

        cout<<"\nTesting invalid index:\n";

        Z[5][0]=100;

    }catch(MatrixException& e){

        cout<<"Exception: "
            <<e.what()<<endl;
    }

	return 0;
}
