class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string result = "";
        if(strs.size() == 0)
            return result;
        for(int i = 0; i < strs[0].size(); i++) {
            // check if strs[0][i] is shared by all the strings in strs
            char c = strs[0][i];
            bool share = true;
            for(int j = 1; j < strs.size(); j++) {
                if(strs[j].size() >= (i + 1) && strs[j][i] == c) {
                    continue;
                } else {
                    share = false;
                    break;
                }
            }
            if(share) {
                result += c;
            } else {
                break;
            }
        }
        return result;
    }
};