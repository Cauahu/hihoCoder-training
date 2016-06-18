#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	string str1 = "10 2";
	string str2 = "2 10 1";
	string str3 = "2 10 1 2 3";
	int i = str1.find("10");
	str1.replace(i, 2, "A");
	i = str2.find("10");
	str2.replace(i, 2, "A");
	i = str3.find("10");
	str3.replace(i, 2, "A");
	cout << str1 << "\n" << str2 << "\n" << str3 << "\n" ;
		
	return 0;
}