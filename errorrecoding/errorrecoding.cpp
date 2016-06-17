/*
1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)只记录一条，错误计数增加；(文件所在的目录不同，文件名和行号相同也要合并)
2.超过16个字符的文件名称，只记录文件的最后有效16个字符；(如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
3.输入的文件可能带路径，记录文件名称不能带路径

将所有的记录统计并将结果输出，格式：文件名代码行数数目，一个空格隔开，如: fpgadrive.c 1325 1 

    结果根据数目从多到少排序，数目相同的情况下，按照输入第一次出现顺序排序。

    如果超过8条记录，则只输出前8条记录.

    如果文件名的长度超过16个字符，则只输出后16个字符
*/


    #include <iostream>
    #include <string>
    #include <utility>
    #include <vector>
    #include <algorithm>
    #include <fstream>

    using namespace std;

void dealinputstr(const string &str, vector<pair<string, int> > &records){
	int len = records.size();
	bool isinvec = false;
	for(int i=0;i<len;++i){
		if(records[i].first == str){
			++records[i].second;
			isinvec = true;
			break;
		}
	}
	if(!isinvec)
		records.push_back(make_pair(str, 1));
}

bool compare(const pair<string, int> p1, const pair<string, int> p2){
	return p1.second > p2.second;
}

    int main(int argc, char const *argv[])
    {
    	vector<pair<string, int> > records;
    	string fileerror;
    	ifstream fin("testdata.txt");
    	while(getline(fin, fileerror) ){
    		fileerror = fileerror.substr( fileerror.find_last_of('\\') + 1 , string::npos);
    		dealinputstr(fileerror, records);
    	}
    	sort(records.begin(), records.end(), compare);
    	for(int i=0,len = records.size();i < 8 && i < len;++i)
    		cout << records[i].first << " " << records[i].second << endl;
    	return 0;
    }


