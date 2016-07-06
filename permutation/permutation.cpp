#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string str;
	while(cin >> str){	
		vector<char> vec;
		int len = str.size();
		for(int i=0;i<len;++i)
			vec.push_back(str[i]);
		
		sort(vec.begin(), vec.end());
		
		do{
			vector<char>::iterator it = vec.begin();
			while(it != vec.end()){
				cout << *it;
				++it;
			}
			cout << endl;
		}	while(next_permutation(vec.begin(), vec.end()));

	}
	return 0;
}
