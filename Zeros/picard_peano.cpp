/*
	Calculates intersection of function with y = x
	f(x) = 0  =>  x = g(x)
	the derivative of g(x) must be between -1 and 1 or it will tend to infinite
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float f(float x){
	return log(x) + 10;
}

void pica(float x0, unsigned int ite){
	float x = x0;
	
	cout << "x: " << setw(15) << x << endl;
	for(unsigned int i = 0; i < ite; i++){
		x = f(x);
		cout << "x: " << setw(15) << x << endl;
	}
}

int main(){
	cout << fixed << setprecision(9);
	
	float a = 1;
	unsigned int ite = 10;
	
	
	pica(a, ite);
	return 0;
}
