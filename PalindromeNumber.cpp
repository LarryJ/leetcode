class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x < 0)
            return false;
        int n = x;
        int reverse = 0;
        while(n != 0) {
            int digit = n % 10;
            reverse = reverse * 10 + digit;
            n /= 10;
        }
        if(reverse == x)
            return true;
        else
            return false;
    }
};