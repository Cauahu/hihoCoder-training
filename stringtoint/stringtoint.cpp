#include <iostream>
#include <vector>

using namespace std;

bool stringToint(const char * s, int &num){
	int cur = 0, temp = 0, flag = 1;
	bool illegal = true;
	vector<int> numstack;
	if(s[cur] == '-')
	{
		flag = -1;
		cur++;
	}
	else if(s[cur] == '+')
		cur++;

	while(s[cur] != '\0')
	{
		temp = s[cur] - '0';
		if(temp > 0 && temp < 10)
			numstack.push_back(temp);
		else if(temp != 0)
		{
			illegal = false;
			return illegal;
		}
		cur++;
	}
	if(numstack.empty())
		numstack.push_back(0);
	int mult = 1, sum = 0;
	while(!numstack.empty())
	{
		sum += numstack.back()*mult;
		mult *= 10;
		numstack.pop_back();		
	}
	num = flag*sum;
	return illegal;
}

int main(){
	const char *a[4];
	a[0] = "+123";
	a[1] = "-123";
	a[2] = "0000";
	a[3] = "abc";
	int num, i = 0;
	while(i != 4)
	{
		if(stringToint(a[i], num))
			cout << num << endl;
		else
			cout << "illegal input!" << endl;
		i++;
	}


	return 0;
}
