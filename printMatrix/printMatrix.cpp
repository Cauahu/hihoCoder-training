#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int> > matrix){
	int xu = 0, xd = matrix.size()-1, yu = 0, yd = matrix[0].size()-1;
	while(xu < xd || yu < yd){
		for(int i= yu;i<=yd;i++)
			cout << matrix[xu][i] << " ";
		xu++;
		for(int i=xu;i<=xd;i++)
			cout << matrix[i][yd] << " ";
		yd--;
		for(int i=yd;i>=yu;i--)
			cout << matrix[xd][i] << " ";
		xd--;
		for(int i=xd;i>=xu;i--)
			cout << matrix[i][yu] << " ";
		yu++;
	}
}

int main(){
	vector<vector<int> > matrix;
	int a1[] = {1,2,3,4}, a2[] = {5,6,7,8}, a3[] = {9,10,11,12}, a4[] = {13,14,15,16};
	vector<int> v1(a1, a1+4), v2(a2, a2+4), v3(a3, a3+4), v4(a4, a4+4);
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);
	matrix.push_back(v4);

	printMatrix(matrix);
	return 0;
}

