#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > finalpath;
void findpath(TreeNode* root, int expectNumber, vector<int> path, int cureentSum){
	void findpath(TreeNode* root, int expectNumber, vector<int> path, int cureentSum){
		path.push_back(root->val);
		cureentSum += root->val;
		if(cureentSum == expectNumber && root->left == NULL && root->right == NULL)
			finalpath.push_back(path);
        if(root->left != NULL)
        	findpath(root->left, expectNumber, path, cureentSum);    
		if(root->right != NULL)
			findpath(root->right, expectNumber, path, cureentSum);	
        path.pop_back();
	}
}

int main(){

	return 0;
}
