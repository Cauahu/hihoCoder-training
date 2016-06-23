#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int a[] = {5, 9, 13, 17, 19, 22, 23, 28, 33, 
		37, 39, 41, 44, 49, 52, 54, 59, 64, 66,
		 67, 72, 75, 77, 79, 84, 89, 94, 95,100, 
		 104, 107, 110, 113, 116, 117, 119, 120, 124 ,129,
		  133 ,137 ,142, 147, 148, 150, 153, 157, 158, 161,
		   162, 164, 168, 171, 176, 177, 179,184, 189, 193, 
		   197, 202, 203, 206, 211, 213, 216, 218, 223, 227, 
		   232, 235, 237, 240 
};
	vector<int> data(a, a+73);
	vector<int> gap;
	vector<int > result;
	int len = data.size();
	
	for (int i = 1; i < len-1; ++i)
		gap.push_back(data[i] - data[i-1]);

	int maxgap = *max_element(gap.begin(),gap.end()), gaplen = gap.size(), final = 1000, orignalmaxgap = maxgap;

	for (int i = 0; i <gaplen - 1 ; ++i)
	{
		if(gap[i] + gap[i+1] > maxgap )
			maxgap = gap[i] + gap[i+1] ;
		if(maxgap < final)
			final = maxgap;
		maxgap = orignalmaxgap;
	}

	cout << final << endl;

	return 0;
}