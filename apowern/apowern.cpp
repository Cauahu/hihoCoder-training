#include <iostream>
#include <string>

using namespace std;

double PowerAriginal(double base, int exponent)
{
	if(exponent == 0)
		return 1;
	if(exponent == 1)
		return base;
	double result = PowerAriginal(base, exponent >> 1);
	result *= result;
	if(exponent & 1 == 1)
		result *= base;
	return result;
}

int main(){
	double base, result;
	int exponent;
	cin >> base >> exponent;
	cout << base << " power " << exponent << " is " << PowerAriginal(base, exponent) << endl;


}

