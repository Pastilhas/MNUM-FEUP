/*
	Calculates the first zero on a given function after given x
	Needs function derivative
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float f1(float x, float y){	return x*x - 4 - y;}
float f1x(float x, float y){	return 2*x;}
float f1y(float x, float y){	return -1;}

float f2(float x, float y){	return y-x;}
float f2x(float x, float y){	return -1;}
float f2y(float x, float y){	return 1;}

void tang2(float x0, float y0, unsigned int ite){
	float x = x0;
	float y = y0;
	float xn;
	float yn;
	float J;
	
	cout << "x: " << setw(15) << x << " | y: " << setw(15) << y << endl;
	for(unsigned int i = 0; i < ite; i++){
		J = f1x(x,y) * f2y(x,y) - f2x(x,y) * f1y(x,y);
		xn = x - (f1(x,y) * f2y(x,y) - f2(x,y) * f1y(x,y)) / J;
		yn = y - (f2(x,y) * f1x(x,y) - f1(x,y) * f2x(x,y)) / J;
		
		x = xn;
		y = yn;
		
		cout << "x: " << setw(15) << x << " | y: " << setw(15) << y << endl;
	}
}

int main(){
	cout << fixed << setprecision(9);
	
	float a = 10;
	float b = 8;
	unsigned int ite = 10;
	
	
	tang2(a, b, ite);
	return 0;
}
