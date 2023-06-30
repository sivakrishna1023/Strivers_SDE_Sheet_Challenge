#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
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

***********************************************************/
bool solve(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2){
     if((root1 && !root2) || (!root1 && root2)) return false;
    if(!root1 && !root2) return true;
    if(root1->data!=root2->data) return false;
    //left check
    if(!(solve(root1->left,root2->left))) return false;
    if(!(solve(root1->right,root2->right))) return false;

    return true;

}
bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    return solve(root1,root2);
    // Write your code here. 	 
}
