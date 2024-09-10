class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) 
    {
        unordered_map<int, vector<int>>mp; //num, array in which it is present
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            for(auto n:nums[i])
            {
                if(mp.find(n) == mp.end())
                mp[n].push_back(i);

                else
                {
                    if(mp[n].back() != i)
                    mp[n].push_back(i);
                }

            }
        }
        vector<int>ans;
        for(auto p : mp)
        {
            if(p.second.size() == n)
            ans.push_back(p.first);
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};