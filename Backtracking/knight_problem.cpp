#include <iostream>
#include <vector>
using namespace std;

bool knightTourHelper(int currentRow, int currentCol, int moveCount, int totalMoves, vector<vector<int>>& grid) {
    if (moveCount == totalMoves) {
        return true;
    }

    int n = grid.size();
    int rowMoves[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int colMoves[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int i = 0; i < 8; i++) {
        int newRow = currentRow + rowMoves[i];
        int newCol = currentCol + colMoves[i];
        
        if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < n && grid[newRow][newCol] == moveCount) {
            moveCount++;
            if (knightTourHelper(newRow, newCol, moveCount, totalMoves, grid)) {
                return true;
            }
        }
    }
    return false;
}

bool checkKnightTourValidity(vector<vector<int>>& grid) {
    if (grid[0][0] != 0) return false;
    int n = grid.size();
    int totalMoves = n * n;
    return knightTourHelper(0, 0, 1, totalMoves, grid);
}

int main() {
    vector<vector<int>> grid = {
        {0, 3, 10, 1},
        {7, 8, 15, 4},
        {6, 9, 14, 13},
        {5, 12, 11, 2}
    };
    
    if (checkKnightTourValidity(grid)) {
        cout << "The knight's tour is valid." << endl;
    } else {
        cout << "The knight's tour is not valid." << endl;
    }

    return 0;
}
