#include <string>
#include <set>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;
	set<char> str_set;
	int len = str.size(), oldsize = str_set.size();
	for(int i=0;i <len;++i){
		str_set.insert(str[i]);
		if(oldsize == str_set.size()){
			cout << str[i] << endl;
			break;
		}
		else
			oldsize = str_set.size();
	}
	return 0;
}