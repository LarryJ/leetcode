class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
  		vector<vector<int> > result;
  		if(S.size() == 0) {
  			vector<int> vec;
  			result.push_back(vec);
  			return result;
  		}
  		sort(S.begin(), S.end());
  		vector<int> vec(S.begin(), S.end() - 1);
  		vector<vector<int> > prev = subsets(vec);
  		for(int i = 0; i < prev.size(); i++) {
  			result.push_back(prev[i]);
  			vector<int> tmp = prev[i];
  			tmp.push_back(S[S.size() - 1]);
  			result.push_back(tmp);
  		}
  		return result;
    }
};