class Solution {
public:
    #define pii pair<int, pair<int,int>>

    bool findSafeWalk(vector<vector<int>>& grid, int health) 
    {
        vector<int> nr = {0, -1, 0, +1}; 
        vector<int> nc = {-1, 0, +1, 0};

        int rows = grid.size();
        int cols = grid[0].size();
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        
        vector<vector<int>> visited(rows, vector<int>(cols, -1));
        
        
        pq.push({health - grid[0][0], {0, 0}});
        visited[0][0] = health - grid[0][0];

        
        while (!pq.empty()) {
            int h = pq.top().first;   
            int x = pq.top().second.first;  
            int y = pq.top().second.second; 
            pq.pop();

            
            if (x == rows - 1 && y == cols - 1 && h >= 1)
                return true;

            
            if (h <= 0)
                continue;

            
            for (int i = 0; i < 4; i++) 
            {
                int nrow = x + nr[i];
                int ncol = y + nc[i];

                bool cond = nrow >= 0 && ncol >= 0 && nrow < rows && ncol < cols;
                if (cond) {
                    int nh = h - grid[nrow][ncol];

                    
                    if (nh > visited[nrow][ncol]) 
                    {
                        visited[nrow][ncol] = nh;
                        pq.push({nh, {nrow, ncol}});
                    }
                }
            }
        }
        return false;
    }
};
