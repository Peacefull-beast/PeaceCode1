class Solution {
public:
    bool check2(vector<vector<int>>& grid, int i, int j)
    {
        vector<int> temp(10, 0);  // Array to keep track of numbers 1-9
        for(int r = i; r < i + 3; r++)
        {
            for(int c = j; c < j + 3; c++)
            {
                int num = grid[r][c];
                if(num < 1 || num > 9)  // Numbers should be between 1 and 9
                    return false;
                if(temp[num] == 1)  // If the number is already seen, return false
                    return false;
                temp[num] = 1;
            }
        }
        return true;
    }
    
    bool check1(vector<vector<int>>& grid, int i, int j)
    {
        int s1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
        int s2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
        int s3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
        
        bool cond1 = (s1 == s2 && s2 == s3);
        if(!cond1)
            return false;
        
        int s4 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
        int s5 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
        int s6 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
        
        bool cond2 = (s4 == s5 && s5 == s6);
        if(!cond2)
            return false;
        
        int s7 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
        int s8 = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];
        
        bool cond3 = (s7 == s8);
        if(!cond3)
            return false;
        
        bool cond4 = (s1 == s4 && s4 == s7);
        if(!cond4)
            return false;
        
        return true;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        if(n < 3 || m < 3)
            return 0;
        
        int ans = 0;
        for(int i = 0; i < n - 2; i++)
        {
            for(int j = 0; j < m - 2; j++)
            {
                if(check1(grid, i, j) && check2(grid, i, j))
                    ans++;
            }
        }
        
        return ans;
    }
};
