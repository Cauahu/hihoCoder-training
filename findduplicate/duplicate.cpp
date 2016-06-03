#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int numbers[] = {2,1,3,1,4}, duparray[5], duplication = 0;
    memset(duparray,0,5*sizeof(int));
    bool have_duplication = false;
	for(int i=0;i<5;++i)
		cout << duparray[i] << " ";
	cout << endl;
    for(int i=0;i<5;++i){
		int cur = numbers[i];
	    ++duparray[cur];
	    if(duparray[cur] == 2){
		    duplication = cur;
			have_duplication = true;
			break;
        }
    }
	cout << duplication << (have_duplication? "ture" : "false") << endl;
	return 0;
}
