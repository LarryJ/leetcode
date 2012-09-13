/*******************************
A message containing letters 
from A-Z is being encoded to 
numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing 
digits, determine the total number 
of ways to decode it.

For example,
Given encoded message "12", 
it could be decoded as 
"AB" (1 2) or "L" (12).

The number of ways decoding 
"12" is 2. 
*******************************/
class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      if (s.empty() || s[0] == '0')
	return 0;
      //deal with '0's, O(n)
      for (size_t i = 1; i < s.size(); ++i)
	if (s[i] == '0' && !(s[i - 1] == '1' || s[i - 1] == '2'))
	  return 0;
      vector<int> v;
      v.resize(s.size());
      return decode_string(s, 0, v);
    }

    int decode_string(string s, int pos, vector<int> &v)
    {
      if (pos >= s.size() - 1)
      {
	if (pos == s.size() - 1 && s[pos] == '0')
	  return 0;
	else
	  return 1;
      }
      if (v[pos] != 0)
	return v[pos];
      if (s[pos] == '1' || (s[pos] == '2' && s[pos + 1] <= '6'))
      {
	if (s[pos + 1] == '0')
	  v[pos] = decode_string(s, pos + 2, v);
	else
	  v[pos] = decode_string(s, pos + 1, v) + decode_string(s, pos + 2, v);
      }
      else
	v[pos] =  decode_string(s, pos + 1, v);
      return v[pos];
    }
};
