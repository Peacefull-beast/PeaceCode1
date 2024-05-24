class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int dup = 0;
        int sum = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1])
                dup = nums[i];
            
            sum += nums[i];
        }
        
        int pred = (n * (n + 1)) / 2;
        int dif = pred - sum + dup; // Adjust the difference for the missing number
        
        return {dup, dif};
    } 
};
