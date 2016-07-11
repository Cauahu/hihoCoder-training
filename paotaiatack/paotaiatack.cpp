#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int R, x1, y1, x2, y2, x3, y3, x0, y0;
	while(cin >> R >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x0 >> y0)
	{
		int num = 0;
		int r1 = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
		cout << r1 << endl;
		int r2 = (x2 - x0) * (x2 - x0) + (y2 - y0) * (y2 - y0);
		cout << r2 << endl;
		int r3 = (x3 - x0) * (x3 - x0) + (y3 - y0) * (y3 - y0);
		cout << r3 << endl;
		cout << R*R << endl;
		if(r1 <= R * R)
			++num;		
		if(r2 <= R * R)
			++num;
		if(r3 <= R * R)
			++num;
		cout << num << "x" << endl;

	}
}
