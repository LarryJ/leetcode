class Solution {
public:
    double pow(double x, long long n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0)
        	return 1;
        if(x == 1)
        	return 1;
        if(x == -1) {
        	if(n % 2 == 0)
        		return 1;
        	else
        		return -1;
        }
        if(n > 0) {
        	if(n % 2 == 0) {
        		double tmp = pow(x, n / 2);
        		return tmp * tmp;
        	} else {
        		double tmp = pow(x, n / 2);
        		return x * tmp * tmp;
        	}
        } else {
        	return 1.0 / pow(x, -n);
        }
    }
};