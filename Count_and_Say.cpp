/*******************************
The count-and-say sequence is 
the sequence of integers 
beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, 
then one 1" or 1211.

Given an integer n, 
generate the nth sequence.

Note: The sequence of integers 
will be represented as a string. 
*******************************/
class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      if (n == 0)
	return "";
      string result = "1";
      for (int i = 2; i <= n; ++i)
      {
	result = count_to_string(result);
      }
      return result;
    }

    string count_to_string(string str)
    {
      string result;
      int count = 1;
      char temp = str[0];
      for (size_t i = 1; i < str.size(); ++i)
      {
	if (str[i] == temp)
	{
	  ++count;
	  continue;
	}
	else
	{
	  result += '0' + count;
	  result += temp;
	  count = 1;
	  temp = str[i];
	}
      }
      result += '0' + count;
      result += temp;
      return result;
    }
};
