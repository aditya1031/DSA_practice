#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 5;
const int COLS = 5;


int rowDirection[] = {-1, 1, 0, 0};
int colDirection[] = {0, 0, -1, 1};

bool isValidMove(int row, int col, vector<vector<char>>& maze, vector<vector<bool>>& visited) {
    return (row >= 0) && (row < ROWS) && (col >= 0) && (col < COLS) &&
           (maze[row][col] == '0' || maze[row][col] == 'G') && !visited[row][col];
}

bool dfs(int row, int col, vector<vector<char>>& maze, vector<vector<bool>>& visited) {
    if (maze[row][col] == 'G') return true;  
    
    visited[row][col] = true; 

    for (int i = 0; i < 4; i++) {
        int newRow = row + rowDirection[i];
        int newCol = col + colDirection[i];

        if (isValidMove(newRow, newCol, maze, visited)) {
            if (dfs(newRow, newCol, maze, visited)) return true;
        }
    }

    return false;
}

int main() {
    vector<vector<char>> maze = {
        {'S', '0', '0', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '1', '1', '1', '1'},
        {'0', '0', '0', '0', 'G'}
    };

    vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

    int startRow = 0, startCol = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 'S') {
                startRow = i;
                startCol = j;
                break;
            }
        }
    }

    if (dfs(startRow, startCol, maze, visited)) {
        cout << "Path found from Source to Goal." << endl;
    } else {
        cout << "No path found from Source to Goal." << endl;
    }

    return 0;
}
