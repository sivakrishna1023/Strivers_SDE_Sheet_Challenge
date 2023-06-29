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

int getMaxWidth(TreeNode<int> *root)
{
    int ans=0;
    if(!root) return ans;
    queue<pair<TreeNode<int>*,int>>q;
    q.push({root,0});
    while(!q.empty()){
       int n=q.size();ans=max(ans,n);
       while(n--){
           auto p=q.front();q.pop();
           TreeNode<int>* temp=p.first;int line=p.second;
           if(temp->left) q.push({temp->left,2*line+1});
           if(temp->right) q.push({temp->right,2*line+2});
       }
      // cout<<maxi<<" "<<mini<<endl;
    //   if(maxi==mini) ans=max(ans,1);
    //   else ans=max(ans,max(mini,maxi));

    }
    return ans;
    // Write your code here.
}
