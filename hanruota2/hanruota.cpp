#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int res = -1, cont = 0;
vector<int> temp, orignal;
void dfs(int n, int l, int m, int r)
{
	if(n == 0)
		return;
	dfs(n-1,l,r,m);
	temp[n-1]=r;
	++cont;
	if(temp == orignal)
		res = cont;
	dfs(n-1, m, l, r);	
}

int main()
{
	int n;
	while(cin >> n)
		cout << (1<<n) << endl;
	return 0;
}

