/*******************************
Given n, how many structurally 
unique BST's (binary search trees) 
that store values 1...n?

For example,
Given n = 3, there are a total 
of 5 unique BST's.

1         3     3      2      1
 \       /     /      / \      \
  3     2     1      1   3      2
 /     /       \		 \
2     1         2                 3

*******************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      if (n <= 2)
	return n;
      vector<int> v(n + 1, 0);
      v[0] = 1, v[1] = 1, v[2] = 2;
      int result = numTrees_recursion(n, v);
      return result;
    }

    int numTrees_recursion(int n, vector<int> &v)
    {
      if (v[n] != 0)
	return v[n];
      int result = 0;
      for (int i = 1; i <= n; ++i)
	result += numTrees_recursion(i - 1, v) * numTrees_recursion(n - i, v);
      v[n] = result;
      //cout << result << endl;
      return result;
    }
};

int main()
{
  Solution a;
  cout << a.numTrees(3) << endl;
  return 0;
}
