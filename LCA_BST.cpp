#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
TreeNode<int>*solution(TreeNode<int>*root,TreeNode<int>*p,TreeNode<int>*q){
    if(root==NULL){
        return NULL;
    }
    if(root->data>p->data && root->data>q->data){
          return solution(root->left,p,q);
    }
    else if(root->data<p->data && root->data<q->data){
          return solution(root->right, p,q);
    }
    else return root;
}
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
     return solution(root,P,Q);
	// Write your code here
}
