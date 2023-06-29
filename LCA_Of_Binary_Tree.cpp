#include <bits/stdc++.h> 
/************************************************************
    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>*solution(TreeNode<int> *root,int x,int y){
    if(root==NULL || root->data==x || root->data==y){
        return root; 
    }
    TreeNode<int> * left=solution(root->left,x,y);
    TreeNode<int> *right=solution(root->right,x,y);
    if(left==NULL) return right;
    else if(right==NULL) return left;
    else return root;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    TreeNode<int> *ans=solution(root,x,y);
    return ans->data;
	//    Write your code here
}
