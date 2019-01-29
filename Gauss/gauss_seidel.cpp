/*
	Calculate solution for 3 variable, 3 equation system using gauss-seidel method
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const unsigned int col_max = 3;
const unsigned int line_max = 2;
	
void gauss(float m[line_max + 1][col_max + 1], float x[line_max+1], int ite){
	float x1=x[0], x2=x[1], x3=x[2];
	float z1, z2, z3;
	cout << "x1: " << setw(10) << x1 << " | x2: " << setw(10) << x2 << " | x3: " << setw(10) << x3 << endl;
	for(unsigned int i = 0; i < ite; i++){
		x1 = (m[0][col_max] - (m[0][1]*x2 + m[0][2]*x3))/m[0][0];
		x2 = (m[1][col_max] - (m[1][0]*x1 + m[1][2]*x3))/m[1][1];
		x3 = (m[2][col_max] - (m[2][0]*x1 + m[2][1]*x2))/m[2][2];
				
		cout << "x1: " << setw(10) << x1 << " | x2: " << setw(10) << x2 << " | x3: " << setw(10) << x3 << endl;
	}		
}


int main(){
	cout << fixed << setprecision(6);
	
	float matrix[line_max + 1][col_max + 1] = {{3,6,9,39},	// Matrix
												{2,5,-2,3},
						  						{1,3,-1,2}};
	float x[line_max+1] = {1,2,3};		// Starting guess
	int ite = 10;
	
	gauss(matrix,x,ite);
	
	return 0;
}
