class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result = digits;
        int carry = 0;
        bool flag = true;
        int len = digits.size();
        for(int i = len - 1; i >= 0; i--) {
            if(flag) {
                flag = false;
                result[i]++;
                if(result[i] == 10) {
                    result[i] = 0;
                    carry = 1;
                }
            } else {
                if(carry == 0)
                    break;
                result[i] += carry;
                if(result[i] == 10) {
                    result[i] = 0;
                    carry = 1;
                } else {
                    carry = 0;
                }
            }
        }
        if(carry == 1) {
            result.insert(result.begin(), 1);
        }
        return result;
    }
};