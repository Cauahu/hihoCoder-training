#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
	string str = "1#2#3#4#5#6#7#8#9#";
	string::size_type pos = 0;
	while(pos != string::npos){
		pos = str.find('#');
		if(pos != string::npos)
			str.replace(pos, 1, " ");
	}

	cout << str << endl;
	return 0;
}
