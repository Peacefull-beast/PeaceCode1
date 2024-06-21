class Solution {
public:
    bool check(vector<int>& nums, int k, int cap) {
        int ans = 0;
        int stu = 1; // Starts with the first subarray
        for (auto n : nums) 
        {
            if (ans + n > cap) 
            {
                stu++;
                ans = n;
                if (stu > k) return false;
            } 
            else 
                ans += n;
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        while (low <= high) {
            int mid = (high + low) / 2; 
            bool tmp = check(nums, k, mid);
            if (tmp == false) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return low;
    }
};
