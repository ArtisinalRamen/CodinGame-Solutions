#include <iostream>
// https://www.codingame.com/training/easy/island-escape

int GetIndex(int x, int y, int size) {
    return (y * size) + x;
}

int GetDiff(int x, int y) {
    return std::abs(x - y);
}

bool FloodFill(int* grid, int* visited, int size, int x, int y) {
    int currIndex = GetIndex(x, y, size);
    int currElevation = grid[currIndex];
    visited[currIndex] = 1;
    
    if (currElevation == 0) {
        return true;
    }
    // Left
    if ((visited[GetIndex(x - 1, y, size)] == 0 
    && (GetDiff(currElevation, grid[GetIndex(x - 1, y, size)]) <= 1))) {
        if (FloodFill(grid, visited, size, x - 1, y)) {
            return true;
        }
    }
    // Right
    if ((visited[GetIndex(x + 1, y, size)] == 0 
    && (GetDiff(currElevation, grid[GetIndex(x + 1, y, size)]) <= 1))) {
        if (FloodFill(grid, visited, size, x + 1, y)) {
            return true;
        }
    }
    // Up
    if ((visited[GetIndex(x, y - 1, size)] == 0 
    && (GetDiff(currElevation, grid[GetIndex(x, y - 1, size)]) <= 1))) {
        if (FloodFill(grid, visited, size, x, y - 1)) {
            return true;
        }
    }
    // Down
    if ((visited[GetIndex(x, y + 1, size)] == 0 
    && (GetDiff(currElevation, grid[GetIndex(x, y + 1, size)]) <= 1))) {
        if (FloodFill(grid, visited, size, x, y + 1)) {
            return true;
        }
    }
    return false;
}

int main() {
    int size;
    std::cin >> size; std::cin.ignore();
    int grid[size * size];
    int visited[size * size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int elevation;
            std::cin >> elevation; std::cin.ignore();
            grid[GetIndex(j, i, size)] = elevation;
            visited[GetIndex(j, i, size)] = 0;
        }
    }
    int startX = (size - 1) / 2;
    int startY = (size - 1) / 2;
    std::string out;
    if (FloodFill(grid, visited, size, startX, startY)) {
        out = "yes";
    }
    else {
        out = "no";
    }
    std::cout << out << std::endl;
}