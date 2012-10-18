/*******************************
Given n non-negative integers 
representing an elevation map 
where the width of each bar is 1, 
compute how much water it is able 
to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], 
return 6.

(see picture on leetcode.com)
The above elevation map is 
represented by array 
[0,1,0,2,1,0,1,3,2,1,2,1]. In 
this case, 6 units of rain water 
(blue section) are being trapped. 
Thanks Marcos for contributing 
this image!
*******************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      if (n <= 2)
	return 0;
      int *l_max = new int[n];
      int *r_max = new int[n];
      l_max[0] = A[0], r_max[n - 1] = A[n - 1];
      for (int i = 1; i <= n - 3; ++i)
	l_max[i] = max(l_max[i - 1], A[i]);
      for (int i = n - 2; i >= 2; --i)
	r_max[i] = max(r_max[i + 1], A[i]);
      int result = 0;
      for (int i = 1; i <= n - 2; ++i)
      {
	int low = min(l_max[i - 1], r_max[i + 1]);
	if (A[i] < low)
	  result += low - A[i];
      }
      delete l_max;
      delete r_max;
      l_max = NULL, r_max = NULL;
      return result;
    }
};

int main()
{
  return 0;
}
