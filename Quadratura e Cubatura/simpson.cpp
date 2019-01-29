/*
	Calculates integral of function in given interval using Simpson's rule
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float f(float x){
	return (x*x - 4*x + 3.5);
}

float simp(float a, float b, unsigned int ite){
	float h = (b - a) / ite;
	float sum1 = 0;
	float sum2 = 0;
	for(unsigned int i = 1; i < ite; i+=2){
		sum1 += f(a + i * h);
	}
	for(unsigned int i = 2; i < ite; i+=2){
		sum2 += f(a + i * h);
	}
	sum1 *= 4;
	sum2 *= 2;
	cout << sum1 << endl;
	sum1 += sum2 + f(a) + f(b);
	cout << sum1 << endl << endl;
	return ((h/3)*sum1);
}

int main(){
	cout << fixed << setprecision(6);
	
	float a = 0;
	float b = 3;
	unsigned int ite = 100;
	float s,sl,sll,err,qc;
	
	s = simp(a, b, ite);
	sl = simp(a, b, ite*2);
	sll = simp(a, b, ite*4);
	err = (sll - sl) / 15;
	qc = (sl - s) / (sll - sl);
	
	
	cout << "s: " << setw(10) << s << " | sl: " << setw(10) << sl << " | sll: " << setw(10) << sll << " | qc: " << setw(10) << qc << " | err: " << setw(10) << abs(err);
	
	return 0;
}
