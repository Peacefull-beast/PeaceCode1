class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        int l = 0;
        int ans = 0;
        
        for(int i=1; i<nums.size();i++)
        {
            if(nums[l]-nums[i] > k)
            {
                ans++;
                l=i;
            }
        }
        
        return ans+1;
    }
};