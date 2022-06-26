// https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
    vector<bool> cols; // Columns used.
    vector<bool> ldiag; // Left diagonal lines used, for the same line, row - col is constant. 
    vector<bool> rdiag; // Right diagonal lines used, for the same line, row + col is constant.
    vector<string> board;
    bool setQueen(int row, int col){
        if(cols[col] || ldiag[board.size() - 1 + row - col] || rdiag[row + col]) return false;
        
        cols[col] = true;
        ldiag[board.size() - 1 + row - col] = true;
        rdiag[row + col] = true;
        board[row][col] = 'Q';
        return true;
    }
    
    void unsetQueen(int row, int col){
        cols[col] = false;
        ldiag[board.size() - 1 + row - col] = false;
        rdiag[row + col] = false;
        board[row][col] = '.';
    }
    void solveNQueens(int row, vector<vector<string>> &answer) {
        if(row == board.size()){
            answer.push_back(board);
            return;
        }
        
        for(int col = 0; col < board[row].size(); col ++){
            if(setQueen(row, col)){
                solveNQueens(row + 1, answer); // Try next row.
                unsetQueen(row, col);
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        cols.resize(n, false);
        ldiag.resize(2 * n, false);
        rdiag.resize(2 * n, false);
        board.resize(n, string(n, '.'));
        
        vector<vector<string>> answer;
        solveNQueens(0, answer); // Start from the first row.
        
        return answer;
    }
};

// driver program to test above function
int main()
{
    auto boards = Solution().solveNQueens(4);
    for(const auto & b : boards){
        for(const auto &s : b){
            cout << s << "\n";
        }
        cout << "\n";
    }
    return 0;
}