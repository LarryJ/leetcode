/*******************************
Given n, generate all structurally 
unique BST's (binary search trees) 
that store values 1...n.

For example,
Given n = 3, your program should 
return all 5 unique BST's shown below.

1         3     3      2      1
 \       /     /      / \      \
  3     2     1      1   3      2
 /     /       \		 \
2     1         2                 3


OJ's Binary Tree Serialization:

The serialization of a binary tree 
follows a level order traversal, 
where '#' signifies a path terminator 
where no node exists below.

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
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      vector<TreeNode *> result;
      result = generateTrees_recursion(1, n);
      return result;
    }

    vector<TreeNode *> generateTrees_recursion(int beg, int end)
    {
      vector<TreeNode *> result;
      if (beg > end)
      {
	result.push_back(NULL);
	return result;
      }
      for (int i = beg; i <= end; ++i)
      {

	vector<TreeNode *> prev = generateTrees_recursion(beg, i - 1);
	vector<TreeNode *> next = generateTrees_recursion(i + 1, end);
	for (size_t k = 0; k < prev.size(); ++k)
	{
	  for (size_t j = 0; j < next.size(); ++j)
	  {
	    TreeNode *root = new TreeNode(i);
	    root -> left = prev[k];
	    root -> right = next[j];
	    result.push_back(root);
	  }
	}
      }
      return result;
    }
};
