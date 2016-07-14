#include <iostream>

using namespace std;

int steps;
void dfs(int n, string l, string m, string r)
{
	if(n == 0) return;
	//现将n-1层移动到中间
	dfs(n-1, l, r, m);

	//再将n层移动到右边
	cout << "the " << ++steps << " steps: " << "move from " << l << " to " << r << endl;

	//最后将中间层移动到右边
	dfs(n-1, m, l, r);
}

int main()
{
	int n;

	while(cin >> n){
		steps = 0;
		dfs(n, "left", "mid", "right");
	}
	return 0;

}
