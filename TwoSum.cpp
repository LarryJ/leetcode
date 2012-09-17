class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        vector<pair<int, int> > table;
        for(int i = 0; i < numbers.size(); i++) {
            table.push_back(pair<int, int>(numbers[i], i + 1));
        }
        sort(table.begin(), table.end());
        int start = 0;
        int end = table.size() - 1;
        while(start < end) {
            int sum = table[start].first + table[end].first;
            if(sum == target) {
                int index1 = min(table[start].second, table[end].second);
                int index2 = max(table[start].second, table[end].second);
                result.push_back(index1);
                result.push_back(index2);
                return result;
            } else if(sum < target) {
                start++;
            }  else {
                end--;
            }
        }
    }
};

/* hash_map need to consider more cases, such as: [1, 10, 4, 4, 2] 8
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // map integer to index
        vector<int> result;
        hash_map<int, int> table;
        for(int i = 1; i <= numbers.size(); i++) {
            table[numbers[i - 1]] = i;
        }
        hash_map<int, int>::iterator it;
        for(it = table.begin(); it != table.end(); it++) {
            int toFind = target - it->first;
            hash_map<int, int>::iterator iter = table.find(toFind);
            if(iter != table.end() && iter->first != it->first) {
                int index1 = it->second;
                int index2 = iter->second;
                result.push_back(min(index1, index2));
                result.push_back(max(index1, index2));
                return result;
            }
        }
        return result;
    }
};
*/