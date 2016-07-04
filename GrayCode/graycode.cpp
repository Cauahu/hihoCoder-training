#include <isotream>

using namespace std;

vector<string> vec(1<<n,"");
        vec[0]=string(n,'0');
		        for(int i=0;i<n;++i){
					            int num=1<<i;
								            for(int j=0;j<num;++j){
												                vec[num+j]=vec[num-j-1];
																                vec[num+j][n-1-i]='1';
																				            }
											        }
        return vec;
