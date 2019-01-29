/*
	Calculates integral of function in given interval using trapezoidal rule
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float f(float x){
	return (x*x - 4*x + 3.5);
}

float trap(float a, float b, unsigned int ite){
	float h = (b - a) / ite;
	float sum = 0;
	
	for(unsigned int i = 1; i < ite; i++){
		sum += f(a + i * h);
	}
	sum *= 2;
	sum += f(a) + f(b);
	return ((h/2)*sum);
}

int main(){
	cout << fixed << setprecision(6);
	
	float a = 0;
	float b = 3;
	unsigned int ite = 100;
	float s,sl,sll,err,qc;
	
	s = trap(a, b, ite);
	sl = trap(a, b, ite*2);
	sll = trap(a, b, ite*4);
	err = (sll - sl) / 3;
	qc = (sl - s) / (sll -sl);
	
	
	cout << "s: " << setw(10) << s << " | sl: " << setw(10) << sl << " | sll: " << setw(10) << sll << " | qc: " << setw(10) << qc << " | err: " << setw(10) << abs(err);
	
	return 0;
}
