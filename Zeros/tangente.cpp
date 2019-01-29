/*
	Calculates the first zero on a given function after given x
	Needs function derivative
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float f(float x){
	return x*x - 4;
}

float fl(float x){
	return 2*x;
}

void tang(float x0, unsigned int ite){
	float x = x0;
	
	cout << "x: " << setw(15) << x << endl;
	for(unsigned int i = 0; i < ite; i++){
		x = x - f(x) / fl(x);
		cout << "x: " << setw(15) << x << endl;
	}
}

int main(){
	cout << fixed << setprecision(9);
	
	float a = -100;
	unsigned int ite = 10;
	
	
	tang(a, ite);
	return 0;
}
