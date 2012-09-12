/*******************************
Given a binary tree, 
return the inorder traversal 
of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,3,2]. 
*******************************/
// struct TreeNode
// {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode (int v) : val(v), left(NULL), right(NULL) {};
// };
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      vector<int> result;
      if (root == NULL)
	return result;
      result = inorderTraversal(root -> left);
      result.push_back(root -> val);
      vector<int> temp = inorderTraversal(root -> right);
      result.insert(result.end(), temp.begin(), temp.end());
      return result;
    }
};
