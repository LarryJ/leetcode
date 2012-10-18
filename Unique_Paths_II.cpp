/*******************************
Follow up for "Unique Paths":

Now consider if some obstacles 
are added to the grids. How many 
unique paths would there be?

An obstacle and empty space is 
marked as 1 and 0 respectively 
in the grid.

For example,

There is one obstacle in the 
middle of a 3x3 grid as 
illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

The total number of unique paths 
is 2.

Note: m and n will be at most 100.
*******************************/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
	return 0;
      vector<vector<int> > matrix;
      for (size_t i = 0; i < obstacleGrid.size(); ++i)
      {
	vector<int> row(obstacleGrid[0].size(), 0);
	matrix.push_back(row);
      }
      for (size_t i = 0; i < matrix[0].size(); ++i)
      {
	if (obstacleGrid[0][i] == 1)
	  break;
	else
	  matrix[0][i] = 1;
      }
      for (size_t i = 0; i < matrix.size(); ++i)
      {	
	if (obstacleGrid[i][0] == 1)
	  break;
	else
	  matrix[i][0] = 1;
      }
      for (size_t i = 1; i < matrix.size(); ++i)
      {
	for (size_t j = 1; j < matrix[0].size(); ++j)
	{
	  if (obstacleGrid[i][j] == 1)
	    continue;
	  matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
	}
      }
      return matrix[matrix.size() - 1][matrix[0].size() - 1];
    }
};
