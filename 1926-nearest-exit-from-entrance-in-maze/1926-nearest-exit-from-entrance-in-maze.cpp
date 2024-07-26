class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        queue<pair<pair<int, int>, int>> q; // row, col, dist
        q.push({{e[0], e[1]}, 0});

        int n = maze.size();
        int m = maze[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[e[0]][e[1]] = 1;

        vector<int> r = {-1, 0, 1, 0};
        vector<int> c = {0, -1, 0, 1};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            
            if ((row == 0 || col == 0 || row == n - 1 || col == m - 1) && dist != 0) {
                return dist;
            }

            for (int i = 0; i < 4; i++) {
                int nrow = row + r[i];
                int ncol = col + c[i];
                bool isValid = (nrow >= 0) && (ncol >= 0) && (nrow < n) && (ncol < m);
                if (isValid && vis[nrow][ncol] == 0 && maze[nrow][ncol] == '.') {
                    vis[nrow][ncol] = 1; 
                    q.push({{nrow, ncol}, dist + 1});
                }
            }
        }
        return -1; 
    }
};
