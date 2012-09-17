class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = grid.size();
        int column = grid[0].size();
        int curSum[row][column];
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                if(i == 0) {
                    if(j == 0) {
                        curSum[i][j] = grid[i][j];
                    } else {
                        curSum[i][j] = curSum[i][j - 1] + grid[i][j];
                    }
                } else {
                    if(j == 0) {
                        curSum[i][j] = curSum[i - 1][j] + grid[i][j];
                    } else {
                        if(curSum[i - 1][j] <= curSum[i][j - 1]) {
                            curSum[i][j] = curSum[i - 1][j] + grid[i][j];
                        } else {
                            curSum[i][j] = curSum[i][j - 1] + grid[i][j];
                        }
                    }
                }
            }
        }
        return curSum[row - 1][column - 1];
    }
};