class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string longest = "";
        for(int i = 0; i < s.size(); i++) {
            string tmp = "";
            tmp += s[i];
            int j = 1;
            while((i - j) >= 0 && (i + j) < s.size()) {
                if(s[i - j] == s[i + j]) {
                    tmp = s[i - j] + tmp + s[i + j];
                    j++;
                } else {
                    break;
                }
            }
            if(tmp.size() > longest.size())
                longest = tmp;
        }
        int first = 0, second = 1;
        while(second < s.size()) {
            string tmp = "";
            if(s[first] == s[second]) {
                tmp = s[first] + tmp + s[second];
                int dist = 1;
                while((first - dist) >= 0 && (second + dist) < s.size()) {
                    if(s[first - dist] == s[second + dist]) {
                        tmp = s[first - dist] + tmp + s[second + dist];
                        dist++;
                    } else {
                        break;
                    }
                }
            }
            if(tmp.size() > longest.size())
                longest = tmp;
            first++;
            second++;
        }
        return longest;
    }
};