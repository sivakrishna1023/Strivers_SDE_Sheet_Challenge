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
bool solve(BinaryTreeNode<int> *root,int Llimit,int Rlimit){
          if(!root) return true;

          if(root->data<Llimit || root->data>Rlimit) return false;
          if(root->left){
              if(!(solve(root->left,Llimit,root->data))) return false;
          }
          if(root->right){
              if(!(solve(root->right,root->data,Rlimit))) return false;
          }
          return true;
}
bool validateBST(BinaryTreeNode<int> *root) {
    return solve(root,-1e9,1e9);
    // Write your code here
}
