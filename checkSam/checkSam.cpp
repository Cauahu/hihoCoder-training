#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool checkSam(string stringA, string stringB)
{
	if(stringA.size() != stringB.size())
		return false;

	int temp[256] = {0};
	int lenA = stringA.size(), lenB = stringB.size();

	for(int i=0;i<lenA;++i)
		++temp[stringA[i]];

	for(int i=0;i<lenB;++i)
	{
		--temp[stringB[i]];
		if(temp[stringB[i]] < 0)
			return false;
	}

	return true;
}

int main()
{
	cout << checkSam("This is nowcoder","is This nowcoder") << endl;
	cout << checkSam("Here you are", "Are you here") << endl;
}

