#include <iostream>
#include <map>

using namespace std;


int Fibonacci(int n) {
	int a[2] = {0, 1};
	if(n < 2){
		return a[n];
	}

	int fibone = 1, fibtwo = 0, fibn = 0;
	for(int i = 2; i <= n ;i++){
		fibn = fibone + fibtwo;
		fibone = fibtwo;
		fibone = fibn;
	}
	return fibn;
}

int main(){
	
	return 0;
}
