#include <iostream>
#include <cstring>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

// Function to perform backtracking to search the word in the grid
bool backtrack(char board[ROWS][COLS], string word, int row, int col, int index) {
    // If all characters of the word have been matched
    if (index == word.length()) {
        return true;
    }

    // If out of bounds or the character doesn't match
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col] != word[index]) {
        return false;
    }

    // Mark the current cell as visited by temporarily changing the character
    char temp = board[row][col];
    board[row][col] = '#'; // Use a special marker to denote the cell as visited

    // Explore in all 8 possible directions
    if (backtrack(board, word, row - 1, col, index + 1)) return true;  // Up
    if (backtrack(board, word, row + 1, col, index + 1)) return true;  // Down
    if (backtrack(board, word, row, col - 1, index + 1)) return true;  // Left
    if (backtrack(board, word, row, col + 1, index + 1)) return true;  // Right
    if (backtrack(board, word, row - 1, col - 1, index + 1)) return true;  // Up-Left Diagonal
    if (backtrack(board, word, row - 1, col + 1, index + 1)) return true;  // Up-Right Diagonal
    if (backtrack(board, word, row + 1, col - 1, index + 1)) return true;  // Down-Left Diagonal
    if (backtrack(board, word, row + 1, col + 1, index + 1)) return true;  // Down-Right Diagonal

    // Backtrack: undo the marking of the cell
    board[row][col] = temp;
    return false;
}

// Main function to search how many times the word appears in the board
int exist(char board[ROWS][COLS], string word) {
    int count = 0;
    // Start searching from every cell in the grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // For each cell, if a valid match is found, increment the counter
            if (backtrack(board, word, i, j, 0)) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    // Example word search grid
    char board[ROWS][COLS] = {
        {'G', 'R', 'O', 'O', 'T'},
        {'B', 'A', 'R', 'R', 'O'},
        {'W', 'R', 'D', 'B', 'S'},
        {'R', 'A', 'D', 'A', 'R'},
        {'W', 'E', 'S', 'T', 'G'}
    };

    string word;
    cout << "Enter the word to search: ";
    cin >> word;

    // Check how many times the word exists in the board
    int occurrences = exist(board, word);
    if (occurrences > 0) {
        cout << "The word '" << word << "' was found " << occurrences << " times in the grid!" << endl;
    } else {
        cout << "The word '" << word << "' was not found in the grid." << endl;
    }

    return 0;
}
