/*******************************
Given an array of strings, 
return all groups of strings 
that are anagrams.

Note: All inputs will be in 
lower-case (keep the duplicates)
*******************************/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution { 
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      vector<string> result;
      if (strs.empty())
	return result;
      typedef map<string, vector<string> > my_map;
      my_map m;
      m.clear();
      //O(nlogn), assuming each str has a constant length
      for (size_t i = 0; i < strs.size(); ++i)
      {	
	string temp(strs[i]);
        sort(temp.begin(), temp.end());
	m[temp].push_back(strs[i]);
      }
      //O(n)
      result.clear();
      for (my_map::iterator it = m.begin(); it != m.end(); ++it)
	if (it -> second.size() > 1)
	  for (size_t j = 0; j < (it -> second.size()); ++j)
	    result.push_back(it -> second[j]);
      return result;
    }
};

int main()
{
  return 0;
}
