class Solution {
public:
    int ans = INT_MAX;
    void solve(vector<int>& cookies, vector<int>& sum, int ind)
    {
        if(ind == cookies.size())
        {
            int temp = *max_element(sum.begin(), sum.end());
            ans = min(ans, temp);
            return;
        }
        for(int i=0; i<sum.size(); i++)
        {
            sum[i] += cookies[ind];
            solve(cookies, sum, ind+1);
            sum[i] -= cookies[ind];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) 
    {
        vector<int>sum(k,0);
        solve(cookies, sum, 0);
        return ans;
    }
};