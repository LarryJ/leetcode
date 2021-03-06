class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int i = 0; i < n; i++) {
            while(A[i] != i + 1) {
                if(A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1])
                    break;
                int tmp = A[i];
                A[i] = A[tmp - 1];
                A[tmp - 1] = tmp;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(A[i] != i + 1)
                return i + 1;
        }
        return n + 1;
};
    }