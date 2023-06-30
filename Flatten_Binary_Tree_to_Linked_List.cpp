#include <bits/stdc++.h> 


class Solution {
 TreeNode<int> * prev = NULL;
  public:
    void flatten(TreeNode<int> *root) {
      if (root == NULL) return;

      flatten(root -> right);
      flatten(root -> left);

      root -> right = prev;
      root -> left = NULL;
      prev = root;
    }

};
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{   
      Solution solution;
    solution.flatten(root);
     return root;
    // Write your code here.
}
/************************************************************

    Following is the TreeNode class structure.

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
