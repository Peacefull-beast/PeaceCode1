// class Solution {
// public:
//     int n;
//     int solve(vector<int>& obstacles, int ind, int lane, vector<vector<int>>& dp) {
//         if (ind == obstacles.size() - 1) 
//             return 0;

//         if (obstacles[ind] == lane)
//             return dp[ind][lane] = n + 1;

        
//         int ans=INT_MAX;
        
//         if (dp[ind][lane] != -1) 
//             ans= dp[ind][lane];

//         if(obstacles[ind+1]!=lane)return solve(obstacles, ind + 1, 1, dp);
//         else{
//             for (int newLane = 1; newLane <= 3; ++newLane) {
//                 if (newLane != lane && obstacles[ind] != newLane) {
//                     ans = min(ans, 1 + solve(obstacles, ind, newLane, dp));
//                 }
//             }
//         }

//         return dp[ind][lane] = ans;
//     }

//     int minSideJumps(vector<int>& obstacles) {
//         n = obstacles.size();
//         vector<vector<int>> dp(n, vector<int>(4, -1)); 

       
//         return solve(obstacles, 0, 2, dp);
//     }
// };

class Solution {
public:
    int n;

    int solve(vector<int>& obstacles, int ind, int lane, vector<vector<int>>& dp) {
        // Base case: If we reach the last index, no more jumps are needed
        if (ind == obstacles.size() - 1) 
            return 0;

        // If the current lane at this index has an obstacle, return a large number to signify an invalid path
        if (obstacles[ind] == lane)
            return dp[ind][lane] = n + 1;

        // If already computed, return the stored result
        if (dp[ind][lane] != -1) 
            return dp[ind][lane];

        int ans = INT_MAX;

        // Option 1: Move forward in the same lane if the next position is not blocked
        if (obstacles[ind + 1] != lane) {
            ans = solve(obstacles, ind + 1, lane, dp);
        } else {
            // Option 2: Consider jumping to another lane
            for (int newLane = 1; newLane <= 3; ++newLane) {
                if (newLane != lane && obstacles[ind] != newLane) {
                    ans = min(ans, 1 + solve(obstacles, ind, newLane, dp));
                }
            }
        }

        // Save and return the result
        return dp[ind][lane] = ans;
    }

    int minSideJumps(vector<int>& obstacles) {
        n = obstacles.size();
        vector<vector<int>> dp(n, vector<int>(4, -1)); // Memoization table

        // Start from index 0, lane 2 (as per problem statement)
        return solve(obstacles, 0, 2, dp);
    }
};
