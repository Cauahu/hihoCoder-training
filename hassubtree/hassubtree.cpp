#include <iostream>

using namespace std;

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
	bool result = false;
	if(pRoot1 != NULL && pRoot2 != NULL){
		if(pRoot1->val == pRoot2->val)
			result = isTree1EqualTree2(pRoot1, pRoot2);
		if(!result)
			result = HasSubtree(pRoot1->left, pRoot2);
		if(!result)
			result = HasSubtree(pRoot1->right, pRoot2);
	}
	return result;
}

bool isTree1EqualTree2(TreeNode *pRoot1, TreeNode *pRoot2){
	if(pRoot2 == NULL)
		return true;
	if(pRoot1 == NULL)
		return false;
	if(pRoot1->val != pRoot2->val)
		return false;
	return isTree1EqualTree2(pRoot1->left, pRoot2->left) && isTree1EqualTree2(pRoot1->right, pRoot2->right);
	
}
