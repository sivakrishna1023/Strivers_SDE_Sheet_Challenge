#include<bits/stdc++.h>

TreeNode<int>* solve(vector<int>& postOrder, vector<int>& inOrder,int is,int ie,int ps,int pe,map<int,int>& mp){
       if((is>ie) || (ps>pe)) return NULL;
       TreeNode<int>* root=new TreeNode<int>(postOrder[pe]);
       int ele=mp[root->data];
       int nele=ele-is;
       root->left=solve(postOrder,inOrder,is,ele-1,ps,ps+nele-1,mp);
       root->right=solve(postOrder,inOrder,ele+1,ie, ps+nele,pe-1,mp);
       return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
     int ps=0,pe=postOrder.size()-1;
     int is=0,ie=inOrder.size()-1;
     map<int,int> mp;
     for(int i=is;i<=ie;i++){
          mp[inOrder[i]]=i;
     }
     return solve(postOrder,inOrder,is,ie,ps,pe,mp);
	// Write your code here.
}
/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/

