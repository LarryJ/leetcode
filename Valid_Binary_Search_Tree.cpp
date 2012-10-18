/*******************************
Given a binary tree, determine 
if it is a valid binary search 
tree (BST).

Assume a BST is defined as follows:

The left subtree of a node 
contains only nodes with keys less 
than the node's key.
The right subtree of a node 
contains only nodes with keys greater 
than the node's key.
Both the left and right subtrees must also be binary search trees.


OJ's Binary Tree Serialization:

The serialization of a binary tree 
follows a level order traversal, 
where '#' signifies a path 
terminator where no node exists below.

Here's an example:

   1
  / \
 2   3
    /
   4
    \
     5

The above binary tree is 
serialized as "{1,2,3,#,#,4,#,#,5}". 
*******************************/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      if (root == NULL)
	return true;
      return isValidBST_recursion(root, INT_MIN, INT_MAX);
    }

    bool isValidBST_recursion(TreeNode *root, int min, int max)
    {
      if (root == NULL)
	return true;
      if (root -> val <= min || root -> val >= max)
	return false;
      return isValidBST_recursion(root -> left, min, root -> val)
	&& isValidBST_recursion(root -> right, root -> val, max);
    }
};
