#include <iostream>
#include <vector>

using namespace std;

bool Find(int a[][5], int target)
{
	int r = 0, c = 4;
	bool flag = false;
	while(r < 5 && c > -1)
	{
		if(a[r][c] == target )
		{
			flag = true;
			return flag;
		}
		else if(a[r][c] > target)
			--c;
		else
			++r;
	}
	return flag;
}

int main()
{
	int a[][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
	int target = 12;

	cout << (Find(a, target)? "True" : "False") << endl;
}
