/*
	Calculates integral of function in given interval using Simpson's rule
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

float f(float x, float y){
	return (x*y);
}

float simp(float a, float b, float y, unsigned int ite){
	float h = (b - a) / ite;
	float sum1 = 0;
	float sum2 = 0;
	for(unsigned int i = 1; i < ite; i+=2){
		sum1 += f(a + i * h, y);
	}
	for(unsigned int i = 2; i < ite; i+=2){
		sum2 += f(a + i * h, y);
	}
	sum1 *= 4;
	sum2 *= 2;
	
	sum1 += sum2 + f(a, y) + f(b, y);
	return ((h/3.0f)*sum1);
}

float cuba(float x0, float x, float y0, float y, unsigned int ite){
	float h = (y-y0)/ite;
	float sum1 = 0;
	float sum2 = 0;
	
	
	for(unsigned int i = 1; i < ite; i++){
		if(i%2)
			sum1 += simp(x0, x, y0 + i*h, ite);
		else
			sum2 += simp(x0, x, y0 + i*h, ite);
	}
	
	sum1 *= 4;
	sum2 *= 2;
	sum1 = simp(x0, x, y0, ite) + sum1 + sum2 + simp(x0, x, y, ite);
	return ((h/3.0f)*sum1);
}

int main(){
	cout << fixed << setprecision(6);
	
	float x0 = 0;
	float x  = 3;
	float y0 = 0;
	float y	 = 3;
	unsigned int ite = 100;
	float s,sl,sll,err,qc;
	
	s 	= cuba(x0, x, y0, y, ite);
	sl 	= cuba(x0, x, y0, y, ite*2);
	sll = cuba(x0, x, y0, y, ite*4);
	err = (sll - sl) / 15;
	qc 	= (sl - s) / (sll - sl);
	
	
	cout << "s: " << setw(10) << s << " | sl: " << setw(10) << sl << " | sll: " << setw(10) << sll << " | qc: " << setw(10) << qc << " | err: " << setw(10) << abs(err);
	
	return 0;
}
