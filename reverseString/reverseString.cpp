#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string reverseString(string iniString)
{
	int i = 0, j = iniString.size() - 1;

	while(i < j)
	{
		swap(iniString[i], iniString[j]);
		++i;
		--j;
	}

	return iniString;
}

int main()
{
	cout << "This is nowcoder\n" << reverseString("This is nowcoder") << endl;
}
