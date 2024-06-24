class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int i = 0;
        int j = 0;
        int ans = 0;
        int temp = 0;
        
        while (j < nums.size()) {
            mp[nums[j]]++;
            temp += nums[j];
            
            while (mp[nums[j]] > 1) {
                temp -= nums[i];
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            
            ans = max(ans, temp);
            j++;
        }
        
        return ans;
    }
};
