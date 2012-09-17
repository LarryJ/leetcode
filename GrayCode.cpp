class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) {
            vector<int> vec;
            vec.push_back(0);
            return vec;
        }
        vector<int> prev = grayCode(n - 1);
        vector<int> result;
        for(int i = 0; i < prev.size(); i++) {
            result.push_back(prev[i]);
        }
        for(int i = prev.size() - 1; i >= 0; i--) {
            result.push_back(prev[i] + (int)pow(2.0, n - 1));
        }
        return result;
    }
};