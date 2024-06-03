class Solution {
public:
    void dfs(vector<vector<int>>&gr, vector<bool>&vis, int &c, int &i)
    {
        vis[i] = true;
        c++;
        for(int j = 0; j<gr[i].size(); j++)
        {
            if(vis[gr[i][j]] != true)
                dfs(gr,vis,c, gr[i][j]);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        int n = bombs.size();
        vector<vector<int>>gr(n);
        
        
        for(int i = 0; i<n; i++ )
        {
            long long x = bombs[i][0];
            long long y = bombs[i][1];
            long long r = bombs[i][2];
            
            for(int j = 0; j<n; j++)
            {
                if(i != j)
                {
                    long long nx = abs(x - bombs[j][0]);
                    long long ny = abs(y - bombs[j][1]);
                    
                    if(nx*nx + ny*ny <= r*r)
                        gr[i].push_back(j);
                }
            }     
        }
        int ans = INT_MIN;
        for(int i = 0; i<n; i++ )
        {
            int c = 0;
            vector<bool>vis(n, false);
            dfs(gr,vis,c,i);
            ans = max(ans,c);
        }
        
        return ans;
    }
};