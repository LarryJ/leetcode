class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int longest = 0;
        int start = 0;
        int end = 0;
        bool buffer[256] = {0};
        while(start < s.size()) {
            // check the string from start to end
            if(buffer[s[end]] == true) {
                buffer[s[start]] = false;
                start++;
            } else {
                if(end < s.size()) {
                    buffer[s[end]] = true;
                    int dist = end - start + 1;
                    if(dist > longest)
                        longest = dist;
                    end++;
                } else {
                    break;
                }
            }
        }
        return longest;
    }
};