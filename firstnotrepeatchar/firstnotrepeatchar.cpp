#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int FirstNotrepeatchar(string str){
	if(str.empty())
            return -1;
        vector<char> vec_char;
        vector<int> vec_count;
        int i=0;
        while(i != str.size()){
			cout << str[i] << endl;
            vector<char>::iterator it = find(vec_char.begin(), vec_char.end(), str[i]);
            if(it == vec_char.end()){
                vec_char.push_back(str[i]);
                vec_count.push_back(1);
            }else{
                int dif = it - vec_char.begin();
                ++vec_count[dif];
				cout << *it << dif << " " << vec_count[dif] << endl;
            }
            ++i;
        }
		vector<int>::iterator it = find(vec_count.begin(), vec_count.end(), 1);

        return str.find(vec_char[it-vec_count.begin()]);
}


int FirstNotRepeatingChar(string str) {
         
         
        if (str.length() == 0)
            return -1;
        int hashTable[256];
        for (int i = 0; i < 256; i++)
            hashTable[i] = 0;
        for (int i = 0; i < str.size(); i++) {
            hashTable[str[i]]++;
        }
        int pos=-1;
        for (int i = 0; i < str.size(); i++) {
            if (hashTable[str[i]] == 1) {
 
                pos = i;
                break;
            }
        }
        return pos;
 
    }
int main(){
	string str("google");
	cout << FirstNotrepeatchar(str) << endl;
	return 0;
}
