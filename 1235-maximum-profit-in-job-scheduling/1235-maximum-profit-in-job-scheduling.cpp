
class Solution {
public:

    
    int answ(vector<vector<int>>& jobs, vector<int>& srt, int n, int ind, vector<int> &dp)
    {
        if( ind == n)
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        int next = lower_bound(srt.begin(), srt.end(), jobs[ind][1]) - srt.begin();
        
        int mpro = max(answ(jobs, srt, n, ind+1, dp),  jobs[ind][2] + answ(jobs, srt, n, next, dp));
        
        return dp[ind] = mpro;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }

        // Sort jobs by start time
        sort(jobs.begin(), jobs.end());


        for(int i = 0; i<n; i++)
            startTime[i] = jobs[i][0];
        vector<int> dp(n, -1);
        return answ(jobs, startTime, profit.size(), 0, dp);
    }
};
