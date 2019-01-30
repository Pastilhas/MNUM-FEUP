/*
	
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float f(float x){
	return (x+2)*(x+2);
}
	
void terc(float a, float b, float interval){	
	float c,d;
	int i;
	while(abs(b-a) > interval && i < 100){
		c = (1.0f/3) * abs(b-a) + a;
		d = (2.0f/3) * abs(b-a) + a;
		cout << setw(15) << a << " | " << setw(15) << c << " | " << setw(15) << d << " | " << setw(15) << b << " | ite: " << setw(3) << i << endl;
		
		if(f(c) < f(d)){
			b = d;
		}else{
			a = c;
		}
		i++;
	}
	
	cout << setw(15) << a << " | " << setw(15) << c << " | " << setw(15) << d << " | " << setw(15) << b << " | ite: " << setw(3) << i << endl;
}

void aure(float a, float b, float interval){	
	float c,d;
	int i;
	while(abs(b-a) > interval && i < 100){
		c = pow((sqrt(5) - 1)/2.0f, 2) * abs(b-a) + a;
		d = (sqrt(5) - 1)/2.0f * abs(b-a) + a;
		cout << setw(15) << a << " | " << setw(15) << c << " | " << setw(15) << d << " | " << setw(15) << b << " | ite: " << setw(3) << i << endl;
		
		if(f(c) < f(d)){
			b = d;
		}else{
			a = c;
		}
		i++;
	}
	
	cout << setw(15) << a << " | " << setw(15) << c << " | " << setw(15) << d << " | " << setw(15) << b << " | ite: " << setw(3) << i << endl;
}

int main(){
	cout << fixed << setprecision(6);
	
	float a = -1000;
	float b = 1000;
	float h = 0.000001;
	
	cout << "=================================== THIRDS ===================================" << endl;
	terc(a, b, h);
	
	cout << "=================================== GOLDEN ===================================" << endl;
	aure(a, b, h);
	return 0;
}
