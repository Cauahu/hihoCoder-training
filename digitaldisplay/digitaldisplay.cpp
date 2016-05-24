#include <iostream>
#include <algorithm>

using namespace std;

const int displayArray[] = {0xf999f, 0x22222, 0xf1f8f, 0xf8f8f, 0x88f99, 0xf8f1f, 0xf9f1f, 0x44447, 0xf9f9f, 0xf8f9f};

void displaybydigitalnumber(int num){
	int cur = 1, p0 = displayArray[num];
	while(cur != 21){
	if(p0&1 == 1)
		cout << "*";
	else
		cout << " ";
	p0 = p0>>1;
	if(cur%4==0)
		cout << endl;
		cur++;
	}

}

int main(){
	for(int i=0;i<10;i++){
		displaybydigitalnumber(i);
		cout << endl;
	}
}
