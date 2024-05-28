class Solution {
public:
    int solve(vector<vector<int>>& grid,vector<pair<int, int>> &srt, vector<pair<int, int>> &end, int ind)
    {
        if(ind == end.size())
            return 0;
        
        int n = srt.size();
        
        int currow = end[ind].first;
        int curcol = end[ind].second;
        int ans = INT_MAX;
        
        for(int i = 0; i<n; i++)
        {
            int srtrow = srt[i].first;
            int srtcol = srt[i].second;
            
            if(grid[srtrow][srtcol] > 1)
            {
                grid[srtrow][srtcol]--;
                grid[currow][curcol] = 1;
                ans = min(ans, abs(currow - srtrow) + abs(curcol - srtcol) + solve(grid, srt,end, ind+1));
                grid[srtrow][srtcol]++;
                grid[currow][curcol] = 0;
                
            }
            
        }
        return ans;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> srt;
        vector<pair<int, int>> end;
        

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == 0) {
                    end.push_back({i, j});
                } else if (grid[i][j] > 1) {
                    srt.push_back({i, j});
                }
            }
        }
        return solve(grid, srt, end, 0);

        
    }
};
