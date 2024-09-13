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

bool isSafe(int col, int row, int n, vector<vector<string>>& board) {
    int x = row;
    int y = col;
    
    // Check for left row (no need to check for column)
    while (y >= 0) {
        if (board[x][y] == "Q") {
            return false;
        }
        y--;
    }
    
    x = row;
    y = col;
    
    // Check for secondary left diagonal
    while (x >= 0 && y >= 0) {
        if (board[x][y] == "Q") {
            return false;
        }
        y--;
        x--;
    }
    
    x = row;
    y = col;
    
    // Check for primary left diagonal
    while (x < n && y >= 0) {
        if (board[x][y] == "Q") {
            return false;
        }
        y--;
        x++;
    }
    
    return true;
}   
    
void solve(vector<vector<string>>& board, vector<vector<string>>& ans, int col, int n) {
    if (col == n) {
        Add2D(board, ans, n);
        return;
    }
    
    for (int row = 0; row < n; row++) {
        if (isSafe(col, row, n, board)) {
            board[row][col] = "Q";
            solve(board, ans, col + 1, n);
            board[row][col] = ".";
        }
    }
}
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n, vector<string>(n, "."));
        vector<vector<string>> ans;
        int col = 0;
        
        solve(board, ans, col, n);
        
        return ans;
    }
};
