/*******************************
Given a binary tree, check 
whether it is a mirror of itself 
(ie, symmetric around its center).

For example, this binary tree 
is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:

    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it 
both recursively and iteratively.

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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      if (root == NULL)
	return true;
      vector<int> value;
      in_order_traverse(root, value);
      size_t s = value.size();
      if (!(s % 2))    //even number of nodes, impossible
	return false;
      for (size_t i = 0; i < s / 2; ++i)
      {
	if (value[i] != value[s - i - 1])
	  return false;
      }
      return true;
    }

    void in_order_traverse(TreeNode *root, vector<int> &value)
    {
      if (root == NULL)
	return;
      in_order_traverse(root -> left, value);
      value.push_back(root -> val);
      in_order_traverse(root -> right, value);
    }
};
