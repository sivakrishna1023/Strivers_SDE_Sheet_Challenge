#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int istrue(BinaryTreeNode<int>* root){
    if(!root) return 0;
    int l=istrue(root->left);
    if(l==-1) return -1;
    int r=istrue(root->right);
    if(r==-1) return -1;
    if(abs(l-r)>1) return -1;
    return max(l,r)+1;
    
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
     return (istrue(root)!=-1);
    // Write your code here.
}
