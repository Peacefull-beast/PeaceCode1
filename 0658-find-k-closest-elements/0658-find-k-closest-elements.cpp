class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                return mid; 
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return low;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = searchInsert(arr, x);

        int left = idx - 1;
        int right = idx;

        vector<int> result;

        while (k > 0) 
        {
            if (left < 0) 
            {
                result.push_back(arr[right]);
                right++;
            } 
            else if (right >= arr.size()) 
            {
                result.push_back(arr[left]);
                left--;
            } 
            else 
            {
                if (abs(arr[left] - x) <= abs(arr[right] - x)) 
                {
                    result.push_back(arr[left]);
                    left--;
                } 
                else 
                {
                    result.push_back(arr[right]);
                    right++;
                }
            }
            k--;
        }

        sort(result.begin(), result.end());
        return result;
    }
};
