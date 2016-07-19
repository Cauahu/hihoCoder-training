#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool checkDifferent(string iniString)
{
	//ascii字符集只有256个字符
	if(iniString.size() > 256)
		return false;

	int loop = 0;
	int len = iniString.size();
	for(int i=0;i<len;++i)
	{
		int val = 1 << (iniString[i] - 'a');
		if((loop & val) > 0)
			return false;
		loop |= val;
	}

	return true;
}


int main()
{

	cout << checkDifferent("aeiou") << endl;
	cout << checkDifferent("barackobama") << endl;

	return 0;
}

