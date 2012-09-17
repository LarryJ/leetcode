class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num1 == "0" || num2 == "0")
    		return "0";
		int numZero = 0;
		string result = "0";
		for(int i = num2.size() - 1; i >= 0; i--) {
			// num1 * num2[i]
			string mult = multiplyHelp(num1, num2[i]);
			string tail(numZero, '0');
			numZero++;
			mult += tail;
			result = plus(result, mult); 
		}
		return result;
    }
	
	string multiplyHelp(string s, char c) {
		if(s == "0" || c == '0')
			return "0";
		string result;
		int carry = 0;
		int b = c - '0';
		for(int i = s.size() - 1; i >= 0; i--) {
			int value = (s[i] - '0') * b + carry;
			int remain = value % 10; 
			carry = value / 10;
			char ch = (char)('0' + remain);
			result = ch + result;
		}
		if(carry != 0) {
			result = (char)('0' + carry) + result;
		}
		return result;
	}
	
	string plus(string s1, string s2) {
		if(s1 == "0")
			return s2;
		if(s2 == "0")
			return s1;
		string result;
		int carry = 0;
		int end1 = s1.size() - 1;
		int end2 = s2.size() - 1;
		while(end1 >= 0 && end2 >= 0) {
			int value = carry + (s1[end1] - '0') + (s2[end2] - '0');
			int remain = value % 10;
			carry = value >= 10 ? 1 :  0;
			char c = (char)('0' + remain);
			result = c + result;
			end1--;
			end2--;
		}
		while(end1 >= 0) {
			int value = carry + (s1[end1] - '0');
			int remain = value % 10;
			carry = value >= 10 ? 1 : 0;
			char c = (char)('0' + remain);
			result = c + result;
			end1--;
		}
		while(end2 >= 0) {
			int value = carry + (s2[end2] - '0');
			int remain = value % 10;
			carry = value >= 10 ? 1 : 0;
			char c = (char)('0' + remain);
			result = c + result;
			end2--;
		}
        if(carry != 0)
            result = "1" + result;
		return result;
	}
};