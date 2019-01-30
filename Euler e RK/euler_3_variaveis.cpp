/*

*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float f1(float x, float y, float z){
	return (z);
}
float f2(float x, float y, float z){
	return (1.5 + x*x + x*z);
}

void euler(float x0, float y0, float z0, float h, unsigned int ite){
	float xn=x0, yn=y0, zn=z0;
	float x=x0, y=y0, z=z0;
	
	cout << "( " << setw(15) << xn << " , " << setw(15) << yn << " , " << setw(15) << zn << " )" << endl;
	for(unsigned int i = 0; i < ite; i++){
		yn = y + h*f1(x,y,z);
		zn = z + h*f2(x,y,z);
		xn = xn + h;
		
		z = zn; y = yn;
		
		cout << "( " << setw(15) << xn << " , " << setw(15) << yn << " , " << setw(15) << zn << " )" << endl;
	}
}

int main(){
	cout << fixed << setprecision(9);
	
	float a = -5;
	float b = 3;
	float c = 3;
	float h = 0.5;
	unsigned int ite = 100;
	
	
	euler(a, b, c, h, ite);
	return 0;
}
