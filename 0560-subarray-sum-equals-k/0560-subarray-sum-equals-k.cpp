class Solution {
public:

    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> pref; 
        pref[0] = 1; 

        int cumSum = 0;
        int ans = 0;

        for (int num : nums) {
            cumSum += num;

            if (pref.find(cumSum - k) != pref.end()) {
                ans += pref[cumSum - k];
            }

            pref[cumSum]++;
        }

        return ans;
    }
};