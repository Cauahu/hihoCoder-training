#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > transformImage(vector<vector<int> > mat, int n)
{
	for(int i = 0;i < n-1;++i)
	{
		for(int j=1;j < n;++j)
		{
			swap(mat[i][j], mat[j][i]);
		}
	}
	
	for(int i=0;i<n;++i)
	{
		int j = 0, k = n - 1;
       		while(j < k)
       			swap(mat[i][j++],mat[i][k--]);	
            		
	}


	for(int i=0;i < n;++i)
	{
		for(int j=0;j < n;++j)
			cout << mat[i][j] << " ";
		cout << endl;
	}
	
	return mat;
}

int main()
{
	int a[][3] = {1,2,3,4,5,6,7,8,9};
	vector<vector<int> > mat;
	mat.push_back(vector<int> (a[0],a[0]+3));
	mat.push_back(vector<int> (a[1],a[1]+3));
	mat.push_back(vector<int> (a[2],a[2]+3));

	transformImage(mat,3);
	
	return 0;
}

