/*******************************
Given a string S and a string T, 
count the number of distinct 
subsequences of T in S.

A subsequence of a string is a 
new string which is formed from 
the original string by deleting 
some (can be none) of the 
characters without disturbing 
the relative positions of the 
remaining characters. (ie, "ACE" 
is a subsequence of "ABCDE" 
while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3. 
*******************************/
class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      if (T.size() == 0 || S.size() < T.size())
	return 0;
      if (S.size() == T.size())
      {
	if (S == T)
	  return 1;
	else
	  return 0;
      }
      size_t s = S.size(), t = T.size();
      int **dp = new int *[s];
      for (int i = 0; i < s; ++i)
      {
	dp[i] = new int[t];
      }
      dp[0][0] = (S[0] == T[0])? 1: 0;
      //init first row and first column
      for (int j = 1; j < t; ++j)
	dp[0][j] = 0;
      for (int i = 1; i < s; ++i)
      {
	if (S[i] == T[0])
	  dp[i][0] = dp[i - 1][0] + 1;
	else
	  dp[i][0] = dp[i - 1][0];
      }
      for (int i = 1; i < s; ++i)
      {
	for (int j = 1; j < t; ++j)
	{
	  if (j > i)
	  {
	    dp[i][j] = 0;
	    continue;
	  }
	  int count = 0;
	  if (j > 0 && i > 0 && S[i] == T[j])
	    count += dp[i - 1][j - 1];
	  if (i > 0)
	    count += dp[i - 1][j];
	  dp[i][j] = count;	  
	}
      }
      int result = dp[s - 1][t - 1];
      for (int i = 0; i < s; ++i)
      {
	delete []dp[i];
	dp[i] = NULL;
      }
      delete []dp;
      return result;
    }
};
