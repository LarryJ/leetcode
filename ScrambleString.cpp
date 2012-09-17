class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s1 == s2)
        	return true;
        if(s1.length() != s2.length())
        	return false;
        int length = s1.length();
        if(length == 1) {
        	return false;
        }
        if(length == 2) {
        	return (s1[0] == s2[1] && s1[1] == s2[0]);
        }
        string left1, right1, left2, right2;
        for(int i = 1; i < length; i++) {
        	left1 = s1.substr(0, i);
        	right1 = s1.substr(i);
        	left2 = s2.substr(0, i);
        	right2 = s2.substr(i);
        	if(isScramble(left1, left2) && isScramble(right1, right2)) {
        		return true;
        	}
        }
        for(int i = 1; i < length; i++) {
        	left1 = s1.substr(0, i);
        	right1 = s1.substr(i);
        	left2 = s2.substr(0, length - i);
        	right2 = s2.substr(length - i);
        	if(isScramble(left1, right2) && isScramble(right1, left2)) {
        		return true;
        	}
        }
        return false;
    }
};
