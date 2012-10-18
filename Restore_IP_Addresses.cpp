/*******************************
Given a string containing only 
digits, restore it by returning 
all possible valid IP address 
combinations.

For example:
Given "25525511135",

return 
["255.255.11.135", "255.255.111.35"]. 
(Order does not matter) 
*******************************/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      vector<string> result;
      if (s.size() < 4 || s.size() > 12)
	return result;
      restore_ip_addresses_recursion(s, "", result, 0, 0);
      return result;
    }

    void restore_ip_addresses_recursion(string s, string ip, vector<string> &result, int pos, int index)
    {
      if (pos == s.size() && index == 4)
      {
	result.push_back(ip);
	return;
      }
      if (pos >= s.size() || index > 4)
	return;
      if (index != 0)
	ip += '.';
      int n = 0;
      int i = pos;
      do
      {
	n = 10 * n + (s[i] - '0');
	if (n > 255)
	  break;
	ip += s[i++];
	restore_ip_addresses_recursion(s, ip, result, i, index + 1);
      }
      while (n != 0 && i < s.size());
    }
};
