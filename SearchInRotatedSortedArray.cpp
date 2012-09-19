class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = n - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(A[mid] == target)
                return mid;
            else if(A[mid] > A[right]) { // the left half is sorted
                if(target >= A[left] && target <= A[mid])
                    right = mid -1;
                else
                    left = mid + 1;
            } else { // right half is sorted
                if(target >= A[mid] && target <= A[right])
                    left = mid + 1;
                else 
                    right = mid - 1;
            }
        }
        return -1;
    }
};