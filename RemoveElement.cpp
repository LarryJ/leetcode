class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int index = 0;
        for(int i = 0; i < n; i++) {
        	if(A[i] != elem) {
        		if(i != index) {
        			int tmp = A[i];
        			A[i] = A[index];
        			A[index] = tmp;
        		}
        	index++;
        	}
        }
        return index;
    }
};