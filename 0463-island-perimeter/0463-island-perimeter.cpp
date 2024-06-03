class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>>q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)
                    q.push({i,j}); 
            }
        }
        int ans = 0;
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            if(row-1 < 0 || grid[row-1][col] == 0)
                ans += 1;
            if(row+1 >= n || grid[row+1][col] == 0)
                ans += 1;
            if(col-1 < 0 || grid[row][col-1] == 0)
                ans += 1;
            if(col+1 >= m || grid[row][col+1] == 0)
               ans+=1;
        }
        return ans;
               
        
        
    }
};