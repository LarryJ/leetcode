class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, int> cache;
        return jumpHelp(A, n, cache);
    }
    
    int jumpHelp(int A[], int n, map<int, int>& cache) {
        if(n == 1)
            return 0;
        map<int, int>::iterator it = cache.find(n);
        if(it != cache.end()) {
            return it->second;
        } else {
            int minJump = 0x7fffffff;
            for(int i = 0; i < n - 1; i++) {
                if((A[i] + i) >= (n - 1)) {
                    int numJump = 1 + jumpHelp(A, i + 1, cache);
                    if(numJump < minJump) {
                        minJump = numJump;
                    }
                }
            }
            cache[n] = minJump;
            return minJump;
        }
    }
};