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
	
	float x;
	
	for(unsigned int i = 0; i < ite; i++){
		x = (a*f(b) - b*f(a)) / (f(b) - f(a));
		cout << "a: " << setw(15) << a << " | b: " << setw(15) << b << " | x: " << setw(15) << x << endl; 
		if(f(x) * f(a) > 0){
			a = x;
		}else{
			b = x;
		}
	}
	
}

int main(){
	cout << fixed << setprecision(9);
	
	float a = 0;
	float b = 1;
	float ite = 100;
	
	
	biss(a, b, ite);
	return 0;
}
