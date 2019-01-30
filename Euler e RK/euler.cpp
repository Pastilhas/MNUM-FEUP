/*

*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float f(float x, float y){
	return (x*x*0.5 - 2*x + 2);
}

void melhor(float x0, float y0, float y, float h, unsigned int ite){
	float xn=x0, yn=y0, p, pl, yb = y;
	
	cout << "( " << setw(15) << xn << " , " << setw(15) << yn << " )" << endl;
	for(unsigned int i = 0; i < ite; i++){
		
		p = yb + 2*h*f(xn,yn);
		pl = f(xn+h,p);
		
		yb = yn;
		yn = yn + (pl + f(xn,yn))/2;
		xn = xn + h;
		cout << "( " << setw(15) << xn << " , " << setw(15) << yn << " )" << endl;
	}
}

void euler(float x0, float y0, float h, unsigned int ite){
	float xn=x0,yn=y0;
	
	cout << "( " << setw(15) << xn << " , " << setw(15) << yn << " )" << endl;
	for(unsigned int i = 0; i < ite; i++){
		yn = yn + h*f(xn,yn);
		xn = xn + h;
		cout << "( " << setw(15) << xn << " , " << setw(15) << yn << " )" << endl;
	}
}

int main(){
	cout << fixed << setprecision(9);
	
	float a = 0;
	float b = 3;
	float c = 2;
	float h = 0.125;
	unsigned int ite = 40;
	
	cout << "=================================== EULER ===================================" << endl;
	euler(a, b, h, ite);
	
	cout << "=================================== MELHOR ===================================" << endl;
	melhor(a, b, c, h, ite);
	return 0;
}
