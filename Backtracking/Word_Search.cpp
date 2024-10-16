#include <iostream>
using namespace std;

bool Check(string maze[4][4], int srcx, int srcy, string curr, int index, int destination) {
    if (srcx >= 0 && srcy >= 0 && srcx <= destination && srcy <= destination && index < curr.length()) {
        char val = maze[srcx][srcy][0]; 
        return val == curr[index];
    }
    return false;
}

bool solve(string maze[4][4], int srcx, int srcy, string curr, int index, int destination) {
    if (index == curr.length()) {
        return true;
    }

    if (!Check(maze, srcx, srcy, curr, index, destination)) {
        return false;
    }

    index++;

    if (solve(maze, srcx + 1, srcy, curr, index, destination)) return true;
    if (solve(maze, srcx, srcy + 1, curr, index, destination)) return true;
    if (solve(maze, srcx - 1, srcy, curr, index, destination)) return true;
    if (solve(maze, srcx, srcy - 1, curr, index, destination)) return true;
    return false;
}

bool CheckDiagonal(string maze[4][4],int r, int c, string curr){
    int index = 0;
    bool f = false;

    for(int i=r; i<4; i++){
        for(int j=c; j<4; j++)
        if( i==j){
           char val = maze[i][j][0];
           if(val != curr[index]){
             f = true;
             return false;
           }
           index++;
        }
    }
    if( !f )
    return true;
     
     f = false;
     index = 0;
    
    for(int i=r; i<4; i++){
        for(int j=c; j<4; j++)
        if( i==j+1){
           char val = maze[i][j][0];
           if(val != curr[index]){
            f = true;
             return false;
           }
           index++;
        }
    }  
    if( !f )
    return true;  
    
}

void findStringInMaze(string maze[4][4], string curr, int destination) {
    bool found = false;
    
    for (int i = 0; i <= destination; i++) {
        for (int j = 0; j <= destination; j++) {
            if (solve(maze, i, j, curr, 0, destination)) {
                cout << "Found: " << curr << " starting at (" << i << ", " << j << ")" << endl;
                found = true;
                return;
            }
            if (CheckDiagonal(maze,i,j,curr)) {
                cout << "Found: " << curr << " starting at (" << i << ", " << j << ")" << endl;
                found = true;
                return;
            }
        }
    }

    if (!found) {
        cout << "Not Found: " << curr << endl;
    }
}

int main() {
    string maze[4][4] = {
        {"A", "B", "C", "D"},
        {"K", "Y", "F", "E"},
        {"L", "O", "T", "O"},
        {"M", "N", "E", "G"}
    };
    
    string curr = "YTG";
    int destination = 3;

    findStringInMaze(maze, curr, destination);

    return 0;
}
