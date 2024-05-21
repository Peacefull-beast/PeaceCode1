class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> subsets;

        for (int bitmask = 0; bitmask < (1 << n); ++bitmask) 
        {
            vector<int> subset;
            for (int j = 0; j < n; ++j) 
            {
                if (bitmask & (1 << j)) 
                    subset.push_back(nums[j]);
            }
            subsets.push_back(subset);
        }
        return subsets;
    }
};