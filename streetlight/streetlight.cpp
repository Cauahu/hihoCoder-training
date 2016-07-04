#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	int n, l;
	while(cin >> n >> l){
		double * a = new double[n];
		for(int i=0;i<n;++i)
			cin >> a[i];

		sort(a, a+n);
	
		double distance = 0;
		for(int i=1;i<n;++i){
			double temp = (a[i] - a[i-1]) / 2;
			if(distance < temp)
				distance = temp;
		}
			cout << setiosflags(ios::fixed) << setprecision(2) << distance << endl;
	}

}
