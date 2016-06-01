#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

bool compare(const string &s1, const string &s2){
	string str1 = s1 + s2;
	string str2 = s2 + s1;
	return str1 < str2;
}

void PrintMinNumber(vector<int> numbers){
	int len = numbers.size();
	vector<string> str(len);
	for(int i=0;i<len;++i){
		stringstream ss;
		ss << numbers[i];
		ss >> str[i];
	}
	sort(str.begin(), str.end(), compare);
	string resStr;
	for(int i=0;i<len;++i){
		cout << str[i] << " ";
		resStr = resStr + str[i];
	}
	cout << "\n" << resStr << endl;
}


int main(){
	int a[] = {3,32,321};
	vector<int> vec(a,a+3);;
	PrintMinNumber(vec);
	return 0;
}
