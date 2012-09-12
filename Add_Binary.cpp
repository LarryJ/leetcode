/*******************************
Given two binary strings, 
return their sum 
(also a binary string).

For example,
a = "11"
b = "1"
Return "100". 
*******************************/
class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      string result;
      if (a.size() == 0 && b.size() == 0)
	return result;
      if (a.size() == 0)
	return b;
      if (b.size() == 0)
	return a;
      int i = a.size() - 1, j = b.size() - 1;
      int carry = 0;
      while (!(i < 0 && j < 0))
      {
	int m = 0;
	if (i >= 0)
	  m += a[i--] - '0';
	if (j >= 0)
	  m += b[j--] - '0';
	m += carry;
	carry = m / 2;
	char temp = (m % 2) + '0';
	result = temp + result;
      }
      if (carry != 0)
	result = '1' + result;
      return result;
    }
};
