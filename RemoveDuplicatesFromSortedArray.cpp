class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0)
            return 0;
        int last = A[0];
        int index = 1;
        for(int i = 1; i < n; i++) {
            if(A[i] != last) {
                A[index++] = A[i];
                last = A[i];
            }
        }
        return index;
    }
};