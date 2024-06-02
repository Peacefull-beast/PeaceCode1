class Solution {
public:
    int minimumDeletions(vector<int>& nums) 
    {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int max_i = 0;
        int min_i = 0;
        
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] > maxi)
            {
                maxi = nums[i];
                max_i = i;
            }
            if(nums[i] < mini)
            {
                mini = nums[i];
                min_i = i;
            }
        }
        
        int n = nums.size();
        
        cout << n <<"  " << min_i <<"  "<< max_i;
        int p1 = max(min_i, max_i) + 1; // Removing from the beginning to the farthest of min or max
        int p2 = n - min(min_i, max_i); // Removing from the end to the farthest of min or max
        int p3 = min(min_i, max_i) + 1 + n - max(min_i, max_i); // Removing min from one end and max from the other end
        

        return min(p1, min(p2, p3));

    }
};