#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	while(cin >> str)
	{
		string str_res = "";
		int len = str.size();
		for(int i=0;i<len;++i)
		{
			if(str_res.find(str[i]) == string::npos)
				str_res.append(1,str[i]);
				//str_res += str[i];
		}
		cout << str_res << endl;
	}
	return 0;
}
