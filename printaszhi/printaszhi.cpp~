vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > result;
        if(pRoot == NULL)
            return result;
        stack<TreeNode *> levels[2];
        vector<int> vec;
        int current = 0;
        int next = 1;
        levels[current].push(pRoot);
        while(!levels[0].empty() || !levels[1].empty()){
            
            TreeNode* pNode = levels[current].top();
            levels[current].pop();
            vec.push_back(pNode->val);
            if(current == 0){
                if(pNode->left != NULL)
                    levels[next].push(pNode->left);
                if(pNode->right != NULL)
                    levels[next].push(pNode->right);
            }
            else{
                if(pNode->right != NULL)
                    levels[next].push(pNode->right);
                if(pNode->left != NULL)
                    levels[next].push(pNode->left);
            }
            
            if(levels[current].empty()){
                result.push_back(vec);
                vec.clear();
                current = 1 - current;
                next = 1 - next;
            }
        }
        return result;
    }    
