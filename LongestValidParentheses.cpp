class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max = 0;
        int len = 0;
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                count++;
                len++;
            } else if(s[i] == ')') {
                count--;
                len++;
            }
            if(count == 0) { // a valid parentheses
                if(len > max)
                    max = len;
            }
            if(count < 0) {
                count = 0;
                len = 0;
            }
        }
        len = 0;
        count = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == ')') {
                count++;
                len++;
            } else if(s[i] == '(') {
                count--;
                len++;
            }
            if(count == 0 && len > max)
                max = len;
            if(count < 0) {
                count = 0;
                len = 0;
            }
        }
        return max;
    }
};