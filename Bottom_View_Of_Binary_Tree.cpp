#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){

    vector<int> ans;
    if(!root) return ans;
    map<int,int> mp;
    queue<pair<BinaryTreeNode<int>*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto p=q.front();q.pop();
        BinaryTreeNode<int>* temp=p.first;
        int line=p.second;
        mp[line]=temp->data;
        if(temp->left!=NULL) q.push({temp->left,line-1});
        if(temp->right!=NULL) q.push({temp->right,line+1});
    }
    for(auto x:mp){
        ans.push_back(x.second);
    }
    return ans;
    // Write your code here.
    
}
