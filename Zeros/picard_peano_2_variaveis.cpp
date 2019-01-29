/*
	Calculates the first zero on a given function after given x
	Needs function derivative
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float f1(float x, float y){	return sqrt((x*(y+5) - 1)/2);}
float f2(float x, float y){	return sqrt( x + log10(x));}

void pica2(float x0, float y0, unsigned int ite){
	float x = x0;
	float y = y0;
	float xn;
	float yn;
	
	cout << "x: " << setw(15) << x << " | y: " << setw(15) << y << endl;
	for(unsigned int i = 0; i < ite; i++){
		xn = f1(x,y);
		yn = f2(x,y);
		
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
	
	
	pica2(a, b, ite);
	return 0;
}
