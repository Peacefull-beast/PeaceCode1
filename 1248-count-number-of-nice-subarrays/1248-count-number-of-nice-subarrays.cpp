class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt = 0;  
        int ans = 0;  
        unordered_map<int, int> countMap;  
        countMap[0] = 1;  

        for (int i = 0; i < nums.size(); ++i) {
            cnt += (nums[i] % 2);

            if (countMap.find(cnt - k) != countMap.end()) {
                ans += countMap[cnt - k];
            }

            countMap[cnt]++;
        }

        return ans;
    }
};
