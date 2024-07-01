class Solution {
public:
    int result = INT_MIN;
    bool fun(vector<int>& home)
    {
        for(int i=0;i<home.size();i++)
            if(home[i] != 0)
                return false;
        return true;
    }
    void solve(vector<vector<int>>& requests, vector<int>&home, int ind, int count)
    {
        if(ind == requests.size())
        {
            if(fun(home))
                result = max(result, count);
            
            return;
        }
        int from = requests[ind][0];
        int to   = requests[ind][1];
        home[from]--;
        home[to]++;
        solve(requests,home, ind+1, count+1);
        home[from]++;
        home[to]--;
        solve(requests, home, ind+1, count);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) 
    {
        vector<int>home(n,0);
        solve(requests, home, 0,0);
        return result;
        
    }
};