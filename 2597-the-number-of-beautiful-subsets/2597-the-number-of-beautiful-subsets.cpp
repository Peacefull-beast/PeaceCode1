class Solution {
public:
    int solve(vector<int>& nums, int k, int ind, unordered_map<int,int> &mp) {
        if (ind == nums.size())
            return 1; 

        int pick = 0;
        if (!mp[nums[ind] - k] && !mp[nums[ind]+k]) 
        {
            mp[nums[ind]]++;
            pick = solve(nums, k, ind + 1,mp);
            mp[nums[ind]]--;
        }

        int npick = solve(nums, k, ind + 1, mp);

        return pick + npick;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int totalSubsets = solve(nums, k, 0, mp);
        return totalSubsets - 1; // Subtract 1 to exclude the empty subset.
    }
};
