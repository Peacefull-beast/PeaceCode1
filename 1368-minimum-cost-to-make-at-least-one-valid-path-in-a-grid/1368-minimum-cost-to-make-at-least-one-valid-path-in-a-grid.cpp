class Solution {
public:
    #define P pair<int, pair<int,int>>
    int minCost(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        priority_queue<P, vector<P>, greater<P>>pq;
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        
        
        pq.push({0,{0,0}});
        
        
        
        while(!pq.empty())
        {
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            
            pq.pop();
            
            if(x == n-1 && y == m-1)
                return d;
            
            
            int original = grid[x][y];
            
            for(int i = 1;i<=4;++i)
            {                
                if(x + dx[i-1] < n && y+dy[i-1] < m && x+dx[i-1] >= 0 && y+dy[i-1] >=0  )
                {
                    if(!(original == i) + d < dist[x + dx[i-1]][y+dy[i-1]])
                    {
                    
                        dist[x + dx[i-1]][y+dy[i-1]] = !(original == i) + d;
                        pq.push({!(original == i) + d,{x + dx[i-1],y+dy[i-1]}});
                    }
                }
            }
            
            
        }
        
        return 0;
        
        
    }
};