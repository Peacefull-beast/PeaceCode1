class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) 
    {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>obs(n, vector<int>(m, INT_MAX));
        obs[0][0] = 0; 
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>pq;

        pq.push({0,{0,0}});

        vector<int> nc = {-1, 0, 1, 0};
        vector<int> nr = {0, -1, 0, 1};

        while(!pq.empty())
        {
            int num = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();


            if(row == n-1 && col == m-1)
            return num;

            for(int i=0; i<4; i++)
            {
                int nrow = row + nr[i];
                int ncol = col + nc[i];
                bool valid = (nrow >= 0) && (nrow < n) && (ncol >= 0) && (ncol < m);
                if(valid)
                {
                    if(num + grid[nrow][ncol] < obs[nrow][ncol])
                    {
                        obs[nrow][ncol] = num + grid[nrow][ncol];
                        pq.push({num + grid[nrow][ncol], {nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};