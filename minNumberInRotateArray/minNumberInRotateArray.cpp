#include <iostream>
#include <vector>

using namespace std;

int minNumberInRotateArray(vector<int> rotateArray){
	vector<int>::iterator beg = rotateArray.begin()+1;
	while(beg != rotateArray.end())
	{
		if(*(beg-1) > *beg)
			break;
		beg++;
	}

	return *beg;
}

int main()
{
}

