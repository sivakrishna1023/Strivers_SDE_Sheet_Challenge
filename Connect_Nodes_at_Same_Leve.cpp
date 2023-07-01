#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/
void connectNodes(BinaryTreeNode< int > *root) {
    queue<BinaryTreeNode< int > *> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();n--;BinaryTreeNode< int > *prev=q.front();q.pop();
        if(prev->left) q.push(prev->left);
        if(prev->right) q.push(prev->right);
        while(n--){
             BinaryTreeNode< int > *temp=q.front();q.pop();
             prev->next=temp;
             prev=temp;
             if(temp->left) q.push(temp->left);
             if(temp->right)q.push(temp->right); 
        }
    } 
    // Write your code here.
}
