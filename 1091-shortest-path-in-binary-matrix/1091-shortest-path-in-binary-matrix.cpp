class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return -1;
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        vector<vector<int>> directions = {{1, 0}, {1, 1}, {1, -1}, {0, 1}, {0, -1}, {-1, 0}, {-1, 1}, {-1, -1}};
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        distance[0][0] = 1;
        
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            int row = temp.first;
            int col = temp.second;
            for (auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0) {
                    if (distance[newRow][newCol] > distance[row][col] + 1) {
                        distance[newRow][newCol] = distance[row][col] + 1;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
        
        return distance[n-1][n-1] == INT_MAX ? -1 : distance[n-1][n-1];
    }
};
