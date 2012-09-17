class Solution {
public:
    int minDistance(string word1, string word2) {
        map<pair<string, string>, int> cache;
        return minDistanceHelp(word1, word2, cache);
    }

    int minDistanceHelp(string word1, string word2, map<pair<string, string>, int>& cache) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(word1.size() == 0)
            return word2.size();
        if(word2.size() == 0)
            return word1.size();
        if(word1[0] == word2[0]) {
            return minDistanceHelp(word1.substr(1), word2.substr(1), cache);
        }
        map<pair<string, string>, int>::iterator it = cache.find(pair<string, string>(word1, word2));
        if(it != cache.end()) {
            return it->second;
        }
        int dis1 = minDistanceHelp(word1, word2.substr(1), cache);
        int dis2 = minDistanceHelp(word1.substr(1), word2, cache);
        int dis3 = minDistanceHelp(word1.substr(1), word2.substr(1), cache);
        int result = min(min(dis1, dis2), dis3) + 1;
        cache[pair<string, string>(word1, word2)] = result;
        return result;
    }
};