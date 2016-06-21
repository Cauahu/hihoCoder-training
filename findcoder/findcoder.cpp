#include <iostream>
#include <utility>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

string toUpper(string s){
	cout << "runing toUpper......." << endl;
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	cout << "finish toUpper......." << endl;
	return s;
}

int  countstr(string str){
	cout << "runing countstr......." << endl;
	int pos = str.find("CODER") , num = 0;
	while(pos != string::npos){
		++num;
		pos = str.find("CODER", pos+1);
	}
	cout << "finish countstr......." << endl;
	return num;
}

bool comp(pair<string, int> pair1, pair<string, int> pair2){
	return pair1.second > pair2.second;
}
vector<pair<string , int> > findCoder(vector<string> A, int n) {
        // write code here
	cout << "runing findCoder......." << endl;
	vector<pair<string , int> > vecpair;
	for(int i=0;i<n;++i)
		vecpair.push_back(make_pair<string , int>(A[i], countstr(toUpper(A[i]))));
	sort(vecpair.begin(), vecpair.end(), comp);
	cout << "finish findCoder......." << endl;
	return vecpair;
}

int main(int argc, char const *argv[])
{
	vector<string> strvec;
	vector<pair<string , int> > vecpair;
	strvec.push_back("i am a coder");
	strvec.push_back("Coder Coder");
	strvec.push_back("Code");
	int len1 = strvec.size();
	for (int i = 0; i < len1; ++i)
	{
		/* code */
		cout << strvec[i] << endl;
	}
	vecpair = findCoder(strvec, strvec.size());
	int len = vecpair.size();
	for(int i=0;i<len;++i){
		if(vecpair[i].second > 0)
			cout << vecpair[i].first << endl;
	}

	return 0;
}