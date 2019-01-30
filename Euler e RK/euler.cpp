/*

*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float f(float x, float y){
	return (x*x*0.5 - 2*x + 2);
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
	
	float a = -5;
	float b = 3;
	float h = 0.5;
	unsigned int ite = 100;
	
	
	euler(a, b, h, ite);
	return 0;
}
