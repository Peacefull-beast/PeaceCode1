class Solution {
public:
    // Standard binary search function
    int bs(vector<int>& nums, int target, int low, int high)
    {
        while (low <= high) // Correct binary search loop condition
        {
            int mid = low + (high - low) / 2; // Correct calculation of mid
            
            if (nums[mid] == target)
                return mid;
            
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1; // Return -1 if target is not found
    }

    vector<int> searchRange(vector<int>& nums, int target) 
    {   
        int n = nums.size();
        if (n == 0) return {-1, -1}; // Handle empty input

        int firstPos = bs(nums, target, 0, n - 1);
        if (firstPos == -1) return {-1, -1}; // If the target is not found

        // Find the start position
        int start = firstPos;
        int temp = firstPos;
        while (temp != -1)
        {
            start = temp;
            temp = bs(nums, target, 0, start - 1);
        }

        // Find the end position
        int end = firstPos;
        temp = firstPos;
        while (temp != -1)
        {
            end = temp;
            temp = bs(nums, target, end + 1, n - 1);
        }

        return {start, end};
    }
};
