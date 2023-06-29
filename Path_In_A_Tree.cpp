#include <bits/stdc++.h>
/*
    template <typename T = int>
        class TreeNode
        {
                public:
                T data;
                TreeNode<T> *left;
                TreeNode<T> *right;

                TreeNode(T data)
                {
                        this->data = data;
                        left = NULL;
                        right = NULL;
                }
                ~TreeNode()
                {
                        if (left != NULL)
                        {
                                delete left;
                        }
                        if (right != NULL)
                        {
                                delete right;
                        }
                }
        };
*/
bool solve(TreeNode<int>*root,int x,vector<int>&v){
	if(!root) return false;
	v.push_back(root->data);
	if(root->data==x) return true;
	if(root->left){
		if(solve(root->left,x,v)) return true;
	}
	if(root->right){
		if(solve(root->right,x,v)) return true;
	}
	v.pop_back();
	return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
	vector<int> ans;
	solve(root,x,ans);
	//reverse(ans.begin(),ans.end());
	return ans;
    // Write your code here.
}
