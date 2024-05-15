class Solution {
public:
    bool isValid(vector<vector<bool>>&vis, int i, int j)
    {
        if(i < 0 || j < 0 || i == vis.size() || j == vis.size() || vis[i][j])
            return false;
        return true;
    }
    
    
    bool isSafe(vector<vector<int>>& dist, int safedist)
    {
        int n = dist.size();
        queue<pair<int,int>> q;
        
        
        if(dist[0][0] < safedist)
            return false;
        
        vector<vector<bool>>vis(n, vector<bool>(n, false));
        q.push({0,0});
        vis[0][0] = true;
        
        
        vector<int> nr = {0, 1, 0 ,-1};
        vector<int> nc = {1, 0, -1, 0};
        
        while(!q.empty())
        {
            int currow = q.front().first;
            int curcol = q.front().second;
            q.pop(); 
            
            if(currow == n-1 && curcol == n-1)
                return true;
            
            for(int i = 0; i<4; i++)
            {
                int newrow = currow + nr[i];
                int newcol = curcol + nc[i];
                     
                if(isValid(vis, newrow, newcol)) 
                {
                    if(dist[newrow][newcol] < safedist)
                        continue;
                    vis[newrow][newcol] = true;
                    q.push({newrow,newcol});
                }

            }
            
        }
        return false;
        
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) 
    {
        
        int n = grid.size();
        queue<pair<int,int>> q;
        
        vector<vector<bool>>vis(n, vector<bool>(n, false));
        vector<vector<int >>dist(n, vector<int>(n, -1));
        
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    vis[i][j]=true;
                    q.push({i,j});
                }
                    
            }
        }
        
        vector<int> nr = {0, 1, 0 ,-1};
        vector<int> nc = {1, 0, -1, 0};

        int l = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                 int currow = q.front().first;
                 int curcol = q.front().second;
                 q.pop();
                dist[currow][curcol] = l;
                 for(int i = 0; i<4; i++)
                 {
                     int newrow = currow + nr[i];
                     int newcol = curcol + nc[i];
                     
                     if(!isValid(vis, newrow, newcol)) //non - valid condition
                         continue;
                     
                     vis[newrow][newcol] = true;
                     q.push({newrow,newcol});
                 }
            }
            l+=1;
        
        }
        
        int low = 0;
        int high = l;
        int ans = 0;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(isSafe(dist, mid))
            {
                ans = mid;
                low = mid+1;
            }
            else
                high = mid - 1;
        }
        
        return ans;
    }
};