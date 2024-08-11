class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) 
    {
        vector<vector<int>>dist(n, vector<int>(n, INT_MAX));
        
        
        for(int i = 0; i < n; i++) {
            dist[i][i] = 0; 
            if (i < n - 1) {
                dist[i][i + 1] = 1;  
                dist[i + 1][i] = 1; 
            }
        }
        if(x != y)
        {
            dist[x-1][y-1] = 1;
            dist[y-1][x-1] = 1;
        }
        
            
        
        
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        vector<int>ans(n,0);
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int d = dist[i][j];
                if(d!=0)
                    ans[--d]++;
            }
        }
        
        return ans;
    }
};