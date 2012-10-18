/*******************************
The string "PAYPALISHIRING" is 
written in a zigzag pattern on a 
given number of rows like this: 
(you may want to display this 
pattern in a fixed font for better 
legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: 
"PAHNAPLSIIGYIR"

Write the code that will take a 
string and make this conversion 
given a number of rows:

string convert(string text, 
int nRows);

convert("PAYPALISHIRING", 3) 
should return "PAHNAPLSIIGYIR". 
*******************************/
class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function  
      string result;
      if (s.empty() || nRows <= 0)
	return result;
      vector<string> v_str;
      v_str.resize(nRows);
      int pos = 0;
      while (pos < s.size())
      {
	for (int i = 0; i < nRows; ++i)
	{
	  if (pos == s.size())
	    break;
	  v_str[i].push_back(s[pos++]);
	}
	for (int i = nRows - 2; i > 0; --i)
	{
	  if (pos == s.size())
	    break;
	  v_str[i].push_back(s[pos++]);
	}
      }
      for (size_t i = 0; i < v_str.size(); ++i)
	result += v_str[i];
      return result;
    }
};
