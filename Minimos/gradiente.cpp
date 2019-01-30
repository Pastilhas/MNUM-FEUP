/*
	
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float f(float x, float y){
	return ( (x+2)*(x+2) + (y+2)*(y+2) - 5 );
}
float fx(float x, float y){
	return (2*(x+2));
}
float fy(float x, float y){
	return (2*(y+2));
}

	
void grad(float x0, float y0, float h, unsigned int ite){	
	float x=x0,y=y0,xn,yn;
	float fb = f(x,y);
	cout << "( " << setw(15) << x << " , " << setw(15) << y << " )" << endl;
	for(unsigned int i = 0; i < ite; i++){
		yn = y - h * fy(x,y);
		xn = x - h * fx(x,y);
		
		if(f(xn,yn) < fb){
			x = xn;
			y = yn;
			fb = f(x,y);
		}
		else{
			h = h/2;
		}
		cout << "( " << setw(15) << x << " , " << setw(15) << y << " )" << endl;
	}
	
	
}

int main(){
	cout << fixed << setprecision(6);
	
	float a = -1000;
	float b = 3958;
	float h = 0.1;
	unsigned int ite = 100;
	
	cout << "=================================== GRADIENT ===================================" << endl;
	grad(a, b, h, ite);
	return 0;
}
