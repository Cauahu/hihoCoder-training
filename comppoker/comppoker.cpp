#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string dealstring(string & str){
	int i = str.find("@");
	while( i != string::npos){
		str.replace(i, 1, "10");
		i = str.find("@");
	}
	return str;

}

int main(int argc, char const *argv[])
{
	string orignal;
	while(getline(cin, orignal)){
		string pokerstr1, pokerstr2;
		pokerstr1 = orignal.substr(0, orignal.find('-'));
		pokerstr2 = orignal.substr(orignal.find('-')+1);
		int i = pokerstr1.find("10");
		while( i != string::npos){
			pokerstr1.replace(i, 2, "@");
			i = pokerstr1.find("10");
		}
		i = pokerstr2.find("10");
		while(i != string::npos ){
			pokerstr2.replace(i, 2, "@");
			i = pokerstr2.find("10");
		}
		int len1 = pokerstr1.size(), len2 = pokerstr2.size();
		//the size of input pokers only have 1,3,9 7 and 11.
		if(len1 == 11 || len2 == 11)
			cout << (len1 == 11? pokerstr1:pokerstr2) << endl;
		else if(len1 == 7 && len2 == 7)
			cout << (pokerstr1[0] > pokerstr2[0] ? dealstring( pokerstr1 ):dealstring( pokerstr2 )) << endl;
		else if(len1 == 7 || len2 == 7)
			cout << (len1 == 7 ? dealstring( pokerstr1 ):dealstring( pokerstr2 ) ) << endl;
		else if(len1 == 9 && len2 == 9)
			cout << (pokerstr1[0] > pokerstr2[0] ? dealstring( pokerstr1 ):dealstring( pokerstr2 )) << endl;
		else if(len1 == 3 && len2 == 3)
			cout << (pokerstr1[0] > pokerstr2[0] ? dealstring( pokerstr1 ):dealstring( pokerstr2 ))  << endl;
		else if(len1 == 1 && len2 == 1)
			cout << (pokerstr1[0] > pokerstr2[0] ? dealstring( pokerstr1 ):dealstring( pokerstr2 ))  << endl;
		else
			cout << "ERROR" << endl;
	}
	return 0;
}