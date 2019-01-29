/*
	Calculate solution for 3 variable, 3 equation system using gauss method
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const unsigned int col_max = 3;
const unsigned int line_max = 2;
	
void gauss(float m[line_max + 1][col_max + 1]){	
	for(unsigned int diag = 0; diag <= line_max; diag++){
		for(unsigned int col = diag + 1; col <= col_max; col++){
			m[diag][col] /= m[diag][diag];
		}
		m[diag][diag] = 1;
		
		for(unsigned int line = diag + 1; line <= line_max; line++){
			for(unsigned int col = diag + 1; col <= col_max; col++){
				m[line][col] -= m[diag][col] * m[line][diag]; 
			}
			m[line][diag] = 0;
		}
		
		for(unsigned int line = 0; line <= line_max; line++){
			cout << "[ ";
			for(unsigned int col = 0; col <= col_max; col++){
				cout << setw(10) << m[line][col] << " ";
			}
			cout << " ]" << endl;
		}
		cout << endl << endl << endl;
	}
}

void jordan(float m[line_max + 1][col_max + 1]){	
	for(int diag = line_max - 1; diag >= 0; diag--){
		for(unsigned int col = col_max - 1; col > diag; col--){
			m[diag][col_max] = m[diag][col_max] - m[diag][col] * m[col][col_max];
			m[diag][col] = 0;
		}
		
		for(unsigned int line = 0; line <= line_max; line++){
			cout << "[ ";
			for(unsigned int col = 0; col <= col_max; col++){
				cout << setw(10) << m[line][col] << " ";
			}
			cout << " ]" << endl;
		}
		cout << endl << endl << endl;
	}
}

int main(){
	cout << fixed << setprecision(6);
	
	float matrix[line_max + 1][col_max + 1] = {{3,6,9,39},
												{2,5,-2,3},
						  						{1,3,-1,2}};
	
	cout << "====================== GAUSS METHOD ======================" << endl;
	gauss(matrix);
	cout << "=================== GAUSS-JORDAN METHOD ==================" << endl;
	jordan(matrix);
	return 0;
}
