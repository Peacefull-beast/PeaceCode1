#include <vector>
#include <algorithm>
using namespace std;

class neighborSum {
public:
    int n;
    int m;
    vector<vector<int>> grid;

    neighborSum(vector<vector<int>>& g) {
        n = g.size();
        m = g[0].size();
        grid = g;
    }

    int adjacentSum(int value) {
        int i = 0, j = 0;
        bool found = false;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (grid[i][j] == value) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (!found) return 0; // Value not found in the grid

        int sum = 0;
        if (i > 0) sum += grid[i - 1][j];
        if (i < n - 1) sum += grid[i + 1][j];
        if (j > 0) sum += grid[i][j - 1];
        if (j < m - 1) sum += grid[i][j + 1];

        return sum;
    }

    int diagonalSum(int value) {
        int i = 0, j = 0;
        bool found = false;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (grid[i][j] == value) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (!found) return 0; // Value not found in the grid

        int sum = 0;
        if (i > 0 && j > 0) sum += grid[i - 1][j - 1];
        if (i > 0 && j < m - 1) sum += grid[i - 1][j + 1];
        if (i < n - 1 && j > 0) sum += grid[i + 1][j - 1];
        if (i < n - 1 && j < m - 1) sum += grid[i + 1][j + 1];

        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
