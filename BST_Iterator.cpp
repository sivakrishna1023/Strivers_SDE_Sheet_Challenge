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

class BSTiterator
{
    public:
    stack<TreeNode<int>*> st;
    BSTiterator(TreeNode<int> *root)
    {
        while(root){
            st.push(root);
            root=root->left;
        }
        // write your code here
    }

    int next()
    {
        TreeNode<int> * top=st.top();
        st.pop();
        TreeNode<int> * temp=top->right;
        while(temp){
            st.push(temp);
            temp=temp->left;
        }
        return top->data;
        // write your code here
    }

    bool hasNext()
    {
        return (!st.empty());
        // write your code here
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
