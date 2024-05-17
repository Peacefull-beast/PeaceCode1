
class Solution {
public:
    int answer(vector<vector<int>>& job, int ind, int prev_end, vector<vector<int>>& dp) {
        if (ind >= job.size()) {
            return 0;
        }

        if (dp[ind][prev_end + 1] != -1) {
            return dp[ind][prev_end + 1];
        }

        int inc = INT_MIN;
        if (prev_end == -1 || job[ind][0] >= job[prev_end][1]) {
            inc = job[ind][2] + answer(job, ind + 1, ind, dp);
        }

        int exc = answer(job, ind + 1, prev_end, dp);
        return dp[ind][prev_end + 1] = max(inc, exc);
    }
    
    
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

        // Initialize dp array with -1
        //vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        for(int i = 0; i<n; i++)
            startTime[i] = jobs[i][0];
        vector<int> dp(n, -1);
        return answ(jobs, startTime, profit.size(), 0, dp);
    }
};
