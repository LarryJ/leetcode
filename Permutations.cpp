class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        if(num.size() == 1) {
        	result.push_back(num);
        	return result;
        }
        vector<int> vec(num.begin(), num.end() - 1);
        vector<vector<int> > prev = permute(vec);
        // insert the last element to every position of prev
        for(int i = 0; i < prev.size(); i++) {
        	for(int pos = 0; pos <= prev[i].size(); pos++) {
        		vector<int> tmp = prev[i];
        		tmp.insert(tmp.begin() + pos, num[num.size() - 1]);
        		result.push_back(tmp);
        	}
        }
        return result;
    }
};