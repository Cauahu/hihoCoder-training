#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int a[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
vector<int> fibonacci(a, a+10);

bool lucky(vector<int> vec){
	int len = vec.size();
	for(int i=0;i < len;++i){
		if(find(fibonacci.begin(), fibonacci.end(), vec[i]) == fibonacci.end())
			return false;
	}

	return true;
}

vector<int> getpositionofstr(string str){
	vector<int> vec;
	int pos = 1, len = str.size();
	for(int i=0;i<len;++i){
		if(str.substr(0,i+1).find(str[i])+1 != string::npos)
			vec.push_back(pos++);
	}
	return vec;

}
int main(int argc, char const *argv[])
{
	set<string> result;
	string str;
	cin >> str;
	int len = str.size();

	for (int i = 0; i < len; ++i)
	{
		for (int j = i; j < len; ++j)
		{
			string temp = str.substr(i, j-i+1);
			if( lucky( getpositionofstr(temp)))
				result.insert(temp);
		}
	}
	
	set<string> ::iterator it = result.begin();
	while(it != result.end())
		cout << *it++ << endl;
	return 0;
}