/*******************************
Determine if a Sudoku is valid, 
according to: Sudoku Puzzles - 
The Rules.

The Sudoku board could be 
partially filled, where empty 
cells are filled with the 
character '.'.

A partially filled sudoku 
which is valid.
*******************************/
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      if (board.size() != 9 || board[0].size() != 9)
	return false;
      //check row
      for (int i = 0; i < 9; ++i)
      {
	vector<int> v(10, 0);
	for (int j = 0; j < 9; ++j)
	{
	  if (board[i][j] <= '0' || board[i][j] > '9')
	  {
	    if (board[i][j] != '.')
	      return false;	      
	  }
	  else
	  {
	    int k = board[i][j] - '0';
	    if (v[k] == 1)
	      return false;
	    else
	      v[k] = 1;
	  }
	}
      }
      //chech colunm
      for (int j = 0; j < 9; ++j)
      {
	vector<int> v(10, 0);
	for (int i = 0; i < 9; ++i)
	{
	  if (board[i][j] <= '0' || board[i][j] > '9')
	  {
	    if (board[i][j] != '.')
	      return false;	      
	  }
	  else
	  {
	    int k = board[i][j] - '0';
	    if (v[k] == 1)
	      return false;
	    else
	      v[k] = 1;
	  }
	}
      }
      //chech block
      for (int i = 0; i < 9; i += 3)
      {
	for (int j = 0; j < 9; j += 3)
	{
	  vector<int> v(10, 0);
	  for (int m = i; m < i + 3; ++m)
	  {
	    for (int n = j ; n < j + 3; ++n)
	    {
	      if (board[m][n] <= '0' || board[m][n] > '9')
	      {
		if (board[m][n] != '.')
		  return false;	      
	      }
	      else
	      {
		int k = board[m][n] - '0';
		if (v[k] == 1)
		  return false;
		else
		  v[k] = 1;
	      }
	    }
	  }
	}
      }
      return true;
    }
};
