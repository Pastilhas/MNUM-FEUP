/*
	Calculates an isolated zero on a given function in given interval
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float f(float x){
	return x*x*x*x + 2*x*x*x - x - 1;
}

void biss(float a, float b, unsigned int ite){
	
	float m;
	
	for(unsigned int i = 0; i < ite; i++){
		m = (a + b) / 2;
		cout << "a: " << setw(15) << a << " | b: " << setw(15) << b << " | m: " << setw(15) << m << endl; 
		if(f(m) * f(a) < 0){
			b = m;
		}else{
			a = m;
		}
	}
	
}

int main(){
	cout << fixed << setprecision(9);
	
	float a = 0;
	float b = 12;
	float ite = 10;
	
	
	biss(a, b, ite);
	return 0;
}
