#include <vector>
#include <algorithm>
#include <climits> 
using namespace std;

class Solution {
public:
     int bs(vector<vector<int>>& rides, int ind) {
        int low = ind + 1;
        int high = rides.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (rides[mid][0] >= rides[ind][1]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    long long solve(vector<vector<int>>& rides, int p, int ind, vector<long long>& dp) {
        if (ind >= rides.size())
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        long long pick = LLONG_MIN;
        long long npick = LLONG_MIN;

        long long tip = rides[ind][1] - rides[ind][0] + rides[ind][2];
        
    
        npick = solve(rides, p, ind + 1, dp);

        int nind = bs(rides, ind);
        pick = tip + solve(rides, rides[ind][1], nind, dp);

        return dp[ind] = max(pick, npick);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        
        vector<long long> dp(rides.size() + 1, -1);
        
        return solve(rides, 0, 0, dp);
    }
};
