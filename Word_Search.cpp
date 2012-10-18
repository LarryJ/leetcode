/*******************************
Given a 2D board and a word, 
find if the word exists in the 
grid.

The word can be constructed from 
letters of sequentially adjacent 
cell, where "adjacent" cells are 
those horizontally or vertically 
neighboring. The same letter cell 
may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*******************************/
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      if (board.size() == 0 || board[0].size() == 0)
	return false;
      if (word.size() == 0)
	return true;
      vector<vector<bool> > visit;
      for (size_t i = 0; i < board.size(); ++i)
      {
	vector<bool> row(board[0].size(), false);
	visit.push_back(row);
      }
      for (size_t i = 0; i < board.size(); ++i)
	for (size_t j = 0; j < board[0].size(); ++j)
	  if (exist_recursion(board, word, visit, 0, i, j))
	    return true;
      return false;
    }
    /*******************************************************************
    pass references for "board", "word" and "visit", save space ,and 
    improve running effeciency as well (200 milli secs -> 100 milli secs)
    ********************************************************************/
    bool exist_recursion(const vector<vector<char> > &board, const string &word, 
			 vector<vector<bool> > &visit, int pos, int row, int column)
    {
      if (word[pos] != board[row][column])
	return false;
      ++pos;
      if (pos == word.size())
	return true;
      visit[row][column] = true;
      if (row > 0 && !visit[row - 1][column] && exist_recursion(board, word, visit, pos, row - 1, column))
	return true;
      if (row < board.size() - 1 && !visit[row + 1][column] && exist_recursion(board, word, visit, pos, row + 1, column))
	return true;
      if (column > 0 && !visit[row][column - 1] && exist_recursion(board, word, visit, pos, row, column - 1))
	return true;
      if (column < board[0].size() - 1 && !visit[row][column + 1] && exist_recursion(board, word, visit, pos, row, column + 1))
	return true;
      visit[row][column] = false;   //since "visit" is passing by reference
      return false;
    }
};
