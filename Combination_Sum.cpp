/*******************************
Given a set of candidate numbers 
(C) and a target number (T), 
find all unique combinations in 
C where the candidate numbers 
sums to T.

The same repeated number may be 
chosen from C unlimited number 
of times.

Note:

    All numbers (including target) 
    will be positive integers.
    Elements in a combination 
    (a1, a2, … , ak) must be in 
    non-descending order. 
    (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not 
    contain duplicate combinations.

For example, 
given candidate set 2,3,6,7 
and target 7,
A solution set is:
[7]
[2, 2, 3] 
*******************************/
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      //O(nlogn)
      sort(candidates.begin(), candidates.end());
      //cut tail
      for (int i = candidates.size() - 1; i >= 0; --i)
      {
	if (candidates[i] > target)
	  candidates.pop_back();
	else
	  break;
      }
      vector<vector<int> > result;
      vector<int> combination;
      combination_recursion(candidates, target, result, combination, 0);
      return result;
    }
  
    //O(n ^ n)
    void combination_recursion(vector<int> candidates, int target, vector<vector<int> > &result, 
					       vector<int> combination, int pos)
    {
      if (pos >= candidates.size())
	return;
      if (target < candidates[pos])
	return;
      for (int j = 0; j * candidates[pos] <= target; ++j)
      {
	vector<int> temp(combination);
	temp.insert(temp.end(), j, candidates[pos]);
	if (j != 0 && j * candidates[pos] == target)
	  if (find(result.begin(), result.end(), temp) == result.end())
	    result.push_back(temp);
	combination_recursion(candidates, target - j * candidates[pos], result, temp, pos + 1);
      }
    }
};
