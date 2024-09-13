class Solution {
    
void Add2D(vector<vector<string>>& board, vector<vector<string>>& ans, int n) {
    vector<string> temp;
    
    for (int i = 0; i < n; i++) {
        string rowStr;
        for (int j = 0; j < n; j++) {
            rowStr += board[i][j];
        }
        temp.push_back(rowStr);
    }
    
    ans.push_back(temp);
}    

void solve(int col, int n, vector<vector<string>>& board, vector<vector<string>>& ans, 
           unordered_map<int, bool>& rows, 
           unordered_map<int, bool>& upperDiagonals, 
           unordered_map<int, bool>& lowerDiagonals) {
    
    if (col == n) {
        Add2D(board, ans, n);
        return;
    }
    
    for (int row = 0; row < n; row++) {
        if (!rows[row] && !upperDiagonals[n-1 + col - row] && !lowerDiagonals[col + row]) {
            
            // Place the queen
            board[row][col] = "Q";
            rows[row] = true;
            upperDiagonals[n-1 + col - row] = true;
            lowerDiagonals[col + row] = true;
            
            solve(col + 1, n, board, ans, rows, upperDiagonals, lowerDiagonals);
            
            // Backtrack
            board[row][col] = ".";
            rows[row] = false;
            upperDiagonals[n-1 + col - row] = false;
            lowerDiagonals[col + row] = false;
        }
    }
}

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n, vector<string>(n, "."));
        vector<vector<string>> ans;
        
        unordered_map<int, bool> rows;           // To track occupied rows
        unordered_map<int, bool> upperDiagonals; // To track occupied upper diagonals (row - col)
        unordered_map<int, bool> lowerDiagonals; // To track occupied lower diagonals (row + col)
        
        solve(0, n, board, ans, rows, upperDiagonals, lowerDiagonals);
        
        return ans;
    }
};
