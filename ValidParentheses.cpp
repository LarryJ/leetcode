// a typical WRONG answer
/*
class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // count1 for "()", count2 for "{}", count3 for "[]"
        int count1 = 0, count2 = 0, count3 = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                count1++;
            } else if(s[i] == ')') {
                count1--;
                if(count1 < 0)
                    return false;
            } else if(s[i] == '{') {
                count2++;
            } else if(s[i] == '}') {
                count2--;
                if(count2 < 0)
                    return false;
            } else if(s[i] == '[') {
                count3++;
            } else if(s[i] == ']') {
                count3--;
                if(count3 < 0)
                    return false;
            }
        }
        if(count1 != 0 || count2 != 0 || count3 != 0)
            return false;
        else
            return true;
    }
};
*/

class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> sta;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                sta.push(s[i]);
            } else {
                if(sta.empty())
                    return false;
                char top = sta.top();
                if((s[i] == ')' && top != '(') ||
                    (s[i] == '}' && top != '{') || 
                    (s[i] == ']' && top != '['))
                    return false;
                else
                    sta.pop();
            }
        }
        if(sta.empty())
            return true;
        else
            return false;
    }
};