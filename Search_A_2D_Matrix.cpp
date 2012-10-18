/*******************************
Write an efficient algorithm that 
searches for a value in an m x n
 matrix. This matrix has the 
following properties:

Integers in each row are sorted 
from left to right.
The first integer of each row is 
greater than the last integer of 
the previous row.

For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target = 3, return true.
*******************************/
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      int N = matrix.size();
      if (N == 0)
	return false;
      int M = matrix[0].size();
      if (M == 0)
	return false;
      if (target < matrix[0][0] || target > matrix[N - 1][M - 1])
	return false;
      //find row
      int beg = 0, end = N - 1;
      int mid = 0;
      //binary search
      while (beg <= end)
      {
	mid = (beg + end) / 2;
	if (matrix[mid][0] == target)
	  return true;
	else if (matrix[mid][0] < target)
	  beg = mid + 1;
	else
	  end = mid - 1;
      }
      int row = beg;
      if (row != 0 && matrix[row - 1][M - 1] >= target)
	--row;
      //find column
      beg = 0, end = M - 1;
      while (beg <= end)
      {
	mid = (beg + end) / 2;
	if (matrix[row][mid] == target)
	  return true;
	else if (matrix[row][mid] < target)
	  beg = mid + 1;
	else
	  end = mid - 1;
      }
      return false;
    }
};
