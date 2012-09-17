class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) {
        	return 0;
        }
        int last = A[0];
        int index = 1;
        int repeatCount = 0;
        for(int i = 1; i < n; i++) {
        	if(A[i] != last) {
        		repeatCount = 0;
        		A[index++] = A[i];
        		last = A[i];
        	} else {
        		if(repeatCount == 0) {
        			repeatCount++;
        			A[index] = A[i];
        			index++;
        		}
        	}
        }
        return index;
    }
};