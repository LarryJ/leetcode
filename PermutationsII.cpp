class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        set<vector<int> > permutations = permute(num);
        set<vector<int> >::iterator it;
        for(it = permutations.begin(); it != permutations.end(); it++) {
        	result.push_back(*it);
        }
        return result;
    }

    set<vector<int> > permute(vector<int>& num) {
    	set<vector<int> > result;
    	if(num.size() == 1) {
    		result.insert(num);
    		return result;
    	}
    	vector<int> vec(num.begin(), num.end() - 1);
    	set<vector<int> > prev = permute(vec);
    	set<vector<int> >::iterator it;
    	for(it = prev.begin(); it != prev.end(); it++) {
    		for(int pos = 0; pos <= it->size(); pos++) {
    			vector<int> tmp = *it;
    			tmp.insert(tmp.begin() + pos, num[num.size() - 1]);
    			result.insert(tmp);
    		}
    	}
    	return result;
    }
};