/*******************************
Given two words word1 and word2, 
find the minimum number of steps 
required to convert word1 to word2. 
(each operation is counted as 
1 step.)

You have the following 3 operations 
permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

*******************************/
class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      size_t l1 = word1.length();
      size_t l2 = word2.length();
      if (l1 == 0 && l2 == 0)
	return 0;
      int **dp = new int *[l1 + 1];
      for (size_t i = 0; i <= l1; ++i)
	dp[i] = new int[l2 + 1];
      //init two dimensions
      for (size_t i = 0; i <= l1; ++i)
	dp[i][0] = i;
      for (size_t j = 0; j <= l2; ++j)
	dp[0][j] = j;
      //compare two string
      for (size_t i = 1; i <= l1; ++i)
      {
	for (size_t j = 1; j <= l2; ++j)
	{
	  int append_one_char = min(dp[i - 1][j], dp[i][j - 1]) + 1;   //(insert)append the next character respectively, choose the shorter solution
	  int append_one_char_each = dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]);//(replace)append the next character at the same time
	  dp[i][j] = min(append_one_char, append_one_char_each);
	}
      }
      int result = dp[l1][l2];
      //end of compare
      for (size_t i = 0; i <= l1; ++i)
      {
	delete []dp[i];
	dp[i] = NULL;
      }
      delete []dp;
      dp = NULL;

      return result;
    }
};
