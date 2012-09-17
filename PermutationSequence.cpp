class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // compute 1 to (n - 1) factorial
        int factorial[n];
        for(int i = 1; i < n; i++) {
        	if(i == 1) {
        		factorial[i] = 1;
        	} else {
        		factorial[i] = factorial[i - 1] * i;
        	}
        }
        vector<int> elements;
        for(int i = 1; i <= n; i++) {
        	elements.push_back(i);
        }
        string s; // store the result
        k = k - 1;
        for(int i = n - 1; i >= 1; i--) {
        	int order = k / factorial[i];
        	// add elements[order] to s
        	s += (char)('0' + elements[order]);
        	elements.erase(elements.begin() + order);
        	k %= factorial[i];
        }
        s += (char)('0' + elements[0]);
        return s;
    }
};