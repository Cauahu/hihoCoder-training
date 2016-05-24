#include <iostream>

using namespace std;

double PowerWithUnsigned(double base, int exponent){
	double result = 1.0;
	while(exponent){
		if(exponent&1 == 1)
			result *= base;
		base *= base;
		exponent = exponent >> 1;
	}
	return result;
}

double Power(double base, int exponent){
	int absExponent = exponent;
	if(exponent < 0)
		absExponent = -exponent;
	double result = PowerWithUnsigned(base, absExponent);
	if(exponent < 0)
		result = 1.0 / result;
	return result;
}
int main(){
	cout << Power(2.0, 4) << endl;
	cout << Power(2.0, -4) << endl;
	cout << Power(2.0, 0) << endl;

	return 0;
}
