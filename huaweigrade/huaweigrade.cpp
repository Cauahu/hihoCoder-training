#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M ;
	int *a = new int[N];
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	for (int i = 0; i < N; ++i)
		cout << a[i];
	while(M--){
		char c;
		int num1, num2;
		cin >> c >> num1 >> num2;
		if(c == 'Q')
			cout << *max_element(a+num1-1,a+num2) << endl;
		else if(c == 'U')
			a[num1-1] = num2;
		else{
			cout << "input error" << endl;
			M++;
		}
	}
	delete [] a;
	return 0;
}