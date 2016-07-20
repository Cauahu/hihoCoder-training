#include <iostream>
#include <string>

using namespace std;

string replacespace(string iniString, int length)
{
	string result = "";
	for(int i=0;i<length;++i)
	{
		if(iniString[i] == ' ')
			result += "%20";
		else
			result += iniString[i];
	}

	return result;

}


int main()
{

	cout << replacespace("Mr John Smith", 13) << endl;
	return 0;

}
