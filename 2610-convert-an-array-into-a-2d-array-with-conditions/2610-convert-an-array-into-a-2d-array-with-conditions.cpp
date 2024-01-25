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
        vector<vector<int>>ans;
        int row = 0;
        for(int i=0;i<cnt;i++)
        {
            vector<int>temp;
            ans.push_back(temp);
        }
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