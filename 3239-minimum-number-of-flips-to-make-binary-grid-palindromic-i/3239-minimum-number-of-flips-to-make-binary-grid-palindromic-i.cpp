class Solution {
public:
    int minFlips(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        int rop = 0;
        
        for(int i=0; i<n; i++)
        {
            int c = 0;
            int p1 = 0;
            int p2 = m-1;
            
            while(p1 < p2)
            {
                if(grid[i][p1] != grid[i][p2])
                    c++;
                p1++;
                p2--;
            }
            
            rop += c;
        }
        
        int cop = 0;
        for(int j=0; j<m; j++)
        {
            int c = 0;
            int p1 = 0;
            int p2 = n-1;
            
            while(p1 < p2)
            {
                if(grid[p2][j] != grid[p1][j])
                    c++;
                p1++;
                p2--;
            }
            cop+=c;
        }
        
        return min(rop, cop);
    }
};