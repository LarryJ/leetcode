class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size() == 1 || num.size() == 0)
            return;
        // find a increasing sequence from the end
        int maxIndex = num.size() - 1;
        int changeIndex;
        for(int i = num.size() - 2; i >= 0; i--) {
            if(num[i] > num[maxIndex]) {
                maxIndex = i;
            }
            if(num[i] < num[maxIndex]) { // have found the increase
                changeIndex = i;
                break;
            }
        }
        if(maxIndex == 0) {
            sort(num.begin(), num.end());
            return;
        }
        // find the minimum number larger than num[changeIndex] and swap
        int toChange = maxIndex;
        for(int i = changeIndex + 1; i < num.size(); i++) {
            if(num[i] > num[changeIndex] && num[i] < num[toChange]) {
                toChange = i;
            }
        }
        int tmp = num[changeIndex];
        num[changeIndex] = num[toChange];
        num[toChange] = tmp;
        sort(num.begin() + changeIndex + 1, num.end());
        return;
    }
};