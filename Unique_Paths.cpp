/*******************************
A robot is located at the top-left 
corner of a m x n grid 
(marked 'Start' in the diagram below).

The robot can only move either 
down or right at any point in time. 
The robot is trying to reach the 
bottom-right corner of the grid 
(marked 'Finish' in the diagram below).

How many possible unique paths 
are there?


Above is a 3 x 7 grid. 
How many possible unique paths 
are there?

Note: m and n will be at most 100.
*******************************/
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      vector<vector<int> > matrix;
      for (size_t i = 0; i < m; ++i)
      {
	vector<int> row(n, 0);
	matrix.push_back(row);
      }
      return uniquePaths_recursion(m - 1, n - 1, matrix);
    }

    int uniquePaths_recursion(int m, int n, vector<vector<int> > &matrix)
    {
      if (m == 0 || n == 0)
	return 1;
      if (matrix[m][n] != 0)
	return matrix[m][n];
      int result = uniquePaths_recursion(m - 1, n, matrix) 
	+ uniquePaths_recursion(m, n - 1, matrix);
      matrix[m][n] = result;
      return result;
    }
};
