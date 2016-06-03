#include <iostream>

using namespace std;

bool matchcore(char* str, char* pattern){
	if(*str == '\0' && *pattern == '\0')
		return true;
	if(*str != '\0' && *pattern == '\0')
		return false;
	if(*(pattern+1) == '*'){
		if(*str == *pattern || *pattern == '.' && *str != '\0')
			return matchcore(str+1, pattern+2) || matchcore(str+1, pattern) || matchcore(str, pattern+2);
		else
			return matchcore(str, pattern+2);
	}

	if(*str == *pattern || (*pattern == '.' && *str != '\0'))
		return matchcore(str+1, pattern+1);
	return false;
}


int main(){
	char str[] = "aaa", pattern[] = "ab*ac*a";
	cout << (matchcore(str, pattern)? "true" : "false" ) << endl;
}
