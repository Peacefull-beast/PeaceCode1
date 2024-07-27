class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 1)
            return nums[0];
        int cp = 0; // count of positive numbers
        int cn = 0; // count of negative numbers
        for (auto n : nums) {
            if (n > 0) cp++;
            if (n < 0) cn++;
        }
        
        // Special case: If there's only one negative number and no positives, return 0
        if (cn == 1 && cp == 0)
            return 0;
        
        if(cp == 0 && cn == 0)
            return 0;
        
        // If there's an odd number of negatives, ignore the one with the smallest magnitude
        if (cn % 2 != 0) cn--;
        
        long long pro = 1;
        // Multiply all valid negative numbers
        for (int i = 0; i < cn; i++) {
            pro *= nums[i];
        }
        
        // Multiply all positive numbers
        for (int i = cn; i < nums.size(); i++) {
            if (nums[i] > 0) {
                pro *= nums[i];
            }
        }
        
        return pro;
    }
};
