class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int>mp;
        int cnt = 0;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            cnt = max(cnt, mp[nums[i]]);
        }
        vector<vector<int>>ans(cnt);
        int row = 0;
        int ind = 0;
        int col = 0;
        for(auto it:mp)
        {
            col = 0;
            while(it.second != 0)
            {
                ans[col].push_back(it.first);
                it.second--;
                col++;
            }
        
        }
        return ans;
    }
};