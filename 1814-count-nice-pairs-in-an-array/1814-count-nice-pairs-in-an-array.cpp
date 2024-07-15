class Solution {
public:
    int mod = 1e9+7;
    int rev(int n)
    {
        int ans = 0;
        while(n != 0)
        {
            int d = n % 10;
            ans = (ans * 10) + d;
            n /= 10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) 
    {
        unordered_map<int, int>mp;
        int ans = 0;
        for(auto n : nums)
        {
            int r = rev(n);
            cout<<r <<" ";
            int d = n - r;
            mp[d] += 1;
            ans = (ans + (mp[d]-1))%mod;
            
        }
        return ans;
    }
};