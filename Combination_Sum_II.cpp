/*******************************
Given a collection of candidate 
numbers (C) and a target number 
(T), find all unique combinations 
in C where the candidate numbers 
sums to T.

Each number in C may only be 
used once in the combination.

Note:

    All numbers (including target) 
    will be positive integers.
    Elements in a combination 
    (a1, a2, … , ak) must be in 
    non-descending order. 
    (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not 
    contain duplicate combinations.

For example, given candidate set 
10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6] 
*******************************/
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      vector<vector<int> > result;
      if (num.size() == 0 || target <= 0)
	return result;
      //O(nlogn)
      sort(num.begin(), num.end());
      //cut tail
      for (int i = num.size() - 1; i >= 0; --i)
      {
	if (num[i] > target)
	  num.pop_back();
	else
	  break;
      }
      vector<int> combination;
      combination_recursion(num, target, result, combination, 0);
      return result;
    }

    void combination_recursion(vector<int> num, int target, vector<vector<int> > &result,
			       vector<int> combination, int pos)
    {
      if (pos >= num.size())
	return;
      if (target < num[pos])
	return;
      combination_recursion(num, target, result, combination, pos + 1);
      combination.push_back(num[pos]);
      if (target == num[pos])
	if (find(result.begin(), result.end(), combination) == result.end())
	  result.push_back(combination);
      combination_recursion(num, target - num[pos], result, combination, pos + 1);
    }
};
