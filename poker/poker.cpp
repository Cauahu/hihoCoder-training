#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dealstring(const string& s )
{
	vector<int> vecs;
	int i=0, len = s.size();
	while(i < len)
	{
		char c = s[i++];
		switch (c)
		{
			case '1':
				vecs.push_back(10);
				++i;
				break;
			case 'J':
				vecs.push_back(11);
				break;
			case 'Q':
				vecs.push_back(12);
				break;
			case 'K':
				vecs.push_back(13);
				break;
			case 'A':
				vecs.push_back(15);
				break;
			default :
				vecs.push_back(c-'0');
		}
	}
	sort(vecs.begin(), vecs.end());
	return vecs;
}

int judgestring(const vector<int>& vec)
{
	if(vec[0] == vec[1] && vec[1] == vec[2])
		return 4;
	if(vec[1] == vec[0]+1 && vec[2] == vec[1]+1)
		return 3;
	if(vec[0] == vec[1] || vec[1] == vec[2])
		return 2;
	return 1;
}

int main()
{
	string s1, s2;
	while(cin >> s1 >> s2)
	{
		vector<int> vs1 = dealstring(s1);
		vector<int> vs2 = dealstring(s2);
		
		cout << vs1[0] << vs1[1] << vs1[2] << endl;
		cout << vs2[0] << vs2[1] << vs2[2] << endl;

		int type1 = judgestring(vs1), type2 = judgestring(vs2);
		if(type1 > type2)
			cout << "1" << endl;
		else if(type1 < type2)
			cout << "2" << endl;
		else
		{
			switch(type1)
			{
				case 1:
					if(vs1[2] == vs2[2]){
                        					if(vs1[1] == vs2[1]){
                            					if(vs1[0] == vs2[0])
					                            	cout << 0 << endl;
                            					else
	                            					cout << (vs1[0] > vs2[0]? 1:-1) << endl;
                      					}else	
                            					cout << (vs1[1] > vs2[1]? 1:-1) << endl;
                    				}else
	                        				cout << (vs1[2] > vs2[2]? 1:-1) << endl;
                				break;	
				case 2:
					if(vs1[1] == vs2[1])
						cout << 0 << endl;
					else
						cout << (vs1[1] > vs2[1]? 1:2) << endl;
					break;
				default:
				cout << (vs1[2]==vs2[2]? 0:	(vs1[2] > vs2[2]? 1:2)) << endl;

			}
		}


	}
}
