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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      	vector<int> nums;
  		in_order(root, nums);
  		sort(nums.begin(), nums.end());
        int index = 0;
  		in_order_insert(root, nums, index);
    }

    void in_order(TreeNode* root, vector<int>& nums) {
    	if(root == NULL)
    		return;
    	in_order(root->left, nums);
    	nums.push_back(root->val);
    	in_order(root->right, nums);
    }

    void in_order_insert(TreeNode* root, vector<int>& nums, int& index) {
    	if(root == NULL)
    		return;
    	in_order_insert(root->left, nums, index);
    	if(root->val != nums[index]) {
    		root->val = nums[index];
    	}
    	index++;
    	in_order_insert(root->right, nums, index);
    }
};
