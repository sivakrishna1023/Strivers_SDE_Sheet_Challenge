#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode<int> * root,int x,int &res){
            if(!root) return;
            if(root->val>x){
                 solve(root->left,x,res);
            }
            else{
                 res=root->val;
                 solve(root->right,x,res);
            } 
}
int floorInBST(TreeNode<int> * root, int X)
{
    int ans=-1;
    solve(root,X,ans);
    return ans;
    // Write your code here.
}
