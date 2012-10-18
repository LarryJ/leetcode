/*******************************
Given a sorted array and a 
target value, return the index 
if the target is found. If not, 
return the index where it would 
be if it were inserted in order.

You may assume no duplicates 
in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0 
*******************************/
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      int beg = 0;
      int end = n - 1;
      while (beg <= end)
      {
	int mid = (beg + end) / 2;
	if (A[mid] == target)   //find the element
	  return mid;
	else if (A[mid] < target)
	  beg = mid + 1;
	else
	  end = mid - 1;
      }
      return beg;
    }
};
