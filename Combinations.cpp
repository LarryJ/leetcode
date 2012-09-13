/*******************************
Given two integers n and k, 
return all possible combinations 
of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*******************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      vector<vector<int> > result;
      vector<int> combine;
      if (n < 1 || n < k)
	return result;
      combine_recursion(n, k, combine, result, 1);
      return result;
    }
    //O(C(n, k))
    void combine_recursion(int n, int k, vector<int> combine, 
			   vector<vector<int> > &result, int pos)
    {
      if (pos > n)
	return;
      if (combine.size() >= k)
	return;
      combine_recursion(n, k, combine, result, pos + 1);
      combine.push_back(pos);
      if (combine.size() == k)
      {
	result.push_back(combine);
	return;
      }
      else
	combine_recursion(n, k, combine, result, pos + 1);
    }
};

using namespace std;

int main()
{
  return 0;
}
