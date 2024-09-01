class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        queue<pair<int,pair<int,int>>>q;//step, row,col;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dist(n, vector<int>(m,INT_MAX));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            if(grid[i][j] == 1)
            {
                q.push({0, {i,j}});
                dist[i][j] = 0;
            }
        }

        vector<int>nr = {-1, 0, 1, 0};
        vector<int>nc = {0, -1, 0 ,1};

        while(!q.empty())
        {
            int sz = q.size(); 
            while(sz--)
            {
                int step = q.front().first;
                int row = q.front().second.first;
                int col = q.front().second.second;


                q.pop();


                for(int i=0; i<4; i++)
                {
                    int nrow = row + nr[i];
                    int ncol = col + nc[i];

                    bool cond = (nrow >= 0) && (ncol >= 0) && (nrow < n) && (ncol < m);

                    if(cond)
                    {
                        if(dist[nrow][ncol] > step+1)
                        {
                            dist[nrow][ncol] = step+1;
                            q.push({step+1, {nrow,ncol}});
                        }
                    }
                }
            }
            



        }

        int ans = INT_MIN;
        for(int i=0;i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ans = max(ans, dist[i][j]);
            }
        }

        return (ans == INT_MAX) || (ans == 0) ? -1 : ans;
        
    }
};