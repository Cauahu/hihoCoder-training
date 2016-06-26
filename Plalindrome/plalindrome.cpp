#include <iostream>
#include <string>

using namespace std;

int main(){
	string str;
	while(cin >> str){
		int len = str.size();
		int s = 0, e = len - 1;
		int time = 0;
		bool yes = true;
		while(s <= e)
		{
			if(time <= 1 && str[s] == str[e])
			{
				++s;
				--e;
			}
			else if(str[s] != str[e] && time == 0)
			{
				int temps = s+1,tempe = e-1;
				if(str[temps] == str[e])
					++s;
				else if(str[s] == str[tempe])
					--e;
				else
				{
					yes = false;
					break;
				}
				++time;
			}
			else
			{
				yes = false;
				break;
			}
		}
		cout << (yes? "YES" : "NO" ) << endl;
	}
	return 0;
}
