#include <iostream>
#include <string>

using namespace std;

bool checkReverseEqual(string s1, string s2)
{
	if(s1.size() != s2.size())
		return false;
	int pos = (s1 + s1).find(s2);
	if(pos > 1)
		return true;
	return false;
}	


int main()
{
	cout << checkReverseEqual("Hello world", "worldhello") << endl;
	cout << checkReverseEqual("waterbottle", "erbottlewat") << endl;
	
}
