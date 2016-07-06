#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n , m ;
	while(cin >> n >> m){
		vector<vector<int> > vec;
	
		for (int i = 0; i < n; ++i)
		{
			vector<int> a;
			for(int j=0;j<m;++j){
				int num;
				cin >> num;
				a.push_back(num);
			}
			vec.push_back(a);
		}

				long long max = 0;
        
		for(int i=0;i<n;i++){
	            for(int j=0;j<m;j++){
	                long long temp = 1;
	                for(int k=0;k<m;k++){
	                    if(k == j)
	                        continue;
	                    else
	                        temp *= vec[i][k];
	                }
	                for(int k=0;k<n;k++){
	                    if(k == i)
	                        continue;
	                    else
	                        temp *= vec[k][j];
	                }
	                if(temp > max){
	                    max = temp;
	                }
	            }
	        }
		
		cout << max << endl;
	}
	

	return 0;
}
