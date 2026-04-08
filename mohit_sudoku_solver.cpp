#include <iostream>
#include <vector>
using namespace std;

// Checks if placing 'v' at board[r][c] is valid
bool ok(vector<vector<int>>& b, int r, int c, int v) {
    for(int i=0; i<9; i++) {
        // Check row, column, and the 3x3 subgrid simultaneously
        if(b[r][i] == v || b[i][c] == v || b[3*(r/3)+i/3][3*(c/3)+i%3] == v) return 0;
    }
    return 1;
}

bool solve(vector<vector<int>>& b) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(b[i][j] == 0) { // Find an empty cell
                for(int v=1; v<=9; v++) {
                    if(ok(b, i, j, v)) {
                        b[i][j] = v;           // 1. Try a value
                        if(solve(b)) return 1; // 2. Recurse deeper
                        b[i][j] = 0;           // 3. Backtrack if it fails
                    }
                }
                return 0; // Trigger backtracking if no 1-9 works here
            }
        }
    }
    return 1; // True when no empty cells are left (Puzzle solved)
}

int main() {
    // 0 represents empty cells
    vector<vector<int>> b = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if(solve(b)) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) cout << b[i][j] << " ";
            cout << "\n";
        }
    } else {
        cout << "No solution exists\n";
    }
}