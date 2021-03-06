#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string sortword(const string word){
	char alphabet[26];
	string result;
	for(int i=0,len=word.size();i < len;i++){
		alphabet[word[i]-'a'] = 1;
	}
	for(int i=0;i < 26;i++){
		if(alphabet[i]==1)
			result += i+'a';
	}
	return result;
}

void signWordFun(const vector<string> origanlwords, map<string, vector<string> > &signWordsMap){
	for( vector<string>::const_iterator it = origanlwords.begin();it!=origanlwords.end();it++){
		string sign = sortword(*it);
		map<string, vector<string> >::iterator mapit = signWordsMap.find(sign);
		if(mapit!=signWordsMap.end())
		{
			mapit->second.push_back(*it);
		}
		else{
			vector<string> newvec;
			newvec.push_back(*it);
			signWordsMap.insert(make_pair(sign, newvec));
		}
	}
}

int main(){
	string words[] = {"tops", "stop",  "snap", "opt", "pans", "pots" };
	vector<string> origanlwords(words, words+6);
	map<string, vector<string> > signWordsMap;
	signWordFun(origanlwords, signWordsMap);
	for(map<string, vector<string> >::const_iterator it=signWordsMap.begin();it!=signWordsMap.end();it++){
		vector<string>::const_iterator vecit = it->second.begin();
		while(vecit != it->second.end() ){
			cout << *vecit << " ";
			vecit++;
		}
		cout << endl;
	}
}
