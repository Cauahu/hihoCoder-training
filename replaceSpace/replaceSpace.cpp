//length为牛客系统规定字符串输出的最大长度，固定为一个常数
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
		string s(str);
        int cur = 0, len = 0;
        while(len < s.size()){
            if(s[len] != ' ')
                str[cur++] = s[len++];
           	else{
                str[cur++] = '%';
                str[cur++] = '2';
                str[cur++] = '0';
		len++;
            }                
        }
        str[cur] = '\0';
	}
};

int main(){

	char str[100] = "hello world";
	Solution s;
	s.replaceSpace(str, 100);
	cout << str << endl;

	return 0;
}
