/*******************************
You are climbing a stair case.
It takes n steps to reach to the
top.

Each time you can either climb 
1 or 2 steps. In how many distinct
ways can you climb to the top? 
*******************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      vector<int> v(n + 1, 0);
      return my_climb_stairs(n, v);
    }

    int my_climb_stairs(int n, vector<int> &v)
    {
      if (v[n] != 0)	 
	return v[n];
      if (n == 1)
      {
	v[1] = 1;
	return 1;
      }
      if (n == 2)
      {
	v[2] = 2;
	return 2;
      }
      v[n] = my_climb_stairs(n - 1, v) + my_climb_stairs(n - 2, v);
      return v[n];
  }
};

int main()
{
  Solution a;
  cout <<  a.climbStairs(35) << endl;
  return 0;
}
