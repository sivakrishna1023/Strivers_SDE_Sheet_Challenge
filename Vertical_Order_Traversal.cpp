#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
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

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    map<int,map<int,vector<int>>> mp;
    queue<pair<TreeNode<int> *,pair<int,int>>> q;
    if(!root) return ans;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto p=q.front();q.pop();
        TreeNode<int> * temp=p.first;
        int x=p.second.first,y=p.second.second;
        mp[x][y].push_back(temp->data);

           if(temp->left) q.push({temp->left,{x-1,y+1}});
          if(temp->right) q.push({temp->right,{x+1,y+1}});
    }
    for(auto l:mp){
        for(auto m:l.second){
            ans.insert(ans.end(),m.second.begin(),m.second.end());
        }
    }
    return ans;
    //    Write your code here.
}
