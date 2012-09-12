/*******************************
Given an array S of n integers, 
are there elements a, b, c in S 
such that a + b + c = 0? 
Find all unique triplets in the 
array which gives the sum of zero.

Note:
    Elements in a triplet (a,b,c) 
    must be in non-descending 
    order. (ie, a ≤ b ≤ c)
    The solution set must not 
    contain duplicate triplets.

    For example, given array 
    S = {-1 0 1 2 -1 -4},
    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

Time Complexity: O(n ^ 2)
*******************************/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      vector<vector<int> > result;
      sort(num.begin(), num.end());
      for (size_t i = 0; i < num.size(); ++i)
      {
	if (num[i] > 0)
	  break;
	int front = i + 1;
	int end = num.size() - 1;
	while (front < end)
	{
	  if (num[i] + num[front] + num[end] == 0)
	  {
	    vector<int> v;
	    v.push_back(num[i]);
	    v.push_back(num[front]);
	    v.push_back(num[end]);
	    result.push_back(v);
	    ++front;
	    --end;
	  }
	  else if (num[i] + num[front] + num[end] < 0)
	    ++front;
	  else
	    --end;
	}
      }
      //remove duplicates in result
      sort(result.begin(), result.end());
      vector<vector<int> >::iterator it;
      it = unique(result.begin(), result.end());
      result.resize(it - result.begin());
      return result;
    }
};

