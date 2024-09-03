class Solution {
public:
    int n;
    int solve(vector<int>& obstacles, int ind, int lane, vector<vector<int>>& dp) {
        if (ind == obstacles.size() - 1) 
            return 0;

        if (obstacles[ind] == lane)
            return dp[ind][lane] = n + 1;

        

        
        if (dp[ind][lane] != -1) 
            return dp[ind][lane];

        if(obstacles[ind+1]==0)return solve(obstacles, ind + 1, 1, dp);

        int o1 = (obstacles[ind + 1] != 1) ? ((lane == 1 ? 0 : 1) + solve(obstacles, ind + 1, 1, dp)) : n + 1;
        int o2 = (obstacles[ind + 1] != 2) ? ((lane == 2 ? 0 : 1) + solve(obstacles, ind + 1, 2, dp)) : n + 1;
        int o3 = (obstacles[ind + 1] != 3) ? ((lane == 3 ? 0 : 1) + solve(obstacles, ind + 1, 3, dp)) : n + 1;


        return dp[ind][lane] = min({o1, o2, o3});
    }

    int minSideJumps(vector<int>& obstacles) {
        n = obstacles.size();
        vector<vector<int>> dp(n, vector<int>(4, -1)); 

       
        return solve(obstacles, 0, 2, dp);
    }
};
