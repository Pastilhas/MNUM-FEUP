/*

*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float f1(float x, float y, float z){
	return (x*x*0.5 - 2*x + 2);
}
float f2(float x, float y, float z){
	return (x*x*0.5 - 2*x + 2);
}

void rk(float x0, float y0, float z0, float h, unsigned int ite){
	float xn=x0, yn=y0, zn=z0;
	float x=x0,y=y0,z=z0;
	
	cout << "( " << setw(15) << xn << " , " << setw(15) << yn << " )" << endl;
	for(unsigned int i = 0; i < ite; i++){
		zn = z + h*f2(x + (h/2.0f), y + (h/2.0f)*f1(x,y,z), z + (h/2.0f)*f2(x,y,z));
		yn = y + h*f1(x + (h/2.0f), y + (h/2.0f)*f1(x,y,z), z + (h/2.0f)*f2(x,y,z));
		xn = xn + h;
		
		z = zn;
		y = yn;		
		
		cout << "( " << setw(15) << xn << " , " << setw(15) << yn << " )" << endl;
	}
}

void rk4(float x0, float y0, float z0, float h, unsigned int ite){
	float xn=x0,yn=y0,zn=z0;
	float d1,d2,d3,d4;
	float e1,e2,e3,e4;
	
	cout << "( " << setw(15) << xn << " , " << setw(15) << yn << " , " << setw(15) << zn << " )" << endl;
	for(unsigned int i = 0; i < ite; i++){
		
		d1 = h * f1(xn,yn,zn);
		e1 = h * f2(xn,yn,zn);
		
		d2 = h * f1(xn + h/2.0f, yn + d1/2.0f, zn + e1/2.0f);		
		e2 = h * f2(xn + h/2.0f, yn + d1/2.0f, zn + e1/2.0f);
		
		d3 = h * f1(xn + h/2.0f, yn + d2/2.0f, zn + e2/2.0f);
		e3 = h * f2(xn + h/2.0f, yn + d2/2.0f, zn + e2/2.0f);		
		
		d4 = h * f1(xn + h, yn + d3, zn + e3);
		e4 = h * f2(xn + h, yn + d3, zn + e3);
		
		zn = zn + (e1 + 2*e2 + 2*e3 + e4)/6.0f;
		yn = yn + (d1 + 2*d2 + 2*d3 + d4)/6.0f;	
		xn = xn + h;
		cout << "( " << setw(15) << xn << " , " << setw(15) << yn << " , " << setw(15) << zn << " )" << endl;
	}
}

int main(){
	cout << fixed << setprecision(9);
	
	float a = -5;
	float b = 3;
	float c = 3;
	float h = 0.5;
	unsigned int ite = 40;
	
	
	cout << "=================================== RK ===================================" << endl;
	rk(a, b, c, h, ite);
	
	cout << "\n=================================== RK4 ===================================" << endl;
	rk4(a, b, c, h, ite);
	return 0;
}
