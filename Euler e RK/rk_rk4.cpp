/*

*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float f(float x, float y){
	return (x*x*0.5 - 2*x + 2);
}

void rk(float x0, float y0, float h, unsigned int ite){
	float xn=x0,yn=y0;
	
	cout << "( " << setw(15) << xn << " , " << setw(15) << yn << " )" << endl;
	for(unsigned int i = 0; i < ite; i++){
		yn = yn + h*f(xn + (h/2.0f), yn + (h/2.0f)*f(xn,yn));
		xn = xn + h;
		cout << "( " << setw(15) << xn << " , " << setw(15) << yn << " )" << endl;
	}
}

void rk4(float x0, float y0, float h, unsigned int ite){
	float xn=x0,yn=y0;
	float d1,d2,d3,d4;
	
	cout << "( " << setw(15) << xn << " , " << setw(15) << yn << " )" << endl;
	for(unsigned int i = 0; i < ite; i++){
		
		d1 = h * f(xn,yn);
		d2 = h * f(xn + h/2.0f, yn + d1/2.0f);
		d3 = h * f(xn + h/2.0f, yn + d2/2.0f);
		d4 = h * f(xn + h, yn + d3);
		
		yn = yn + (d1 + 2*d2 + 2*d3 + d4)/6.0f;	
		xn = xn + h;
		cout << "( " << setw(15) << xn << " , " << setw(15) << yn << " )" << endl;
	}
}

int main(){
	cout << fixed << setprecision(9);
	
	float a = -5;
	float b = 3;
	float h = 0.5;
	unsigned int ite = 40;
	
	
	cout << "=================================== RK ===================================" << endl;
	rk(a, b, h, ite);
	
	cout << "\n=================================== RK4 ===================================" << endl;
	rk4(a, b, h, ite);
	return 0;
}
