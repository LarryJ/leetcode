class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i, j = 0;
        for(i = 0; i < n; i++) {
            if(i <= j && A[i] + i > j) {
                j = A[i] + i;
            }
        }
        return j >= (n - 1);
    }
};