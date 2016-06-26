#include <iostream>
#include <vector>

using namespace std;

int main() {
	int p, n;
	while(cin >> p >> n){
		vector<int> vec(n);
		vector<int> vecp(p,0);
		int temp, pos = 0 ;
		for(int i=0;i<n;++i){
			cin >> temp;
			vec[i] = temp;
		}
		for(int i=0;i<n;++i)
		{
			int remaind = 0;
			remaind = vec[i] % p;
			if(vecp[remaind] == 1){
				pos = i;
				break;
			}
			else
				vecp[remaind] = 1;
		}
		if(pos != 0)
			cout << pos + 1 << endl;
		else
			cout << -1 << endl;
		
	}
	return 0;


}
