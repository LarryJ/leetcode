/*******************************
Given an array S of n integers, 
find three integers in S such 
that the sum is closest to a 
given umber, target. Return the 
sum of the three integers. You 
may assume that each input 
would have exactly one solution.

For example, given array 
S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the 
target is 2. (-1 + 2 + 1 = 2).
*******************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      if (num.size() < 3)
	return EXIT_FAILURE;
      int candidate = num[0] + num[1] + num[2];
      sort(num.begin(), num.end());
      for (vector<int>::size_type i = 0; i < num.size(); ++i)
      {
	int front = i + 1;
	int end = num.size() - 1;
	while (front < end)
	{
	  int n = num[i] + num[front] + num[end];
	  if (n == target)
	    return target;
	  if (abs(n - target) < abs(candidate - target))
	    candidate = n; 
	  if (n > target)
	    --end;
	  else
	    ++front;
	}
      }
      return candidate;
    }
};

int main()
{
  int arr[] = {-3,-2,-5,3,-4};
  vector<int> v(arr, arr + 5);
  Solution a;
  cout << a.threeSumClosest(v, -1) << endl;
  return 0;
}
