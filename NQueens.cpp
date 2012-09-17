// a false example
/*
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > result;
        nQueen(n, n, result);
        return result;
    }
    
    vector<string> nQueen(int n, int row, vector<vector<string> >& result) {
        if(row < 0) {
            vector<string>  vs;
            return vs;
        }
        vector<string> board = nQueen(n, row - 1, result);
        for(int column = 0; column < n; column++) {
            string before('.', column);
            string after('.', n - column - 1);
            string s = before + 'Q' + after;
            if(valid(board, column, n)) {
                board.push_back(s);
                if(board.size() == n)
                    result.push_back(board);
                return board;
            }
        }
    }
    
    bool valid(vector<string>& board, int column, int n) {
        int row = board.size();
        if(row == 0)
            return true;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'Q') {
                    if(j == column)
                        return false;
                    int distance = row + 1 - i;
                    if(column - j == distance || j - column == distance)
                        return false;
                }
            }
        }
        return true;
    }
};
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > result = nQueen(n, n);
        return result;
    }
    
    vector<vector<string> > nQueen(int n, int row) {
        vector<vector<string> > result;
        if(row < 0) {
            vector<string> vs;
            result.push_back(vs);
            return result;
        }
        vector<vector<string> > prev = nQueen(n, row - 1);
        for(int i = 0; i < prev.size(); i++) {
            for(int column = 0; column < n; column++) {
                string before('.', column);
                string after('.', n - column - 1);
                string s = before + 'Q' + after;
                if(valid(prev[i], column, n)) {
                    prev[i].push_back(s);
                    result.push_back(prev[i]);
                }
            }
        }
        return result;
    }
    
    bool valid(vector<string>& board, int column, int n) {
        int row = board.size();
        if(row == 0)
            return true;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'Q') {
                    if(j == column)
                        return false;
                    int distance = row + 1 - i;
                    if(column - j == distance || j - column == distance)
                        return false;
                }
            }
        }
        return true;
    }
};

int main() {
  Solution s;
  vector<vector<string> > vv = s.solveNQueens(1);
  for(int i = 0; i < vv.size(); i++) {
    for(int j = 0; j < vv[i].size(); j++)
      cout << vv[i][j] << endl;
  }
  cout << endl;
  return 0;
}
