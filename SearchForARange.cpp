class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        int first = searchLeft(A, 0, n - 1, target);
        result.push_back(first);
        if(first == -1) {
        	result.push_back(-1);
        } else {
        	int last = searchRight(A, first, n - 1, target);
        	result.push_back(last);
        }
        return result;
    }

    int searchLeft(int A[], int start, int end, int target) {
    	if(start > end)
    		return -1;
    	while(start <= end) {
    		int mid = (start + end) / 2;
    		if(A[mid] > target) {
    			end = mid - 1;
    		} else if(A[mid] < target) {
    			start = mid + 1;
    		} else { // A[mid] == target
    			if(mid == 0)
    				return 0;
    			else {
    				if(A[mid - 1] != target)
    					return mid;
    				else
    					end = mid - 1;
    			}
    		}    		
    	}
    	return -1;
    }

    int searchRight(int A[], int start, int end, int target) {
    	if(start > end)
    		return -1;
        int last = end;
    	while(start <= end) {
    		int mid = (start + end) / 2;
    		if(A[mid] > target) {
    			end = mid - 1;
    		} else if(A[mid] < target) {
    			start = mid + 1;
    		} else {
    			if(mid == last || A[mid + 1] != target) {
    				return mid;
    			} else {
    				start = mid + 1;
    			}
    		}
    	}
    	return -1;
    }
};